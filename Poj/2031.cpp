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
int fa[111];
int getfa( int u ) {return fa[u]==u?u:fa[u]=getfa( fa[u] );}
double x[111],y[111],z[111],r[111];
int n;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while ( cin>>n&&n ) {
		vector<pair<double,PII> >L;
		for ( i=0; i<n; i++ )cin>>x[i]>>y[i]>>z[i]>>r[i];
		for ( i=0; i<n; i++ )fa[i]=i;
		for ( i=0; i<n; i++ )for ( j=i+1; j<n; j++ ) {
				double d=sqrt( SQ( x[i]-x[j] )+SQ( y[i]-y[j] )+SQ( z[i]-z[j] ) );
				if ( d>r[i]+r[j]+eps )
					L.PB( MP( d-r[i]-r[j],MP( i,j ) ) );
//				else if ( d<max( r[i],r[j] )-min( r[i],r[j] )-eps )
//					L.PB( MP( max( r[i],r[j] )-min( r[i],r[j] )-d,MP( i,j ) ) );
				else L.PB( MP( 0,MP( i,j ) ) );
			}
		SORT( L );
		double ans=0;
		for ( i=0; i<L.SZ; i++ ) {
			int u=getfa( L[i].BB.AA );
			int v=getfa( L[i].BB.BB );
			if ( u!=v )fa[u]=v,ans+=L[i].AA;
		}
		printf( "%.3f\n",ans );
	}
	return 0;
}
