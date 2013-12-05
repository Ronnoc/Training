#数学#
**1 分割数**
>n划分为K个自然数的方案数
>
>验题: 未验 (东大)

	int dp[MAX_N];
	int partition (int n) {
		dp[0]=1;
		for (int i=1; i<=n; i++) {
			for (int j=1,r=1; i- (3*j*j-j) /2>=0; j++,r*=-1) {
				dp[i]+=dp[i- (3*j*j-j) /2]*r;
				if (i- (3*j*j+j) /2>=0)
					dp[i]+=dp[i- (3*j*j+j) /2]*r;
			}
		}
		return dp[n];
	}


**2 Polya 原理**
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
**3 高斯消元**
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
