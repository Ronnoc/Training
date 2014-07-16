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
pair<LL,int>S[100005];
int nS=0;
int a[100005];
int sum[100005][33];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int n,m;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		nS=0;
		for ( i=1; i<=n; i++ )scanf( "%d",&a[i] );
		memset( sum[0],0,sizeof sum[0] );
		for ( i=0; i<=n; i++ ) {
			if ( i )for ( j=0; j<m; j++ )sum[i][j]=sum[i-1][j]+( a[i]>>j&1 );
			LL Hash=0;
			for ( j=1; j<m; j++ )Hash=Hash*37+( sum[i][j]-sum[i][j-1]+37 );
			S[nS++]=( MP( Hash,i ) );
		}
		sort( S,S+nS );
		int ans=0;
		for ( i=0; i<nS; ) {
			int l=i;
			while ( i<nS&&S[i].AA==S[l].AA )i++;
			int r=i-1;
			i=r+1;
			cmax( ans,S[r].BB-S[l].BB );
		}
		printf( "%d\n",ans );
	}
	return 0;
}
