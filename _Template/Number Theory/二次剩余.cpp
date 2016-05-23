//求解x^2=a mod P
//>验题:ural 1132
LL modPow( LL x, LL n, LL mod ) {
	LL ret = 1;
	while ( n ) {
		if ( n & 1 )ret = ret * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return ret;
}
//call(b,0,a,(p+1)/2,p) return a sol of {x^2=a (mod p)}
//{p is odd prime}&&{a^[(p-1)/2]=1 mod p}&&{b^( (p-1)/2 )==-1 mod p}
LL call(LL b, LL c, LL a, LL x, LL p) {
	if (x % 2 == 0)return modPow(b, c / 2, p) * modPow(a, x / 2, p) % p;
	LL tp = modPow(b, c / 2, p) * modPow(a, (x - 1) / 2, p) % p;
	if (tp == 1)return call(b, c / 2, a, (x + 1) / 2, p);
	return call(b, (c + p - 1) / 2, a, (x + 1) / 2, p);
}