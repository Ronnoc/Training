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
LL D[22];
LL comb[22][22];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,u,v;
	D[0]=1;
	D[1]=0;
	D[2]=1;
	for ( i=3; i<=17; i++ )D[i]=( i-1 )*( D[i-1]+D[i-2] );
	for ( i=0; i<=17; i++ ) {
		comb[i][0]=comb[i][i]=1;
		for ( j=1; j<i; j++ )comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
	}
	int T=0,CA;
	scanf( "%d",&T );
	while ( T-- ) {
		scanf( "%d",&CA );
		int n,k;
		scanf( "%d%d",&n,&k );
		LL ans=0;
		for ( i=0; i<=n-k; i++ )ans+=comb[n-k][i]*D[n-i];
		cout<<CA<<" "<<ans<<endl;
	}
	return 0;
}
