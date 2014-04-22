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
int main() {
	int i,j,k;
	int dp[16][33];	//i个数 最后一个是j的种数
	memset( dp,0,sizeof dp );
	for ( i=0; i<26; i++ )dp[1][i]=1;
	for ( i=1; i<10; i++ )for ( j=0; j<26; j++ )if ( dp[i][j] )
				for ( k=j+1; k<26; k++ )dp[i+1][k]+=dp[i][j];
	char c[6];
	while ( ~scanf( "%s",c ) ) {
		int flag=0;
		for ( i=1; c[i]; i++ )if ( c[i]<=c[i-1] )flag=1;
		if ( flag ) {
			printf( "0\n" );
			continue;
		}
		int len=strlen( c );
		int pre=0;
		for ( i=1; i<len; i++ )for ( j=0; j<26; j++ )pre+=dp[i][j];
		for ( i=0; i<len; i++ ) {
			if(i)j=c[i-1]-'a'+1;
			else j=0;
			for ( ; j<c[i]-'a'; j++ ) {
				pre+=dp[len-i][25-j];
//				cout<<i<<" "<<char( j+'a' )<<" "<<len-i<<" "<<25-j<<" "<<dp[len-i][25-j]<<endl;
			}
		}
		printf( "%d\n",pre+1 );
	}
	return 0;
}
