//单纯形
//>验题: hdu2979

const int MVar = 444, MEqa = 444;
long double a[MEqa][MVar];
int idx[MVar], nv, ne;
int nxt[MVar];//-a[0][0]=max ∑a[0][i]*x[i]
void show() {
	int i, j;
	for ( i = 0; i <= ne; i++ ) {
		printf( "%d[%d]%3.5lf=\t", i, idx[i], a[i][0] );
		for ( j = 1; j <= nv; j++ )if (abs(a[i][j]) > eps)printf( "%3.5lf*x[%d] ", a[i][j], j );
		printf( "\n" );
	}
	printf( "\n" );
}
void pivot( int e, int v ) {
	int i, j;
	long double temp;
	int tp = MVar - 1;
	for ( j = nv; j >= 0; j-- )nxt[j] = -1;
	for ( j = nv; j >= 0; j-- )if ( abs( a[e][j] ) > eps ) {nxt[tp] = j; tp = j;}
	temp = a[e][v];
	for ( tp = nxt[MVar - 1]; tp != -1; tp = nxt[tp] )a[e][tp] /= temp;
	for ( i = 0; i <= ne; i++ )if ( abs( a[i][v] ) > eps && i != e ) {
			temp = a[i][v];
			for ( tp = nxt[MVar - 1]; tp != -1; tp = nxt[tp] )
				a[i][tp] -= temp * a[e][tp];
		}
	idx[e] = v;
}
int dualsolve() {
	int i, j;
	long double temp;
	for ( j = 1; j <= nv; j++ )if ( a[0][j] < -eps )return 0;
	while ( 1 ) {
		int l = 0, r = 0;
		temp = -eps;
		for ( i = 1; i <= ne; i++ )if ( a[i][0] < temp )temp = a[i][0], r = i;
		if ( !r )return 1;
		temp = 1e100;
		for ( j = 1; j <= nv; j++ )if ( a[r][j] < -eps && a[0][j] / a[r][j] < temp )
				temp = a[0][j] / a[r][j], l = j;
		if ( !l )return 0;
		pivot( r, l );
	}
}
int solve() {
	int i, j;
	long double temp;
	for ( i = 1; i <= ne; i++ )for (k = 0; k <= ne; k++)if (k != i && abs( a[k][idx[i]] ) > eps ) {
				temp = a[k][idx[i]];
				for ( j = 0; j <= nv; j++ )a[k][j] -= temp * a[i][j];
			}
	int dual = 0;
	for ( i = 1; i <= ne; i++ )if ( a[i][0] < -eps )dual = 1;
	if ( dual ) {
		int dual = dualsolve();
		if ( !dual )return 0;	//no solution
	}
	while ( 1 ) {
		int l = 0, r = 0;
		temp = 1e100;
		for ( j = 1; j <= nv; j++ )if ( a[0][j] > eps ) {l = j; break;}
		if ( !l )return 1;		//done
		for ( i = 1; i <= ne; i++ )if ( a[i][l] > eps && a[i][0] + eps < a[i][l]*temp )
				temp = a[i][0] / a[i][l], r = i;
		if ( !r )return -1;		//infinite
		pivot( r, l );
	}
}
