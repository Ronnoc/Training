//阶乘模分解
//>验题:浙大shi哥译书

int fact[MAX_P];	//预处理n! mod p 的表 O(min(n,p))
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