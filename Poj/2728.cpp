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
int x[1010],y[1010],z[1010];
int fa[1010];
double dis[1010][1010];
int getfa( int u ) {return fa[u]==u?u:fa[u]=getfa( fa[u] );}
double dp[1010];
bool ok[1010];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	while ( ~scanf( "%d",&n )&&n ) {
		for ( i=0; i<n; i++ )scanf( "%d%d%d",&x[i],&y[i],&z[i] );
		for ( i=0; i<n; i++ )for ( j=0; j<n; j++ )dis[i][j]=sqrt( SQ( x[i]-x[j] )+SQ( y[i]-y[j] ) );
		double l=0,r=1e7;
		while ( r-l>1e-5 ) {
			double mid=( l+r )/2;
			for ( i=0; i<n; i++ )dp[i]=fabs( z[0]-z[i] )-mid*dis[0][i];
			for ( i=0; i<n; i++ )ok[i]=0;
			ok[0]=1;
			double now=0;
			for ( i=1; i<n; i++ ) {
				double mx=1e300;
				int id=-1;
				for ( j=0; j<n; j++ )if ( !ok[j] )if ( dp[j]<mx )mx=dp[j],id=j;
				now+=dp[id];
				ok[id]=1;
				for ( j=0; j<n; j++ )if ( !ok[j] )cmin( dp[j],fabs( z[id]-z[j] )-mid*dis[id][j] );
			}
			if ( now>-eps )l=mid;
			else r=mid;
		}
		printf( "%.3f\n",( l+r )/2 );
	}
	return 0;
}
