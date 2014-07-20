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
unsigned long long dp[55][55];
int cnt[55];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n,m;
	int CA=0;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		if ( !n&&!m )break;
		++CA;
		memset( cnt,0,sizeof cnt );
		for ( i=1; i<=n; i++ ) {
			int w;
			scanf( "%d",&w );
			cnt[w]++;
		}
		for ( i=0; i<=51; i++ )for ( j=0; j<=51; j++ )dp[i][j]=0;
		for ( i=0; i<=cnt[1]; i++ )dp[1][i]=1;
		for ( i=2; i<=n; i++ )for ( j=0; j<=51; j++ )
				for ( k=0; k<=cnt[i]&&k<=j; k++ )dp[i][j]+=dp[i-1][j-k];
		cout<<"Case "<<CA<<":\n";
		while ( m-- ) {
			int w;
			scanf( "%d",&w );
			cout<<dp[n][w]<<endl;
		}
	}
	return 0;
}
