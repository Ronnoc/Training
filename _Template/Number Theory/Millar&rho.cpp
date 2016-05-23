//Millar素数测试 && rho大整数因数分解
//> 验题: poj 2447, 2429, 1811

const int S = 7;
LL cs[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
LL mutiMod( LL a, LL b, LL c ) { //(a*b)mod c in 2^63(a,b>0)
	a %= c, b %= c;
	LL ret = 0;
	while ( b ) {
		if ( b & 1 ) {
			ret += a;
			if ( ret >= c ) ret -= c;
		}
		a <<= 1, b >>= 1;
		if ( a >= c ) a -= c;
	}
	return ret;
}
/*LL mulMod( LL A,LL B,LL C ) {
	LL y=( ( long double )A*B )/C;
	LL ret=A*B-C*y;
	if ( ret<0 )ret+=C;
	return ret;
}*///fzu1752
LL powMod( LL x, LL n, LL mod ) {
	LL ret = 1;
	while ( n ) {
		if ( n & 1 )ret = mutiMod( ret, x, mod );
		x = mutiMod( x, x, mod );
		n >>= 1;
	}
	return ret;
}
bool check( LL a, LL n, LL x, LL t ) { //以a为基，n-1=x*2^t，检验n是不是合数
	LL ret = powMod( a, x, n ), last = ret;
	for ( int i = 1; i <= t; i++ ) {
		ret = mutiMod( ret, ret, n );
		if ( ret == 1 && last != 1 && last != n - 1 ) return 1;
		last = ret;
	}
	if ( ret != 1 ) return 1;
	return 0;
}
bool Miller_Rabin( LL n ) {
	LL x = n - 1, t = 0;
	while ( ( x & 1 ) == 0 ) x >>= 1, t++;
	bool flag = 1;
	if ( t >= 1 && ( x & 1 ) == 1 ) {
		for ( int k = 0; k < S; k++ ) {
			LL a = cs[k];
			if ( check( a, n, x, t ) ) {flag = 1; break;}
			flag = 0;
		}
	}
	if ( !flag || n == 2 ) return 0;
	return 1;
}
vector<LL>factor;			  	//需要clear
LL Pollard_rho( LL x, LL c ) {
	LL i = 1, x0 = rand() % x, y = x0, k = 2;
	while ( i++ ) {
		x0 = ( mutiMod( x0, x0, x ) + c ) % x;
		LL d = __gcd( y > x0 ? y - x0 : x0 - y, x );
		if ( d != 1 && d != x ) return d;
		if ( y == x0 ) return x;
		if ( i == k ) y = x0, k <<= 1;
	}
}
void findfac( LL n ) {        	//递归进行质因数分解N
	if ( !Miller_Rabin( n ) ) {
		factor.PB( n );
		return;
	}
	LL p = n;
	while ( p >= n ) p = Pollard_rho( p, rand() % ( n - 1 ) + 1 );
	findfac( p );
	findfac( n / p );
}