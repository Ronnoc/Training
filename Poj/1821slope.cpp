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
int L[111],P[111],S[111];
int dq[16005],op,ed;
LL dp[2][16005];
int slope( LL X,LL Y,LL P,LL Q ) {
	if ( P*Y<X*Q )return -1;
	return P*Y>X*Q;
}
int main() {
//	freopen("in.txt","r",stdin);
//	freopen("m.txt","w",stdout);
	int i,j,k;
	int N,M;
	while ( ~scanf( "%d%d",&N,&M ) ) {
		for ( i=1; i<=M; i++ )scanf( "%d%d%d",&L[i],&P[i],&S[i] );
		for ( i=1; i<=M; i++ )for ( j=i+1; j<=M; j++ )if ( S[j]<S[i] )
					swap( L[i],L[j] ),swap( P[i],P[j] ),swap( S[i],S[j] );
		memset( dp,0,sizeof dp );
		int x=0,y=1;
		for ( i=1; i<=M; i++ ) {
			op=ed=0;
			for ( j=0; j<=N; j++ )dp[y][j]=dp[x][j];
			for ( j=max( 0,S[i]-L[i] ); j<S[i]&&j<=N; j++ ) {
				while ( ed-op>=2 ) {
					int l=dq[ed-2],r=dq[ed-1];
					if ( slope( r-l,dp[x][r]-dp[x][l],j-r,dp[x][j]-dp[x][r] )<=0 )ed--;
					else break;
				}
				dq[ed++]=j;
			}
			for ( j=S[i]; j<S[i]+L[i]&&j<=N; j++ ) {
				while ( ed-op>=2 ) {
					int l=dq[op],r=dq[op+1];
					if ( j-l>L[i]||slope( r-l,dp[x][r]-dp[x][l],1,P[i] )>=0 ){
						op++,k=l+1;
						if(k<r){
							if(ed-op<=1)dq[--op]=k;
							else {
								l=dq[op],r=dq[op+1];
								if(slope(r-l,dp[x][r]-dp[x][l],l-k,dp[x][l]-dp[x][k])<0)
									dq[--op]=k;
							}
						}
					}
					else break;
				}
				cmax( dp[y][j],dp[x][dq[op]]+1LL*P[i]*( j-dq[op] ) );
			}
			swap( x,y );
			for ( j=1; j<=N; j++ )cmax( dp[x][j],dp[x][j-1] );
		}
		printf( "%I64d\n",dp[x][N] );
	}
	return 0;
}
