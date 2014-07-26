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
const double PI=acos( -1. );
const LL MOD = 1000000007;
double E[1010][1010];
double a[1010][1010];
double b[1010][1010];
double c[1010][1010];
int R,C;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while ( ~scanf( "%d%d",&R,&C ) ) {
		for ( i=1; i<=R; i++ )for ( j=1; j<=C; j++ )
				scanf( "%lf%lf%lf",&a[i][j],&b[i][j],&c[i][j] );
		E[R][C]=0;
		for ( i=R; i>=1; i-- )for ( j=C; j>=1; j-- ) {
				if ( i==R&&j==C )continue;
				E[i][j]=1;
				if ( j<C )E[i][j]+=b[i][j]*E[i][j+1];
				if ( i<R )E[i][j]+=c[i][j]*E[i+1][j];
				if ( a[i][j]<1 )E[i][j]/=1-a[i][j];
			}
		printf( "%.3f\n",E[1][1]*2 );
	}
	return 0;
}
