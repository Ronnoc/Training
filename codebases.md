#矩阵(线性代数)#
**1 有向图，从A点恰好走k步（允许重复经过边）到达B点的方案数mod p的值**

	把给定的图转为邻接矩阵，即A(i,j)=1当且仅当存在一条边i->j。令C=A*A，那么C(i,j)=ΣA(i,k)*A(k,j)，实际上就等于从点i到点j恰好经过2条边的路径数（枚举k为中转点）。类似地，C*A的第i行第j列就表示从i到j经过3条边的路径数。同理，如果要求经过k步的路径数，我们只需要二分求出A^k即可。
>可以根据 AC自动机 or trie树 建立图的转移关系,同上乱搞即可

**2 逆矩阵**
>验题: 未验

	#define MAXN 100
	#define fabs(x) ((x)>0?(x):-(x))
	#define zero(x) (fabs(x)<1e-10)
	struct mat {
		int n, m;
		double data[MAXN][MAXN];
	};
	int inv (mat& a) {
		int i, j, k, is[MAXN], js[MAXN];
		double t;
		if (a.n != a.m)
			return 0;
		for (k = 0; k < a.n; k++) {
			for (t = 0, i = k; i < a.n; i++)
				for (j = k; j < a.n; j++)
					if (fabs (a.data[i][j]) > t)
						t = fabs (a.data[is[k] = i][js[k] = j]);
			if (zero (t))
				return 0;
			if (is[k] != k)
				for (j = 0; j < a.n; j++)
					swap (a.data[k][j], a.data[is[k]][j]);
			if (js[k] != k)
				for (i = 0; i < a.n; i++)
					swap (a.data[i][k], a.data[i][js[k]]);
			a.data[k][k] = 1 / a.data[k][k];
			for (j = 0; j < a.n; j++)
				if (j != k)
					a.data[k][j] *= a.data[k][k];
			for (i = 0; i < a.n; i++)
				if (i != k)
					for (j = 0; j < a.n; j++)
						if (j != k)
							a.data[i][j] -= a.data[i][k] * a.data[k][j];
			for (i = 0; i < a.n; i++)
				if (i != k)
					a.data[i][k] *= -a.data[k][k];
		}
		for (k = a.n - 1; k >= 0; k--) {
			for (j = 0; j < a.n; j++)
				if (js[k] != k)
					swap (a.data[k][j], a.data[js[k]][j]);
			for (i = 0; i < a.n; i++)
				if (is[k] != k)
					swap (a.data[i][k], a.data[i][is[k]]);
		}
		return 1;
	}

**3 行列式求值**
>验题: 未验

	#define MAXN 100
	#define fabs(x) ((x)>0?(x):-(x))
	#define zero(x) (fabs(x)<1e-10)
	struct mat {
		int n, m;
		double data[MAXN][MAXN];
	};
	double det (const mat& a) {
		int i, j, k, sign = 0;
		double b[MAXN][MAXN], ret = 1, t;
		if (a.n != a.m)
			return 0;
		for (i = 0; i < a.n; i++)
			for (j = 0; j < a.m; j++)
				b[i][j] = a.data[i][j];
		for (i = 0; i < a.n; i++) {
			if (zero (b[i][i])) {
				for (j = i + 1; j < a.n; j++)
					if (!zero (b[j][i]))
						break;
				if (j == a.n)
					return 0;
				for (k = i; k < a.n; k++)
					t = b[i][k], b[i][k] = b[j][k], b[j][k] = t;
				sign++;
			}
			ret *= b[i][i];
			for (k = i + 1; k < a.n; k++)
				b[i][k] /= b[i][i];
			for (j = i + 1; j < a.n; j++)
				for (k = i + 1; k < a.n; k++)
					b[j][k] -= b[j][i] * b[i][k];
		}
		if (sign & 1)
			ret = -ret;
		return ret;
	}

#数论#
**1 扩展欧几里得**
>ax+by==gcd(a,b)的解
>验题: poj 1061

	typedef long long lint;		//easy to change
	lint extGcd (lint a, lint b, lint &x, lint &y) {
		lint ret = a;
		if (b) {
			ret = extGcd (b, a % b, y, x);
			y -= (a / b) * x;
		} else
			x = 1, y = 0;
		return ret;
	}

