//莫比乌斯
//>验题:zju_watashi(map)
map<int, int> moebius (LL n) {
	map<int, int> res;
	vector<int>prime;
	int i, j;
	for (i = 2; i * i <= n; i++)
		if (n % i == 0) {
			prime.push_back (i);
			while (n % i == 0) n /= i;
		}
	if (n != 1) prime.push_back (n);
	int m = prime.size();
	for (int i = 0; i < (1 << m); i++) {
		int mu = 1, d = 1;
		for (j = 0; j < m; j++) {
			if (i >> j & 1) {
				mu *= -1;
				d *= prime[j];
			}
			res[d] = mu;
		}
	}
	return res;
}