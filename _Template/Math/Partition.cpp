//划分数
//>n划分为K个自然数的和的方案数;验题:hdu4651

LL dp[100010];
void partition( int n ) {
	int i, j, r;
	for ( dp[0] = 1, i = 1; i <= n; i++ ) {
		dp[i] = 0;
		for ( j = 1, r = 1; i >= ( 3 * j * j - j ) / 2; j++, r *= -1 ) {
			dp[i] += dp[i - ( 3 * j * j - j ) / 2] * r;
			if ( i >= ( 3 * j * j + j ) / 2 )
				dp[i] += dp[i - ( 3 * j * j + j ) / 2] * r;
			dp[i] = dp[i] % MOD + MOD;
		}
	}
}

//>验题:hdu4658

int get( int n, int k ) {	//all parts are repeated less than k times.
	LL ret = dp[n];			//<==>all parts are less than k
	for ( int j = 1, r = -1; n >= k * ( 3 * j * j - j ) / 2; j++, r *= -1 ) {
		ret += dp[n - k * ( 3 * j * j - j ) / 2] * r;
		if ( n >= k * ( 3 * j * j + j ) / 2 )
			ret += dp[n - k * ( 3 * j * j + j ) / 2] * r;
		ret = ret % MOD + MOD;
	}
	return ret % MOD;
}