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
int _x[1010],_y[1010];
LL x[1010],y[1010];
int dp[1010];
LL mabs( LL x ) {return x>0?x:-x;}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; ++CA ) {
		int n;
		int _len;
		scanf( "%d%d",&n,&_len );
		LL len=_len;
		for ( i=0; i<=n+1; i++ )scanf( "%d%d",&_x[i],&_y[i] );
		for ( i=0; i<=n+1; i++ )x[i]=_x[i],y[i]=_y[i];
		for ( i=0; i<=n+1; i++ )dp[i]=1000000;
		priority_queue<PII>Q;
		while ( !Q.empty() )Q.pop();
		Q.push( MP( 0,0 ) );
		dp[0]=0;
		while ( !Q.empty() ) {
			PII tp=Q.top();
			Q.pop();
			int u=tp.BB;
			if ( u==1 )break;
			vector<pair<pair<LL,LL>,pair<LL,int> > >L;
			for ( i=0; i<=n+1; i++ )if ( i!=u&&dp[i]>dp[u]+1 ) {
					LL dx=x[i]-x[u];
					LL dy=y[i]-y[u];
					LL D=SQ( dx )+SQ( dy );
					if ( D>SQ( len ) )continue;
					LL g=__gcd( mabs( dx ),mabs( dy ) );
					dx/=g,dy/=g;
					L.PB( MP( MP( dx,dy ),MP( D,i ) ) );
				}
			sort( L.OP,L.ED );
//            for(i=0;i<L.SZ;i++)cout<<L[i].AA.AA<<","<<L[i].AA.BB<<" "<<L[i].BB.AA<<"@"<<L[i].BB.BB<<endl;
			if ( !L.empty() ) {
				int v=L[0].BB.BB;
				dp[v]=dp[u]+1;
				Q.push( MP( -dp[v],v ) );
				for ( i=1; i<L.SZ; i++ )if ( L[i].AA!=L[i-1].AA ) {
						int v=L[i].BB.BB;
						dp[v]=dp[u]+1;
						Q.push( MP( -dp[v],v ) );
					}
			}
		}
		if ( dp[1]==1000000 )printf( "impossible\n" );
		else printf( "%d\n",dp[1]-1 );
		//printf("Case #%d:",CA);
	}
	return 0;
}
