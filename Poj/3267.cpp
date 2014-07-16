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
char dic[605][33];
int len[605];
char s[333];
int tmp[605][333];
int W,L;
int dp[333][333];
int solve( int l,int r ) { //[l,r)
	int &tp=dp[l][r];
	if ( tp!=-1 )return tp;
	tp=r-l;
	int i;
	for ( i=0; i<W; i++ )
		if ( tmp[i][l]<=r&&tmp[i][l]!=-1 )cmin( tp,tmp[i][l]-l-len[i]+solve( tmp[i][l],r ) );
	return tp;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while ( ~scanf( "%d%d",&W,&L ) ) {
		scanf( "%s",s );
		for ( i=0; i<W; i++ )scanf( "%s",dic[i] );
		for ( i=0; i<W; i++ )len[i]=strlen( dic[i] );
		memset( tmp,-1,sizeof tmp );
		memset( dp,-1,sizeof dp );
		for ( i=0; i<W; i++ )
			for ( j=0; j<=L-len[i]; j++ ) {
				int id=0,k=j;
				while ( id<len[i]&&k<L ) {
					if ( dic[i][id]==s[k] )id++;
					k++;
				}
				if ( id==len[i] )tmp[i][j]=k;
			}
		printf( "%d\n",solve( 0,L ) );
	}
	return 0;
}
