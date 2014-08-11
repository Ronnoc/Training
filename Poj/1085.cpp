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
int dp[1<<18];
int sum[1<<18];
bool vis[1<<18];
int ID[5][5];
int L[22],R[22],n;
int ALL=( 1<<18 )-1;
int P[]= {1,2,4,3,5,6,1,3, 6,2,5,4,2,4,5,7,8, 9};
int Q[]= {2,4,7,5,8,9,3,6,10,5,9,8,3,5,6,8,9,10};
map<PII,int>S;
int getid( int l,int r ) {
	if ( S.find( MP( l,r ) )!=S.ED )return S[MP( l,r )];
	for ( int i=0; i<18; i++ )
		if ( P[i]==l&&Q[i]==r )
			return S[MP( l,r )]=i;
	return S[MP( l,r )]=-1;
}
int gao( int mask,int ic ) {
	return sum[mask^( 1<<ic )]-sum[mask];
}
int dfs( int mask ) {
	if ( mask==ALL )return 0;
	if ( vis[mask] )return dp[mask];
	vis[mask]=1;
	int remain=ALL^mask;
	int &tp=dp[mask];
	tp=-100;
	while ( remain ) {
		int ch=remain&( -remain );
		int ic=__builtin_ctz( ch );
		remain^=ch;
		int add=gao( mask,ic );
		if ( add )cmax( tp,add+dfs( mask^ch ) );
		else cmax( tp,-dfs( mask^ch ) );
	}
	return tp;
}
vector<int>G[18];
int main() {
	int i,j,k,T;
	int CA=0;
	memset( vis,0,sizeof vis );
	for ( int ic=0; ic<18; ic++ ) {
		int l=P[ic],r=Q[ic];
		for ( i=1; i<11; i++ )if ( i!=l&&i!=r ) {
				int lid=getid( min( i,l ),max( i,l ) );
				int rid=getid( min( i,r ),max( i,r ) );
				if ( ~lid )if ( ~rid )G[ic].PB( ( 1<<lid )|( 1<<rid ) );
			}
	}
	sum[0]=0;
	for ( i=1; i<1<<18; i++ ) {
		int last=i&( -i );
		k=__builtin_ctz( last );
		sum[i]=sum[i^last];
		for ( j=0; j<G[k].SZ; j++ )if ( ( i&G[k][j] )==G[k][j] )
				sum[i]++;
	}
	scanf( "%d",&T );
	while ( T-- ) {
		scanf( "%d",&n );
		for ( i=0; i<n; i++ )scanf( "%d%d",&L[i],&R[i] );
		for ( i=0; i<n; i++ )if ( R[i]<L[i] )swap( L[i],R[i] );
		int mask=0,ans=0,miu=1;
		for ( i=0; i<n; i++ ) {
			int id=getid( L[i],R[i] );
			int add=gao( mask,id );
			mask|=1<<id;
			ans+=miu*add;
			if ( !add )miu*=-1;
//			cout<<L[i]<<"-"<<R[i]<<" id"<<id<<" add"<<add<<" miu"<<miu<<" ans"<<ans<<endl;
		}
		ans+=miu*dfs( mask );
		printf( "Game %d: %s wins.\n",++CA,ans>0?"A":"B" );
	}
	return 0;
}
