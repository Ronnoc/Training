//欧拉函数
//>验题: poj 1284

int eulerPhi (int n) {			// test: phi(846720)=193536
	int res = n;
	for (int i = 2; i * i <= n; i++)		//可用质数加速
		if (n % i == 0) {
			res = res / i * (i - 1);
			for (; n % i == 0; n /= i);
		}
	if (n != 1) res = res / n * (n - 1);
	return res;
}