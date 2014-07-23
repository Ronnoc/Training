//Zoj 2107 1.2s 比SYSU的略慢,但是13多校03的1011要快一倍
//看main就好了
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
#define SQ(x) ((x) * (x))

const int MAXN = int ( 1e5 + 10 );
double closed;
struct Point {
	double x, y;
	int id;
};
Point pts[MAXN],lP[MAXN],rP[MAXN];
struct cmpY {
	bool operator()( const Point &lhs, const Point &rhs ) {
		return lhs.y < rhs.y;
	}
};
struct cmpX {
	bool operator()( const Point &lhs, const Point &rhs ) {
		return lhs.x < rhs.x;
	}
};
double dist( const Point &pt1, const Point &pt2 ) {
	return sqrt( SQ( pt1.x - pt2.x ) + SQ( pt1.y - pt2.y ) );
}
void findNearest( int l, int r ) {
	if ( r<=l ) return;
	int mid = l + r >> 1;
	findNearest( l, mid );
	findNearest( mid + 1, r );
	int lm = mid, rm = mid + 1;
	while ( lm - 1 >= l && pts[mid].x - pts[lm - 1].x < closed ) --lm;
	while ( rm + 1 <= r && pts[rm + 1].x - pts[mid].x < closed ) ++rm;
	int nlP = 0, nrP = 0;
	for ( int i = lm; i <= mid; ++i ) lP[nlP++] = pts[i];
	for ( int i = mid + 1; i <= rm; ++i ) rP[nrP++] = pts[i];
	sort( lP, lP + nlP, cmpY() );
	sort( rP, rP + nrP, cmpY() );
	int j = 0;
	for ( int i = 0; i < nlP; ++i ) {
		while ( j < nrP && rP[j].y < lP[i].y ) ++j;
		for ( int k = j - 2; k <= j + 2; ++k ) {
			if ( k < 0 || k >= nrP ) continue;
			closed=min( dist( lP[i], rP[k] ),closed );
		}
	}
}

int main() {
	int i, n;
	while ( scanf( "%d", &n ) != EOF && n ) {
		for ( i = 1; i <= n; i++ ) scanf( "%lf%lf", &pts[i].x, &pts[i].y );
		sort( pts + 1, pts + n + 1, cmpX() );
		int flag = 0;
		for ( i = 1; i < n; i++ ) {
			if ( dist( pts[i], pts[i + 1] ) < 1e-4 ) {
				printf( "0.00\n" );
				flag = 1;
				break;
			}
		}
		if ( flag ) continue;
		closed = 1e300;
		findNearest( 1, n );
		printf( "%.2lf\n", closed / 2 );
	}
	return 0;
}