**2 逆元**
>验题:未验

	//用于m不是质数 gcd(a,m)==1时有逆元
	lint modInv (lint a, lint m) {
		lint x, y;
		extGcd(a,m,x,y);
		return (m+x%m)%m;
	}
	//if m为质数 [费马小定理]a^(m-1)=1 mod m ==>a^(m-2)是a关于m的逆元

**3 快速幂取模&&快速乘取模**
>验题: poj 1811

	//a*b mod m
	lint llpro (lint a, lint b, lint m) {
		lint ret = 0LL;
		if (b > a) swap (a, b);
		while (b) {
			if (b & 1) ret = (a + ret) % m;
			a = (a + a) % m;
			b /= 2;
		}
		return ret;
	}
	//a^x mod m
	lint power (lint a, lint x, lint m) {
		lint ret = 1LL;
		while (x) {
			if (x & 1) ret = llpro (a, ret, m);
			a = llpro (a, a, m);
			x /= 2;
		}
		return ret;
	}

**4 素数筛**
>验题: poj 1811

	bool isp[MXN];
	memset (isp, 0, sizeof isp);
	lint i, j, sn = sqrt ( (double) MXN);
	for (i = 3, isp[2] = 1; i < MXN; i++)
		isp[i] = i & 1;
	for (i = 3; i <= sn + 1; i++)
		if (isp[i])
			for (j = i * i; j <= MXN; j += 2 * i)
				isp[j] = 0;
	
	lint prime[PRIME_NUM],mp;	//PRIME_NUM ~= MXN/ln[MXN]
	for (i = 2, mp = 0; i < MXN; i++) if (isp[i]) prime[++mp] = i;
	
**5 因数分解&&质因数分解**

	//TODO LIST

