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
int GOT=0;
int n,m;
int a[5][5];
int b[5][5];
int fa[11];
int getfa( int u ) {return fa[u]==u?u:fa[u]=getfa( fa[u] );}
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
vector<int>G[11];
int F[11][11];
int E[11][11];
int vis[11];
int clr[11];
int mask[11];
void dfs( int h ) {
	if ( GOT )return;
	int i,j,k;
	if ( h==n*n ) {
		memset( F,0,sizeof F );
		for ( i=0; i<m; i++ )for ( j=0; j<G[i].SZ; j++ )F[i][G[i][j]]=1;
		for ( i=0; i<m; i++ )fa[i]=i;
		for ( i=0; i<m; i++ ) {
			int p=i/n,q=i%n;
			for ( j=0; j<4; j++ ) {
				int x=p+dx[j];
				int y=q+dy[j];
				if ( x<0||x>=n )continue;
				if ( y<0||y>=n )continue;
				k=x*n+y;
				if ( !F[i][k]&&!F[k][i] ) {
					int fi=getfa( i );
					int fk=getfa( k );
					fa[fi]=fk;
				}
			}
		}
		vector<int>ID;
		for ( i=0; i<m; i++ )if ( fa[i]==i )ID.PB( i );
		memset(E,0,sizeof E);
		for(i=0;i<m;i++)for(j=0;j<m;j++)if(F[i][j]&&F[j][i])return;
		for ( i=0; i<m; i++ )for ( j=0; j<m; j++ ) if(F[i][j]){
				int fi=getfa( i );
				int fj=getfa( j );
				if(fi!=fj){
					int ii=lower_bound(ID.OP,ID.ED,fi)-ID.OP;
					int ij=lower_bound(ID.OP,ID.ED,fj)-ID.OP;
					E[ii][ij]=1;
				}else return;
			}
		int remain=ID.SZ;
		memset(vis,0,sizeof vis);
		int value=10;
		while(remain){
			int rk=MOD;
			vector<int>who;
			for(i=0;i<ID.SZ;i++)if(!vis[i]){
				int cnt=0;
				for(j=0;j<ID.SZ;j++)if(!vis[j])if(E[i][j])cnt++;
				if(cnt<rk){rk=cnt;who.clear();who.PB(i);}
				else if(cnt==rk)who.PB(i);
			}
			if(rk!=0)return;
			value--;
			for(i=0;i<who.SZ;i++){
				remain--;
				vis[who[i]]=1;
				clr[who[i]]=value;
			}
		}
		for(i=0;i<n;i++)for(j=0;j<n;j++){
			int id=lower_bound(ID.OP,ID.ED,getfa(n*i+j))-ID.OP;
			b[i][j]=clr[id];
		}
		for(i=0;i<n;i++)for(j=0;j<n;j++){
			int cnt=0;
			for(k=0;k<4;k++){
				int x=i+dx[k];
				int y=j+dy[k];
				if ( x<0||x>=n )continue;
				if ( y<0||y>=n )continue;
				if(b[x][y]>b[i][j])cnt++;
			}
			if(cnt!=a[i][j])return;
		}
//		for(i=0;i<m;i++)printf("%d ",mask[i]);printf("\n");
//		for(i=0;i<m;i++)printf("%d ",getfa(i));printf("\n");
//		for(i=0;i<ID.SZ;i++)printf("%d~%d ",ID[i],clr[i]);printf("\n");
		GOT=1;
		for(i=0;i<n;i++){
			printf("%d",b[i][0]);
			for(j=1;j<n;j++)printf(" %d",b[i][j]);
			printf("\n");
		}
		return;
	}
	int p=h/n,q=h%n;
	for ( i=0; i<1<<4; i++ ) {
		int cnt=__builtin_popcount( i );
		if ( cnt!=a[p][q] )continue;
		int flag=1;
		G[h].clear();
		for ( j=0; j<4; j++ )if ( i>>j&1 ) {
				int x=p+dx[j];
				int y=q+dy[j];
				if ( x<0||x>=n ) {flag=0; continue;}
				if ( y<0||y>=n ) {flag=0; continue;}
				G[h].PB( n*x+y );
			}
		if ( flag ){mask[h]=i;dfs( h+1 );}
	}
}
int main() {
	int i,j;
	scanf( "%d",&n );
	m=n*n;
	for ( i=0; i<n; i++ )for ( j=0; j<n; j++ )scanf( "%d",&a[i][j] );
	GOT=0;
	dfs( 0 );
	if ( !GOT )printf( "NO SOLUTION\n" );
	return 0;
}
