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
int gg[11][11];
int dp[11][11];
int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int i,j,u,v;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int n,m;
		scanf( "%d%d",&n,&m );
		vector<int>G[55];
		memset( gg,0,sizeof gg );
		string S[55];
		for ( i=1; i<=n; i++ )G[i].clear();
		string ans;
		for ( i=1; i<=n; i++ ) {
			char ss[55];
			scanf( "%s",ss );
			S[i]=ss;
		}
		for ( i=1; i<=m; i++ ) {
			scanf( "%d%d",&u,&v );
			G[u].PB( v );
			gg[u][v]=1;
		}
		vector<int>A;
		for ( i=1; i<=n; i++ )A.PB( i );
		int OOUUTT=0;
		do {
			string temp;
			for ( i=0; i<A.SZ; i++ )temp+=S[A[i]];
//			if(A[0]==5&&A[1]==2&&A[2]==4&&A[3]==1&&A[4]==3)OOUUTT=1;
//			else OOUUTT=0;
			if(OOUUTT)cout<<temp<<endl;
			if ( !ans.empty()&&temp>ans )continue;
			int out[11][11];
			for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )out[i][j]=gg[i][j];
			for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )out[i][j]|=gg[j][i];
			int id=0;
			int flag=0;
			int vis[11];
			memset( vis,0,sizeof vis );
			vis[A[0]]=1;
			if(OOUUTT)cout<<"A:\t";
			if(OOUUTT)for ( i=0; i<A.SZ; i++ )cout<<A[i]<<" ";
			if(OOUUTT)cout<<endl;
			set<PII>USE;
			while ( id<n ) {
				if ( id==n-1 ) {flag=1; break;}
				vis[A[id+1]]=1;
				for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )dp[i][j]=( i==j?0:MOD );
				for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )if ( out[i][j] )cmin( dp[i][j],1 );
				for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )if ( out[i][j] )cmin( dp[j][i],1 );
				int pre[11];
				int dis[11];
				memset( pre,-1,sizeof pre );
				for ( i=1; i<=n; i++ )dis[i]=MOD;
				queue<int>Q;
				Q.push( A[id] );
				dis[A[id]]=0;
				while ( !Q.empty() ) {
					int u=Q.front(); Q.pop();
					for ( v=1; v<=n; v++ ) {
						if ( (USE.count(MP(v,u))||v==A[id+1])&&vis[v]&&dis[v]>dis[u]+dp[u][v] ) {
							dis[v]=dis[u]+dp[u][v];
							pre[v]=u;
							Q.push( v );
						}
					}
				}
				if(OOUUTT)for ( i=1; i<=n; i++,printf( "\n" ) )for ( j=1; j<=n; j++ )printf( "%12d ",dp[i][j] );
				if(OOUUTT)cout<<"id="<<id<<" ";
				if(OOUUTT)for ( i=1; i<=n; i++ )cout<<dis[i]<<"~"; 
				if(OOUUTT)cout<<endl;
				if ( dis[A[id+1]]!=MOD ) {
					int now=A[id+1];
					while ( pre[now]!=-1 ) {
						int u=pre[now];
						int v=now;
						if(USE.count(MP(v,u)));
						else USE.insert(MP(u,v));
						out[u][v]=0;
						now=u;
					}
				} else break;
				id++;
			}
			if(OOUUTT)cout<<temp<<endl;
			if ( flag ) {
				if ( ans.empty() )ans=temp;
				else if ( ans>temp )ans=temp;
			}
		} while ( next_permutation( A.OP,A.ED ) );
		printf( "Case #%d: ",CASE );
		for ( i=0; i<ans.SZ; i++ )printf( "%c",ans[i] );
		printf( "\n" );
	}
	return 0;
}
/*
1
5 5
36642
28444
50012
29651
10953
1 2
1 4
2 3
2 5
4 5
*/
