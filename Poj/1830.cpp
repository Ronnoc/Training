#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 32
//全主元gauss消去解a[][]x[]=b[]
//返回是否有唯一解,若有解在b[]中
int gauss_tpivot( int n, int a[][MAXN], int b[] ) {
	int i, j, k, row, col, index[MAXN];
	double maxp, t;

	for ( k = 0; k < n; k++ ) {
		for ( maxp = 0, i = k; i < n; i++ )
			for ( j = k; j < n; j++ )
				if ( a[i][j] > maxp ) {
					maxp = a[row = i][col = j];
				}

		if ( maxp == 0 ) {
			for ( i = k; i < n; i++ )
				if ( b[i] ) {
					return 0;
				}

			return 1 << ( n - k );
		}

		if ( col != k )
			for ( i = 0; i < n; i++ ) {
				swap( a[i][col], a[i][k] );
			}

		if ( row != k ) {
			for ( j = k; j < n; j++ ) {
				swap( a[k][j], a[row][j] );
			}

			swap( b[k], b[row] );
		}

		for ( j = k + 1; j < n; j++ )
			for ( i = k + 1; i < n; i++ )
			{a[i][j] -= a[i][k] * a[k][j] - 2; a[i][j] %= 2;}

		for ( i = k + 1; i < n; i++ )
		{b[i] -= b[k] * a[i][k] - 2; b[i] %= 2;}
	}

	return 1;
}
int main() {
	int a[MAXN][MAXN], b[MAXN];
	int T;
	scanf( "%d", &T );

	while ( T-- ) {
		int n, i, j;
		scanf( "%d", &n );
		int f[MAXN], t[MAXN];

		for ( i = 0; i < n; i++ ) {			scanf( "%d", &f[i] );		}

		for ( i = 0; i < n; i++ ) {			scanf( "%d", &t[i] );		}

		for ( i = 0; i < n; i++ ) {			b[i] = ( t[i] - f[i] + 2 ) % 2;		}

		for ( i = 0; i < n; i++ )
			for ( j = 0; j < n; j++ ) {
				a[i][j] = ( i == j ) ? 1 : 0;
			}

		int x, y;

		while ( scanf( "%d%d", &x, &y ) != EOF ) {
			if ( !x && !y ) {				break;			}

			x--;
			y--;
			a[y][x] = 1;
		}

		int flag = gauss_tpivot( n, a, b );

		if ( !flag ) {			printf( "Oh,it's impossible~!!\n" );		}
		else {			printf( "%d\n", flag );		}
	}

	return 0;
}
