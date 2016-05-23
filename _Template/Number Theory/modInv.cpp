//逆元
//>验题: poj2447
LL extGcd (LL a, LL b, LL &x, LL &y) {
	LL ret = a;
	if (b) {
		ret = extGcd (b, a % b, y, x);
		y -= (a / b) * x;
	} else x = 1, y = 0;
	return ret;
}
LL modInv (LL a, LL m) {
	LL x, y;
	extGcd(a, m, x, y);
	return (m + x % m) % m;
}
//if m为质数 [费马小定理]a^(m-1)=1 mod m ==>a^(m-2)是a关于m的逆元