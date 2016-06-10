//BSGS离散对数
//>验题:poj3243,hdu2815,hdu5022
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
int extBSGS( int A, int B, int C ) { //A^x==B mod C
	for ( int i = 0, tmp = 1 % C; i < 100; i++, tmp = 1LL * tmp * A % C )if ( tmp == B )return i;
	int temp, d = 0;
	LL D = 1 % C;
	while ( ( temp = __gcd( A, C ) ) != 1 ) {
		if ( B % temp )return -1;
		C /= temp, B /= temp;
		d++;
		D = 1LL * A / temp * D % C;
	}
	int s = ( int )ceil( sqrt( C + eps ) ) + 1;
	vector<PII>L;
	LL G = 1 % C;
	for ( int i = 0; i < s; i++ ) {
		L.PB( MP( G, i ) );
		G = G * A % C;
	}
	sort( L.OP,L.ED );
	for ( int i = 0; i <= s; i++ ) {
		int tmp = modInv( D, C ) * B % C;
		int id = lower_bound( L.OP, L.ED, MP( tmp, -1 ) ) - L.OP;
		if ( id < L.SZ && id >= 0 && L[id].AA == tmp )
			return i * s + L[id].BB + d;
		D = D * G % C;
	}
	return -1;
}