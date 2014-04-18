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
map<char,int>M;
int main() {
	int i,j;
	M['A']=1;
	M['C']=2;
	M['G']=3;
	M['T']=4;
	int G[5][5]= {
		{0,-3,-4,-2,-1},
		{-3,5,-1,-2,-1},
		{-4,-1,5,-3,-2},
		{-2,-2,-3,5,-2},
		{-1,-1,-2,-2,5}
	};
	int dp[111][111];
	int T;
	scanf( "%d",&T );
	while ( T-- ) {
		char a[111],b[111];
		int la,lb;
		scanf( "%d%s",&la,a );
		scanf( "%d%s",&lb,b );
		for ( i=la; i>=1; i-- )a[i]=a[i-1];a[0]=' ';
		for ( i=lb; i>=1; i-- )b[i]=b[i-1];b[0]=' ';
		dp[0][0]=0;
		for ( i=1; i<=la; i++ )dp[i][0]=dp[i-1][0]+G[M[a[i]]][0];
		for ( j=1; j<=lb; j++ )dp[0][j]=dp[0][j-1]+G[0][M[b[j]]];
		for ( i=1; i<=la; i++ )for ( j=0; j<=lb; j++ ) {
				dp[i][j]=dp[i-1][j]+G[M[a[i]]][0];
				if(j)cmax( dp[i][j],dp[i][j-1]+G[M[b[j]]][0] );
				if(j)cmax( dp[i][j],dp[i-1][j-1]+G[M[a[i]]][M[b[j]]] );
			}
//		printf( "%3d%3d",0,0 );
//		for ( j=1; j<=lb; j++ )printf( "%3c",b[j] );
//		printf( "\n" );
//		for ( i=0; i<=la; i++ ) {
//			printf( "%3c",a[i] );
//			for ( j=0; j<=lb; j++ )printf( "%3d",dp[i][j] );
//			printf( "\n" );
//		}
		printf( "%d\n",dp[la][lb] );
	}
	return 0;
}
