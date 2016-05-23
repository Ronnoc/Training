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
//模同余方程组中国剩余定理
//>验题:poj2891
//a_i*x=b_i {%m_i}  m_i可以不互质
//pair<b,m>			x=b {%m}
pair<LL, LL> linearMod( vector<LL>&A, vector<LL>&B, vector<LL>&M ) {
	LL x = 0, m = 1;
	for ( int i = 0; i < A.SZ; i++ ) {
		LL a = A[i] * m, b = B[i] - A[i] * x, d = __gcd( M[i], a );
		if ( b % d )return MP( 0, -1 );
		LL t = b / d * modInv( a / d, M[i] / d ) % ( M[i] / d );
		x += m * t;
		m *= M[i] / d;
		x %= m;
	}
	return MP( ( ( x % m ) + m ) % m, m );
}