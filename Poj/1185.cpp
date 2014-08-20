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
char s[222][22];
int dp[111][66][66];
int mask[222];
vector<int>ST;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,t,sub;
	int n,m;
	for ( i=0; i<1<<10; i++ ) {
		int flag=1,sub=i;
		if ( sub&( sub<<1 ) )flag=0;
		if ( sub&( sub<<2 ) )flag=0;
		if ( flag )ST.PB( i );
	}
	while ( ~scanf( "%d%d",&n,&m ) ) {
		for ( i=1; i<=n; ++i )scanf( "%s",s[i] );
		memset( mask,0,sizeof mask );
		for ( i=1; i<=n; ++i )
			for ( j=0; j<m; j++ )
				if ( s[i][j]=='P' )mask[i]|=1<<j;
		int A=( 1<<m )-1;
		int B=A<<m;
		memset(dp,0,sizeof dp);
		int ans=0;
		for ( i=0; i<n; i++ )for(j=0;j<ST.SZ;j++)for(k=0;k<ST.SZ;k++)
			for(t=0;t<ST.SZ;t++){
				int sub=ST[t];
				if((sub&mask[i+1])!=sub)continue;
				if(sub&ST[j])continue;
				if(sub&ST[k])continue;
				cmax(dp[i+1][k][t],dp[i][j][k]+__builtin_popcount(sub));
				cmax(ans,dp[i+1][k][t]);
			}
		printf("%d\n",ans);
	}
	return 0;
}
