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
char weat[3][10]= {"Sunny","Cloudy","Rainy"};
char leaf[4][10]= {"Dry","Dryish","Damp","Soggy"};
double P1[3][4]= {
	{0.6,	0.2,	0.15,	0.05},
	{0.25,0.3,	0.2,	0.25},
	{0.05,0.1,	0.35,	0.5},
};
double P2[3][3]= {
	{0.5,0.375,0.125},
	{0.25,0.125,0.625},
	{0.25,0.375,0.375},
};
double D1[3]= {0.63,0.17,0.2};
char tmp[11];
int st[55];
double dp[55][3];
double P[3][3][4];
int pre[55][3];
int main() {
//	freopen( "1005.in","r",stdin );
//	freopen( "1005wa.out","w",stdout );
	int i,j,k,t;
	int T;
	scanf( "%d",&T );
	for ( i=0; i<3; i++ )for ( k=0; k<4; k++ )
			for ( j=0; j<3; j++ )
				P[i][j][k]=P2[i][j]*P1[j][k];
	for ( int CA=1; CA<=T; ++CA ) {
		int n;
		scanf( "%d",&n );
		for ( i=1; i<=n; i++ ) {
			scanf( "%s",tmp );
			for ( j=0; j<4; j++ )if ( strcmp( tmp,leaf[j] )==0 )break;
			st[i]=j;
		}
		for ( i=1; i<=n; i++ )for ( j=0; j<3; j++ )dp[i][j]=-1e300;
		for ( j=0; j<3; j++ )dp[1][j]=log( D1[j] )+log( P1[j][st[1]] );
		for ( i=1; i<n; i++ )for ( j=0; j<3; j++ )for ( k=0; k<3; k++ ) {
					double tmp=dp[i][k]+log( P[k][j][st[i+1]] );
					if ( tmp> dp[i+1][j] )dp[i+1][j]=tmp,pre[i+1][j]=k;
				}
		for ( j=0; j<3; j++ )dp[1][j]= D1[j]*P1[j][st[1]];
		for ( i=1; i<n; i++ )for ( j=0; j<3; j++ )for ( k=0; k<3; k++ ) {
					double tmp=dp[i][k]*P[k][j][st[i+1]];
					if ( tmp> dp[i+1][j] )dp[i+1][j]=tmp,pre[i+1][j]=k;
				}
		printf( "Case #%d:\n",CA );
		vector<int>G;
		int ss;
		double _ss=-1e100;
		for ( j=0; j<3; j++ )if ( dp[i][j]>_ss )_ss=dp[i][j],ss=j;
		int id=n;
		while ( id>1 ) {
			G.PB( ss );
			ss=pre[id--][ss];
		}
		G.PB( ss );
		reverse( G.OP,G.ED );
		for ( i=0; i<G.SZ; i++ )cout<<weat[G[i]]<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
