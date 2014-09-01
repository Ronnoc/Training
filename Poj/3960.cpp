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

typedef long long LL;
typedef pair<int,int> PII;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
const double eps = 1e-8;
const LL MOD = 1000000007;
int G[11][11];
LL ten[33];
int solve( int x,LL cnt,int w ) {
//	cout<<"call solve "<<x<<" "<<cnt<<" "<<w<<endl;
//	int t=x;
//	LL cc=cnt;
	int vis[11];
	memset( vis,-1,sizeof vis );
	vis[x]=0;
	int i,id=0;
	while ( cnt-- ) {
		x=G[x][w];
		if ( vis[x]<0 )vis[x]=++id;
		else {
			int last=vis[x];
			vis[x]=++id;
			int turn=vis[x]-last;
			cnt%=turn;
		}
	}
//	cout<<t<<" solve "<<cc<<" "<<w<<" => "<<x<<endl;
	return x;
}
int play( int x,LL cnt,LL q ) {
//	cout<<"call play "<<x<<" "<<cnt<<" "<<q<<endl;
//	int t=x;
//	LL cc=cnt;
	int vis[11];
	memset( vis,-1,sizeof vis );
	vis[x]=0;
	int i,id=0;
	while ( cnt-- ) {
		for ( i=0; i<=9; i++ )x=solve( x,q,i );
		if ( vis[x]<0 )vis[x]=++id;
		else {
			int last=vis[x];
			vis[x]=++id;
			int turn=vis[x]-last;
			cnt%=turn;
		}
	}
//	cout<<t<<" play "<<cc<<" "<<q<<" => "<<x<<endl;
	return x;
}
int main() {
	int i,j;
	ten[0]=1;
	for ( i=1; i<=20; i++ )ten[i]=ten[i-1]*10;
//	freopen( "binary.in", "r", stdin );
//	freopen( "binary.out", "w", stdout );
	for ( i=0; i<10; i++ )for ( j=0; j<10; j++ )scanf( "%d",&G[i][j] );
	LL a,b;
	ten[19]=ten[18]*4;
	while ( cin>>a>>b ) {
		if ( a==b ) {
			cout<<a<<endl;
			continue;
		}
		char sa[22],sb[22],s[22];
		sprintf( s,"%I64d",a );
		sprintf( sa,"%I64d",a+1 );
		sprintf( sb,"%I64d",b );
		string ta=sa,tb=sb,t=s;
		while ( ta.SZ<tb.SZ )ta="0"+ta;
		while ( t.SZ<tb.SZ )t="0"+t;
		reverse( ta.OP,ta.ED );
		reverse( tb.OP,tb.ED );
		reverse( t.OP,t.ED );
		string ans;
		for ( i=0; i<ta.SZ; i++ ) {
//			cout<<">>>>  "<<i<<endl;
			int x=t[i]-'0';
			LL mx,mn;
			LL p=a+1,q=b;
			for ( j=ta[i]-'0'; j<=9; j++ ) {
				mn=p/ten[i+1]*ten[i+1]+j*ten[i];
				mx=mn+ten[i]-1;
				cmin( mx,q ),cmax( mn,p );
				if ( mn<=mx )x=solve( x,mx-mn+1,j );
				cmax( p,mx+1 );
			}
			LL cnt=( q/ten[i+1]-p/ten[i+1] );
			x=play( x,cnt,ten[i] );
			for ( j=0; j<=tb[i]-'0'; j++ ) {
				mn=q/ten[i+1]*ten[i+1]+j*ten[i];
				mx=mn+ten[i]-1;
				cmin( mx,q ),cmax( mn,p );
				if ( mn<=mx )x=solve( x,mx-mn+1,j );
				cmax( p,mx+1 );
			}
			ans+=( x+'0' );
		}
		reverse( ans.OP,ans.ED );
		int id=0;
		while ( ans[id]=='0'&&id<ans.SZ )id++;
		int flag=0;
		for ( i=id; i<ans.SZ; i++ ) {cout<<ans[i]; flag=1;}
		if ( !flag )cout<<0;
		cout<<endl;
	}
	return 0;
}
