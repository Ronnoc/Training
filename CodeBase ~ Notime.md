**1 字典序组合与序号的转换**

	//comb为组合数C(n,m),注意处理C(n,m)=0|n<m
	int comb2num (int n, int m, int *c) {
		int ret = comb (n, m), i;
		for (i = 0; i < m; i++)
			ret -= comb (n - c[i], m - i);
		return ret;
	}
	void num2comb (int n, int m, int* c, int t) {
		int i, j = 1, k;
		for (i = 0; i < m; c[i++] = j++)
			for (; t > (k = comb (n - j, m - i - 1)); t -= k, j++);
	}

**2 字典序全排列与序号的转换**

	int perm2num (int n, int *p) {
		int i, j, ret = 0, k = 1;
		for (i = n - 2; i >= 0; k *= n - (i--))
			for (j = i + 1; j < n; j++)
				if (p[j] < p[i])
					ret += k;
		return ret;
	}
	void num2perm (int n, int *p, int t) {
		int i, j;
		for (i = n - 1; i >= 0; i--)
			p[i] = t % (n - i), t /= n - i;
		for (i = n - 1; i; i--)
			for (j = i - 1; j >= 0; j--)
				if (p[j] <= p[i])
					p[i]++;
	}
**3 幻方构造(L!=2)**

	#define MAXN 100
	void dllb (int l, int si, int sj, int sn, int d[][MAXN]) {
		int n, i = 0, j = l / 2;
		for (n = 1; n <= l * l; n++) {
			d[i + si][j + sj] = n + sn;
			if (n % l) {
				i = (i) ? (i - 1) : (l - 1);
				j = (j == l - 1) ? 0 : (j + 1);
			} else
				i = (i == l - 1) ? 0 : (i + 1);
		}
	}
	void magic_odd (int l, int d[][MAXN]) {
		dllb (l, 0, 0, 0, d);
	}
	void magic_4k (int l, int d[][MAXN]) {
		int i, j;
		for (i = 0; i < l; i++)
			for (j = 0; j < l; j++)
				d[i][j] = ( (i % 4 == 0 || i % 4 == 3) && (j % 4 == 0 || j % 4 == 3) || (i % 4 == 1 || i % 4 == 2) && (j % 4 == 1 || j % 4 == 2)) ? (l * l - (i * l + j)) : (i * l + j + 1);
	}
	void magic_other (int l, int d[][MAXN]) {
		int i, j, t;
		dllb (l / 2, 0, 0, 0, d);
		dllb (l / 2, l / 2, l / 2, l * l / 4, d);
		dllb (l / 2, 0, l / 2, l * l / 2, d);
		dllb (l / 2, l / 2, 0, l * l / 4 * 3, d);
		for (i = 0; i < l / 2; i++)
			for (j = 0; j < l / 4; j++)
				if (i != l / 4 || j)
					t = d[i][j], d[i][j] = d[i + l / 2][j], d[i + l / 2][j] = t;
		t = d[l / 4][l / 4], d[l / 4][l / 4] = d[l / 4 + l / 2][l / 4], d[l / 4 + l / 2][l / 4] = t;
		for (i = 0; i < l / 2; i++)
			for (j = l - l / 4 + 1; j < l; j++)
				t = d[i][j], d[i][j] = d[i + l / 2][j], d[i + l / 2][j] = t;
	}

	void generate (int l, int d[][MAXN]) {
		if (l % 2)
			magic_odd (l, d);
		else if (l % 4 == 0)
			magic_4k (l, d);
		else
			magic_other (l, d);
	}