**6 Millar素数测试**
>验题: poj 1811

	lint mr[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	bool RabinMiller (lint n) {
		lint i;
		if (n < MXN) return isp[n];//MXN^3>=n_max 筛出MXN内的素数,筛法表isp[]和素数表prime[]
		for (i = 1; i <= mp; i++) if (n % p[i] == 0) return 0;
		for (i = 0; i < 7; ++i)
			if (mr[i] < n && power (mr[i], n - 1, n) != 1LL)
				return 0;//能搞定long long 内的非Carmichael数
		return 1;
	}

**7 rho大整数因数分解**
>验题: poj 1811

	lint f (lint x, lint m) {
		return (llpro (x, x, m) + 1) % m;
	}
	lint pollardrho (lint n) {
		for (int i = 1; i <= mp; i++)
			if (n % p[i] == 0) return p[i];
		lint i, x, y, ret;
		i = 1;
		while (1) {
			x = i++;
			y = f (x, n);
			ret = gcd ( (y > x ? y - x : x - y) % n, n);
			while (ret == 1) {
				x = f (x, n);
				y = f (f (y, n), n);
				ret = gcd ( (y > x ? y - x : x - y) % n, n) % n;
			}
			if (0 < ret && ret < n) {		//n%ret=0
				lint l = RabinMiller (ret) ? ret : pollardrho (ret);
				lint ans = n / ret;
				lint r = RabinMiller (ans) ? ans : pollardrho (ans);
				return min (l, r);
			}
		}
	}

**8 阶乘||组合数 取模**
>验题:未验

	int fact[MAX_P];	//预处理n! mod p 的表 O(p)
	// n!=a*p^e return a%p
	int modFact (int n, int p, int &e) {
		e = 0;
		if (!n) return 1;
		int res = modFact (n / p, p, e);
		e += n / p;
		if (n / p % 2)
			return res * (p - fact[n % p]) % p;
		return res * fact[n % p] % p;
	}
	//C _(n) ^(k) %p
	int modComb (int n, int k, int p) {
		if (n < 0 || k < 0 || n < k) return 0;
		int e1, e2, e3;
		int a1 = modFact (n, p, e1);
		int a2 = modFact (k, p, e2);
		int a3 = modFact (n - k, p, e3);
		if (e1 > e2 + e3) return 0;
		return a1 * modInv (a2 * a3 % p, p) % p;
	}

**9 欧拉函数**//O(sqrt[n])
	
>验题: poj 1284

	int eulerPhi (int n) {
		int res = n;
		for (int i = 2; i * i <= n; i++)		//可用质数加速
			if (n % i == 0) {
				res = res / i * (i - 1);
				for (; n % i == 0; n /= i);
			}
		if (n != 1) res = res / n * (n - 1);
		return res;
	}

	int euler[MAX_N];
	//O(n)
	void tableEuler (int n) {
		for (int i = 0; i < n; i++)
			euler[i] = i;
		for (int i = 2; i < n; i++)
			if (euler[i] == i)
				for (int j = i; j < n; j += i) euler[j] = euler[j] / i * (i - 1);
	}

**10 模同余方程组**
>验题:未验

	//a_i*x=b_i {%m_i}  m_i可以不互质
	//pair<b,m>			x=b {%m}
	pair<int, int> linearMod (const vector<int>&A, const vector<int>&B, const vector<int>&M) {
		int x = 0, m = 1;
		for (int i = 0; i < A.size(); i++) {
			int a = A[i] * m, b = B[i] - A[i] * x, d = __gcd (M[i], a);
			if (b % d) return MP (0, -1);
			int t = b / d * modInv (a / d, M[i] / d) % (M[i] / d);
			x = x + m * t;
			m *= M[i] / d;
		}
		return MP (x % m, m);
	}

**11 中国剩余定理 CRT**
>验题: hdu 4767<br>
>special: bell[n + p] = (bell[n] + bell[n + 1]) {mod p}

	//x=t_i {%primeMOD_i}
	int primeMOD[MAX_N], M[MAX_N], m[MAX_N], r[MAX_N];
	int MOD = 1LL;
	for (int t = 0; t < n; t++) MOD *= primeMOD[t];
	for (int t = 0; t < n; t++) m[t] = MOD / primeMOD[t];
	for (int t = 0; t < n; t++) M[t] = modInv (m[t], primeMOD[t]);
	int ans = 0;
	for (int t = 0; t < n; t++)
		ans = ( (ans + m[t] * M[t] % MOD * r[t] % MOD) % MOD + MOD) % MOD;

**12 高斯消元**
>验题:未验

	//全主元gauss消去解a[][]x[]=b[]
	//返回是否有唯一解,若有解在b[]中
	#define MAXN 100
	#define fabs(x) ((x)>0?(x):-(x))
	#define eps 1e-10
	int gauss_tpivot (int n, double a[][MAXN], double b[]) {
		int i, j, k, row, col, index[MAXN];
		double maxp, t;
		for (i = 0; i < n; i++)
			index[i] = i;
		for (k = 0; k < n; k++) {
			for (maxp = 0, i = k; i < n; i++)
				for (j = k; j < n; j++)
					if (fabs (a[i][j]) > fabs (maxp))
						maxp = a[row = i][col = j];
			if (fabs (maxp) < eps)
				return 0;
			if (col != k) {
				for (i = 0; i < n; i++)
					t = a[i][col], a[i][col] = a[i][k], a[i][k] = t;
				j = index[col], index[col] = index[k], index[k] = j;
			}
			if (row != k) {
				for (j = k; j < n; j++)
					t = a[k][j], a[k][j] = a[row][j], a[row][j] = t;
				t = b[k], b[k] = b[row], b[row] = t;
			}
			for (j = k + 1; j < n; j++) {
				a[k][j] /= maxp;
				for (i = k + 1; i < n; i++)
					a[i][j] -= a[i][k] * a[k][j];
			}
			b[k] /= maxp;
			for (i = k + 1; i < n; i++)
				b[i] -= b[k] * a[i][k];
		}
		for (i = n - 1; i >= 0; i--)
			for (j = i + 1; j < n; j++)
				b[i] -= a[i][j] * b[j];
		for (k = 0; k < n; k++)
			a[0][index[k]] = b[k];
		for (k = 0; k < n; k++)
			b[k] = a[0][k];
		return 1;
	}

**13 原根**