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
char s[100005];
int tot,flag;
int dp[1<<21][21];
int w[23],m;
int solve( int mask,int turn) {
	int &tp=dp[mask][turn];
	if(tp!=-1)return tp;
//	cout<<mask<<" "<<turn<<endl;
	tp=0;
	int i;
	int id,left;
	for(i=0;i<m;i++)if(mask>>i&1);else break;
	if(i!=m&&!solve(mask|(1<<i),turn+1))return tp=1;
	left=w[id=i]-turn;
//	cout<<left<<"~"<<turn<<endl;
	for ( i++; i<m; i++ )if ( mask>>i&1 );
		else {
			if(!left){
				if(!solve(mask|(1<<i)|(1<<id),turn+1))return tp=1;
			}else if(!solve(mask|(1<<i),turn+1))return tp=1;
		}
	return tp=0;
}
int main() {
	freopen("g1.in","r",stdin);
	freopen("g1.out","w",stdout);
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		scanf( "%d%s",&j,s );
		int tot=0, len=strlen( s );
		memset( dp,-1,sizeof dp );
		for ( i=0,m=0; s[i]; i++ )if ( s[i]=='1' )w[m++]=i;
		if ( solve( 0,0 ) )printf( "Adam\n" );
		else printf( "Betka\n" );
		//printf("Case #%d:",CASE);
	}
	return 0;
}
/*
4
1101
B
*/
