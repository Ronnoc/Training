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
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const LL MOD = 1000000007;
LL dp[100010];
void partition( int n ) {
	int i,j,r;
	for ( dp[0]=1,i=1; i<=n; i++ ) {
		dp[i]=0;
		for ( j=1,r=1; i>=( 3*j*j-j )/2; j++,r*=-1 ) {
			dp[i]+=dp[i-( 3*j*j-j )/2]*r;
			if ( i>=( 3*j*j+j )/2 )
				dp[i]+=dp[i-( 3*j*j+j )/2]*r;
			dp[i]=dp[i]%MOD+MOD;
		}
		dp[i]%=MOD;
	}
}
int get( int n,int k ) {
	LL ret=dp[n];
	for ( int j=1,r=-1; n>=k*( 3*j*j-j )/2; j++,r*=-1 ) {
		ret+=dp[n-k*( 3*j*j-j )/2]*r;
		if ( n>=k*( 3*j*j+j )/2 )
			ret+=dp[n-k*( 3*j*j+j )/2]*r;
		ret=ret%MOD+MOD;
	}
	return ret%MOD;
}
int main() {
	int i,j;
	partition( 100001 );
	int n,m;
	int T;
	scanf( "%d",&T );
	while ( T-- ) {
		scanf( "%d%d",&n,&m );
		printf( "%d\n",get( n,m )%MOD );
	}
	return 0;
}
