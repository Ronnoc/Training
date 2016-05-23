//高斯消元
//>验题:hdu4870

#define MXN 300
#define fabs(x) ((x)>0?(x):-(x))
double a[MXN][MXN], b[MXN];
int index[MXN];
int gauss_tpivot(int m, int n) {
	int i, j, k, row, col;
	double maxp, t;
	for (i = 0; i < m; i++)index[i] = i;
	for (k = 0; k < n; k++) {
		for (maxp = 0, i = k; i < m; i++)
			for (j = k; j < n; j++)
				if (fabs(a[i][j]) > fabs(maxp))
					maxp = a[row = i][col = j];
		if (fabs(maxp) < eps)
			return 0;
		if (col != k) {
			for (i = 0; i < m; i++)
				swap(a[i][col], a[i][k]);
			swap(index[col], index[k]);
		}
		if (row != k) {
			for (j = k; j < n; j++)
				swap(a[k][j], a[row][j]);
			swap(b[k], b[row]);
		}
		for (j = k + 1; j < n; j++) {
			a[k][j] /= maxp;
			for (i = k + 1; i < m; i++)
				a[i][j] -= a[i][k] * a[k][j];
		}
		b[k] /= maxp;
		for (i = k + 1; i < m; i++)
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

//>验题: poj2345

#define MXN 300
int idx[MXN];
LL a[MXN][MXN], b[MXN];
int gaussTpivotMod(int m, int n, int mod = 2) { //mod 下高斯消
	int i, j, k, row, col;
	LL maxp, t;
	int ret = 1;
	for (i = 0; i < m; i++)idx[i] = i;
	for (k = 0; k < n; k++) {
		for (maxp = 0, i = k; i < m; i++)
			for (j = k; j < n; j++)
				if (a[i][j] > maxp)
					maxp = a[row = i][col = j];
		if (maxp == 0) {
			bool fail = 0;
			for (i = k; i < m; i++)if (b[i])fail = 1;
			if (fail)return 0;
			ret = k - n;
			break;
		}
		if (col != k)for (swap(idx[col], idx[k]), i = 0; i < m; i++)
				swap(a[i][col], a[i][k]);
		if (row != k)for (swap(b[k], b[row]), j = k; j < n; j++)
				swap(a[k][j], a[row][j]);
		LL inv = modInv(maxp, mod);
		for (i = k + 1; i < m; i++) {
			LL mul = inv * a[i][k];
			for (j = k; j < n; j++)
				a[i][j] -= a[k][j] * mul;
			b[i] -= mul * b[k];
		}
		for (i = k; i < m; i++)
			for (j = k; j < n; j++) {
				LL &tmp = a[i][j];
				if (tmp >= mod)tmp %= mod;
				if (tmp < 0)tmp = tmp % mod + mod;
			}
	}
	for (i = n - 1; i >= 0; i--)
		for (j = i + 1; j < n; j++)
			b[i] -= a[i][j] * b[j];
	for (k = 0; k < n; k++)
		a[0][idx[k]] = b[k];
	for (k = 0; k < n; k++)
		b[k] = (a[0][k] % mod + mod) % mod;
	return ret;
}