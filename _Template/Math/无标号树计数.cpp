//无标号树计数
//>来自yh_victor的板子

LL extGcd (LL a, LL b, LL &x, LL &y) {
	LL ret = a;
	if (b) {
		ret = extGcd (b, a % b, y, x);
		y -= (a / b) * x;
	} else x = 1, y = 0;
	return ret;
}
int solve(int k, int n, int p) { //无标号树计数
	int a[55], s[55][55], tmp, foo;
	a[1] = 1;
	for (int j = 1; j < n; j++) {
		a[j + 1] = 0;
		for (int i = 1; i <= j; i++) {
			if (j - i < i) s[j][i] = a[j + 1 - i];
			else s[j][i] = (s[j - i][i] + a[j + 1 - i]) % p;
			a[j + 1] += s[j][i] * i % p * a[i] % p;
		}
		foo = a[j + 1] % p;
		extGcd(j, p, a[j + 1], tmp);
		a[j + i] *= foo, tmp *= foo;
		if (a[j + 1] >= 0) a[j + 1] %= p;
		else a[j + 1] = p - (-a[j + 1]) % p;
	}
	if (k == 1) {		//if无根树
		for (int i = 1; i <= n / 2; i++)a[n] = (a[n] + p - a[i] * a[n - i] % p) % p;
		if ((n & 1) == 0) a[n] += a[n / 2] * (a[n / 2] + 1) / 2;
	}
	return a[n] % p;
}