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

const double eps = 1e-8;
const int MOD = 1000000007;
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
typedef long long LL;
typedef pair<int, int> PII;
LL dp[44][3][3];
LL a[3][3];
void solve() {
	int i,j,k,n,l,r;
	for ( i=0; i<3; i++ )
		for ( j=0; j<3; j++ )
			cin>>a[i][j];
	for ( i=0; i<3; i++ )
		for ( j=0; j<3; j++ )
			dp[0][i][j]=a[i][j];
	for ( n=1; n<=40; n++ )
		for ( i=0; i<3; i++ )
			for ( j=0; j<3; j++ )
				dp[n][i][j]=1LL<<60;
	cin>>n;
	for ( k=0; k<3; k++ )for ( i=0; i<3; i++ )for ( j=0; j<3; j++ )
				dp[0][i][j]=min( dp[0][i][j],dp[0][i][k]+dp[0][k][j] );
	for ( i=1; i<n; i++ )for ( l=0; l<3; l++ )for ( r=0; r<3; r++ ) {
					if ( l==r ) {dp[i][l][r]=0; continue;}
					j=3-l-r;
					LL f1=dp[i-1][l][j]+a[l][r]+dp[i-1][j][r];
					LL f2=dp[i-1][l][r]+a[l][j]+dp[i-1][r][l]+a[j][r]+dp[i-1][l][r];
					dp[i][l][r]=min( dp[i][l][r],min( f1,f2 ) );
				}
	cout<<dp[n-1][0][2]<<endl;
}
int main() {
//	while ( 1 )
		solve();
	return 0;
}
