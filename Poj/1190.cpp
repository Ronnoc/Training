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
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
int S;
void solve( int V,int R,int H,int m,int S0 ) {
	if ( V<0 )return;
	double Smin=2.0*V/R+S0;
	if ( Smin>S )return;
	if ( m==0 ) {if ( V ); else cmin( S,S0 ); return;}
	for ( int i=R; i>=m; i-- )
		for ( int j=H; j>=m; j-- )
			solve( V-i*i*j,i-1,j-1,m-1,S0+2*i*j );
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int n,m;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		S=MOD;
		for ( i=n; i>=m; i-- )for ( j=m; i*i*j<=n; j++ )
				solve( n,i,j,m,i*i );
		printf( "%d\n",S );
	}
	return 0;
}
