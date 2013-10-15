#数学#
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

**4 线性相关**
>验题:未验

	//判线性相关(正交化)
	//传入m个n维向量
	#define MAXN 100
	#define eps 1e-10
	int linear_dependent (int m, int n, double vec[][MAXN]) {
		double ort[MAXN][MAXN], e;
		int i, j, k;
		if (m > n)
			return 1;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++)
				ort[i][j] = vec[i][j];
			for (k = 0; k < i; k++) {
				for (e = j = 0; j < n; j++)
					e += ort[i][j] * ort[k][j];
				for (j = 0; j < n; j++)
					ort[i][j] -= e * ort[k][j];
				for (e = j = 0; j < n; j++)
					e += ort[i][j] * ort[i][j];
				if (fabs (e = sqrt (e)) < eps)
					return 1;
				for (j = 0; j < n; j++)
					ort[i][j] /= e;
			}
		}
		return 0;
	}

**5 Polya 原理**
>验题:未验

	//perm[0..n-1]为0..n-1的一个置换(排列)
	//返回置换最小周期,num返回循环节个数
	#define MAXN 1000
	//gcd need
	int polya (int* perm, int n, int& num) {
		int i, j, p, v[MAXN] = {0}, ret = 1;
		for (num = i = 0; i < n; i++)
			if (!v[i]) {
				for (num++, j = 0, p = i; !v[p = perm[p]]; j++)
					v[p] = 1;
				ret *= j / gcd (ret, j);
			}
		return ret;
	}