**4  最长公共递增子序列**

	// 时间复杂度O(n^2 * logn)，空间 O(n^2)
	/**
	 * n为a的大小, m为b的大小
	 * 结果在ans中
	 * "define _cp(a,b) ((a)<(b))"求解最长严格递增序列
	 */
	#define MAXN 1000
	#define _cp(a,b) ((a)<(b))
	typedef int elem_t;
	elem_t DP[MAXN][MAXN];
	int num[MAXN], p[1 << 20];
	int LIS (int n, elem_t *a, int m, elem_t *b, elem_t *ans) {
		int i, j, l, r, k;
		
		DP[0][0] = 0;
		num[0] = (b[0] == a[0]);
		for (i = 1; i < m; i++) {
			num[i] = (b[i] == a[0]) || num[i - 1];
			DP[i][0] = 0;
		}
		for (i = 1; i < n; i++) {
			if (b[0] == a[i] && !num[0]) {
				num[0] = 1;
				DP[0][0] = i << 10;
			}
		for (j = 1; j < m; j++) {
			for (k = ( (l = 0) + (r = num[j - 1] - 1)) >> 1; l <= r; k = (l + r) >> 1)
				if (_cp (a[DP[j - 1][k] >> 10], a[i]))
					l = k + 1;
				else
					r = k - 1;
					
			if (l < num[j - 1] && i == (DP[j - 1][l] >> 10)) {
				if (l >= num[j]) DP[j][num[j]++] = DP[j - 1][l];
				else DP[j][l] = _cp (a[DP[j][l] >> 10], a[i]) ? DP[j][l] : DP[j - 1][l];
			}
			if (b[j] == a[i]) {
				for (k = ( (l = 0) + (r = num[j] - 1)) >> 1; l <= r; k = (l + r) >> 1)
					if (_cp (a[DP[j][k] >> 10], a[i]))
						l = k + 1;
					else
						r = k - 1;
					DP[j][l] = (i << 10) + j;
					num[j] += (l >= num[j]);
					p[DP[j][l]] = l ? DP[j][l - 1] : -1;
				}
			}
		}
		for (k = DP[m - 1][i = num[m - 1] - 1]; i >= 0; ans[i--] = a[k >> 10], k = p[k]);
		return num[m - 1];
	}

**5 Romberg求定积分**

	/*	输入：积分区间[a,b]，被积函数f(x,y,z)
		输出：积分结果
		f(x,y,z)示例：
		double f0( double x, double l, double t )
		{
			return sqrt(1.0+l*l*t*t*cos(t*x)*cos(t*x));
		}*/
	double Romberg (double a, double b, double (*f) (double x, double y, double z), double eps, double l, double t) {
	#define MAX_N  1000
		int i, j, temp2, min;
		double h, R[2][MAX_N], temp4;
		
		for (i = 0; i < MAX_N; i++) {
			R[0][i] = 0.0;
			R[1][i] = 0.0;
		}
		h = b - a;
		min = (int) (log (h * 10.0) / log (2.0)); //h should be at most 0.1
		R[0][0] = ( (*f) (a, l, t) + (*f) (b, l, t)) * h * 0.50;
		i = 1;
		temp2 = 1;
		while (i < MAX_N) {
			i++;
			R[1][0] = 0.0;
			for (j = 1; j <= temp2; j++)
				R[1][0] += (*f) (a + h * ( (double) j - 0.50), l, t);
			R[1][0] = (R[0][0] + h * R[1][0]) * 0.50;
			temp4 = 4.0;
			for (j = 1; j < i; j++) {
				R[1][j] = R[1][j - 1] + (R[1][j - 1] - R[0][j - 1]) / (temp4 - 1.0);
				temp4 *= 4.0;
			}
			if ( (fabs (R[1][i - 1] - R[0][i - 2]) < eps) && (i > min))
				return R[1][i - 1];
			h *= 0.50;
			temp2 *= 2;
			for (j = 0; j < i; j++)
				R[0][j] = R[1][j];
		}
		return R[1][MAX_N - 1];
	}

**6 追赶法解周期性方程**

	/*		周期性方程定义：      | a1 b1 c1 ...               |   |   | =  x1
								|    a2 b2 c2 ...            |   |   | =  x2
								|       ...                  | * | X | =  ...
								| cn-1 ...         an-1 bn-1 |   |   | =  xn-1
								| bn   cn                an  |   |   | =  xn
			输入：a[],b[],c[],x[]
			输出：求解结果X在x[]中
	*/
	void run() {
		c[0] /= b[0]; a[0] /= b[0]; x[0] /= b[0];
		for (int i = 1; i < N - 1; i ++) {
			double temp = b[i] - a[i] * c[i - 1];
			c[i] /= temp;
			x[i] = (x[i] - a[i] * x[i - 1]) / temp;
			a[i] = -a[i] * a[i - 1] / temp;
		}
		a[N - 2] = -a[N - 2] - c[N - 2];
		for (int i = N - 3; i >= 0; i --) {
			a[i] = -a[i] - c[i] * a[i + 1];
			x[i] -= c[i] * x[i + 1];
		}
		x[N - 1] -= (c[N - 1] * x[0] + a[N - 1] * x[N - 2]);
		x[N - 1] /= (c[N - 1] * a[0] + a[N - 1] * a[N - 2] + b[N - 1]);
		for (int i = N - 2; i >= 0; i --)
			x[i] += a[i] * x[N - 1];
	}

