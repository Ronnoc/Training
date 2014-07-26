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
LL dp[100010];
void partition( int n ) {
	dp[0]=1;
	int i,j,r;
	for ( i=1; i<=n; i++ ) {
		dp[i]=0;
		for ( j=1,r=1; i>=( 3*j*j-j )/2; j++,r*=-1 ) {
			dp[i]+=dp[i-( 3*j*j-j )/2]*r;
			if ( i>=( 3*j*j+j )/2 )
				dp[i]+=dp[i-( 3*j*j+j )/2]*r;
			dp[i]=dp[i]%MOD+MOD;
		}
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	partition( 100000 );
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; ++CA ) {
		cin>>i;
		cout<<dp[i]%MOD<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
