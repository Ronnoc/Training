//Polya 原理
//>验题:poj1286

//返回置换最小周期,num返回循环节个数
int polya (int* perm, int n, int& num) {
	int i, j, p, v[MXN] = {0}, ret = 1;
	for (num = i = 0; i < n; i++)if (!v[i]) {
			for (num++, j = 0, p = i; !v[p = perm[p]]; j++)
				v[p] = 1;
			ret *= j / __gcd (ret, j);
		}
	return ret;
}