**7 N皇后构造解,n>=4**

	void even1 (int n, int *p) {
		int i;
		for (i = 1; i <= n / 2; i++)
			p[i - 1] = 2 * i;
		for (i = n / 2 + 1; i <= n; i++)
			p[i - 1] = 2 * i - n - 1;
	}
	void even2 (int n, int *p) {
		int i;
		for (i = 1; i <= n / 2; i++)
			p[i - 1] = (2 * i + n / 2 - 3) % n + 1;
		for (i = n / 2 + 1; i <= n; i++)
			p[i - 1] = n - (2 * (n - i + 1) + n / 2 - 3) % n;
	}
	void generate (int, int*);
	void odd (int n, int *p) {
		generate (n - 1, p), p[n - 1] = n;
	}
	void generate (int n, int *p) {
		if (n & 1)
			odd (n, p);
		else if (n % 6 != 2)
			even1 (n, p);
		else
			even2 (n, p);
	}

**8 Joseph's Problem**

	// input: n,m		-- the number of persons, the inteval between persons
	// output:		-- return the reference of last person

	int josephus0 (int n, int m) {
		if (n == 2) return (m % 2) ? 2 : 1;
		int v = (m + josephus0 (n - 1, m)) % n;
		if (v == 0) v = n;
		return v;
	}
	int josephus (int n, int m) {
		if (m == 1) return n;
		if (n == 1) return 1;
		if (m >= n) return josephus0 (n, m);
		int l = (n / m) * m;
		int j = josephus (n - (n / m), m);
		if (j <= n - l) return l + j;
		j -= n - l;
		int t = (j / (m - 1)) * m;
		if ( (j % (m - 1)) == 0) return t - 1;
		return t + (j % (m - 1));
	}

**9 牛顿法解多项式的根**

	/* 输入：多项式系数c[]，多项式度数n，求在[a,b]间的根
		 输出：根
		 要求保证[a,b]间有根
	*/
	double fabs (double x) {
		return (x < 0) ? -x : x;
	}
	double f (int m, double c[], double x) {
		int i;
		double p = c[m];
		
		for (i = m; i > 0; i--)
			p = p * x + c[i - 1];
		return p;
	}
	int newton (double x0, double *r,double c[], double cp[], int n,double a, double b, double eps) {
		int MAX_ITERATION = 1000;
		int i = 1;
		double x1, x2, fp, eps2 = eps / 10.0;
		x1 = x0;
		while (i < MAX_ITERATION) {
			x2 = f (n, c, x1);
			fp = f (n - 1, cp, x1);
			if ( (fabs (fp) < 0.000000001) && (fabs (x2) > 1.0))
				return 0;
			x2 = x1 - x2 / fp;
			if (fabs (x1 - x2) < eps2) {
				if (x2 < a || x2 > b)
					return 0;
				*r = x2;
				return 1;
			}
			x1 = x2;
			i++;
		}
		return 0;
	}
	double Polynomial_Root (double c[], int n, double a, double b, double eps) {
		double *cp;
		int i;
		double root;
		cp = (double *) calloc (n, sizeof (double));
		for (i = n - 1; i >= 0; i--) {
			cp[i] = (i + 1) * c[i + 1];
		}
		if (a > b) {
			root = a; a = b; b = root;
		}
		if ( (!newton (a, &root, c, cp, n, a, b, eps)) &&
				 (!newton (b, &root, c, cp, n, a, b, eps)))
			newton ( (a + b) * 0.5, &root, c, cp, n, a, b, eps);
		free (cp);
		if (fabs (root) < eps)
			return fabs (root);
		else
			return root;
	}
