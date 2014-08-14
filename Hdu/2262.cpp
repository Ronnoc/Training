#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const LL MOD = 1000000007;
//全主元gauss消去解a[][]x[]=b[]
//返回是否有唯一解,若有解在b[]中
#define MAXN 250
#define fabs(x) ((x)>0?(x):-(x))
#define eps 1e-10
int gauss_tpivot ( int n, double a[][MAXN], double b[] ) {
	int i, j, k, row, col, index[MAXN];
	double maxp, t;
	for ( i = 0; i < n; i++ )
		index[i] = i;
	for ( k = 0; k < n; k++ ) {
		for ( maxp = 0, i = k; i < n; i++ )
			for ( j = k; j < n; j++ )
				if ( fabs ( a[i][j] ) > fabs ( maxp ) )
					maxp = a[row = i][col = j];
		if ( fabs ( maxp ) < eps )
			return 0;
		if ( col != k ) {
			for ( i = 0; i < n; i++ )
				t = a[i][col], a[i][col] = a[i][k], a[i][k] = t;
			j = index[col], index[col] = index[k], index[k] = j;
		}
		if ( row != k ) {
			for ( j = k; j < n; j++ )
				t = a[k][j], a[k][j] = a[row][j], a[row][j] = t;
			t = b[k], b[k] = b[row], b[row] = t;
		}
		for ( j = k + 1; j < n; j++ ) {
			a[k][j] /= maxp;
			for ( i = k + 1; i < n; i++ )
				a[i][j] -= a[i][k] * a[k][j];
		}
		b[k] /= maxp;
		for ( i = k + 1; i < n; i++ )
			b[i] -= b[k] * a[i][k];
	}
	for ( i = n - 1; i >= 0; i-- )
		for ( j = i + 1; j < n; j++ )
			b[i] -= a[i][j] * b[j];
	for ( k = 0; k < n; k++ )
		a[0][index[k]] = b[k];
	for ( k = 0; k < n; k++ )
		b[k] = a[0][k];
	return 1;
}
int ID[22][22],nextid,n,m;
char s[22][22];
int fa[444];
int getfa ( int u ) {
	return fa[u]==u?u:fa[u]=getfa ( fa[u] );
}
void merfa ( int u,int v ) {
	int fu=getfa ( u );
	int fv=getfa ( v );
	fa[fu]=fv;
}
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int main() {
	int i,j,k;
	while ( ~scanf ( "%d%d",&n,&m ) ) {
		memset ( ID,-1,sizeof ID );
		for ( i=0; i<n; i++ ) scanf ( "%s",s[i] );
		nextid=0;
		for ( i=0; i<n; i++ ) for ( j=0; j<m; j++ )
				if ( s[i][j]!='#' ) ID[i][j]=nextid++;
		int S;
		for ( i=0; i<n; i++ ) for ( j=0; j<m; j++ )
				if ( s[i][j]=='@' ) S=ID[i][j];
		for ( i=0; i<nextid; i++ ) fa[i]=i;
		for ( i=0; i<n; i++ ) for ( j=0; j<m; j++ )
				if ( s[i][j]!='#' ) for ( k=0; k<4; k++ ) {
						int x=i+dx[k],y=j+dy[k];
						if ( x>=0&&y>=0&&~ID[x][y] )
							merfa ( ID[x][y],ID[i][j] );
					}
		int FAIL=1;
		for ( i=0; i<n; i++ ) for ( j=0; j<m; j++ ) if ( s[i][j]=='$' )
					if ( getfa ( ID[i][j] ) ==getfa ( S ) ) FAIL=0;
		if ( FAIL ) {printf ( "-1\n" ); continue;}
		double A[MAXN][MAXN],B[MAXN];
		for ( i=0; i<nextid; B[i++]=0 )
			for ( j=0; j<nextid; j++ ) A[i][j]=0;
		for ( i=0; i<n; i++ ) for ( j=0; j<m; j++ )
				if ( ~ID[i][j] ) {
					int U=ID[i][j];
					A[U][U]=1;
					if ( s[i][j]=='$'||getfa(U)!=getfa(S) ) {
						B[U]=0; continue;
					}
					B[U]=1;
					double cnt=0;
					for ( k=0; k<4; k++ ) {
						int x=i+dx[k],y=j+dy[k];
						if ( x>=0&&y>=0&&~ID[x][y] )
							cnt+=1;
					}
					for ( k=0; k<4; k++ ) {
						int x=i+dx[k],y=j+dy[k];
						if ( x>=0&&y>=0&&~ID[x][y] )
							A[U][ID[x][y]]=-1/cnt;
					}
				}
		gauss_tpivot ( nextid,A,B );
		printf ( "%.6f\n",B[S] );
	}
	return 0;
}
/*
2 2
@$
.$
*/
