#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define PB push_back
#define MP make_pair
#define AA first
#define SZ size()
#define BB second
#define OP begin()
#define ED end()
int n;
vector<int>X,Y;
pair<int,int> dp[60000];
int pre[60000];
char s[11][11];
bool valid( int x,int y ) {
	if ( x<0||x>=n )return 0;
	if ( y<0||y>=n )return 0;
	return 1;
}
bool v[12][12];
int retff;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
char T[11][11];
void FF( int x,int y,char c ) {
	if ( !valid( x,y ) )return;
	if ( T[x][y]!=c )return;
	if ( v[x][y] )return;
	v[x][y]=1;
	retff++;
	for ( int i=0; i<4; i++ )
		FF( x+dx[i],y+dy[i],c );
}
int gao( int id ) {
	int i,j;
	memset( v,0,sizeof v );
	int ret=0,cnt=0;
	for ( i=0; i<n; i++ )for ( j=0; j<n; j++ )
			if ( T[i][j]==( '0'+id )&&!v[i][j] ) {
				retff=0;
				FF( i,j,'0'+id );
				cmax( ret,retff );
			}
//	cout<<ret<<endl;
	return ret;
}
pair<int,int> solve( int mask ) {
	pair<int,int> &tp=dp[mask];
	if ( tp.AA!=-1 )return tp;
	int st[12],i,j;
	int tmp=mask;
	for ( i=0; i<X.SZ; i++ ) {st[X.SZ-1-i]=tmp%3; tmp/=3;}
	char t[11][11];
	memcpy( t,s,sizeof s );
	for ( i=0; i<X.SZ; i++ )if ( st[i]!=2 )t[X[i]][Y[i]]=st[i]+'0';
	int hasNext=0;
	for ( i=0; i<X.SZ; i++ )if ( st[i]==2 )hasNext=1;
	int c0=0,c1=0;
	for ( i=0; i<n; i++ )for ( j=0; j<n; j++ )
			if ( t[i][j]=='0' )c0++;
			else if ( t[i][j]=='1' )c1++;
	if ( !hasNext ) {
		memcpy( T,t,sizeof t );
		if ( c0==c1 )return tp=MP( gao( 0 ),gao( 1 ) );
		else return tp=MP( gao( 1 ),gao( 0 ) );
	}
	int next=( c0>c1 )?1:0;
	int best=-n*n*n;
	for ( i=0; i<X.SZ; i++ )if ( st[i]==2 ) {
			int ts[12];
			memcpy( ts,st,sizeof st );
			ts[i]=next;
			int tmp=0;
			for ( j=0; j<X.SZ; j++ )tmp=tmp*3+ts[j];
			pair<int,int> to=solve( tmp );
			int iff=to.BB-to.AA;
			if(iff>best){
				best=iff;
				tp=MP(to.BB,to.AA);
				pre[mask]=i;
			}else cmin(pre[mask],i);
		}
	return tp;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while ( ~scanf( "%d",&n )&&n ) {
		memset( dp,-1,sizeof dp );
		X.clear();
		Y.clear();
		for ( i=0; i<n; i++ )scanf( "%s",s[i] );
		for ( i=0; i<n; i++ )for ( j=0; j<n; j++ )if ( s[i][j]=='.' )X.PB( i ),Y.PB( j );
		int mask=0;
		for ( i=0; i<X.SZ; i++ )mask=mask*3+2;
		solve( mask );
//		cout<<pre[mask]<<" "<<dp[mask].AA<<" vs "<<dp[mask].BB<<endl;
		printf( "(%d,%d) %d\n",X[pre[mask]],Y[pre[mask]],dp[mask].AA-dp[mask].BB );
	}
	return 0;
}
