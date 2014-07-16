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
char tmp[111111];
char s[255][255];
int id[255][255];
int v[255][255];
int fa[1111];
int getfa( int u ) {return fa[u]==u?u:fa[u]=getfa( fa[u] );}
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int T;
	scanf( "%d",&T );
	gets( tmp );
	for ( int CA=1; CA<=T; ++CA ) {
		int n,m;
		scanf( "%d%d",&m,&n );
		gets( tmp );
		for ( i=0; i<n; i++ ) {
			for ( j=0; j<m; j++ )s[i][j]=getchar();
			gets( tmp );
		}
		memset( id,0,sizeof id );
		int nid=0,p,q;
		for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )if ( s[i][j]!='#'&&s[i][j]!=' ' )
					id[i][j]=++nid;
		for ( i=1; i<=nid; i++ )fa[i]=i;
		vector<pair<int,PII> >H;
		for ( p=0; p<n; p++ )for ( q=0; q<m; q++ )if ( id[p][q] ) {
					int I=id[p][q];
					for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )v[i][j]=-1;
					v[p][q]=0;
					queue<PII>L;
					L.push( MP( p,q ) );
					while ( !L.empty() ) {
						PII tp=L.front();
						L.pop();
						int x=tp.AA,y=tp.BB;
						for ( int k=0; k<4; k++ ) {
							int xx=x+dx[k],yy=y+dy[k];
							if ( xx<0||xx>=n )continue;
							if ( yy<0||yy>=n )continue;
							if ( s[xx][yy]=='#' )continue;
							if ( v[xx][yy]==-1||v[xx][yy]>v[x][y]+1 ) {
								v[xx][yy]=v[x][y]+1;
								L.push( MP( xx,yy ) );
							}
						}
					}
					for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )if ( id[i][j]&&id[i][j]!=I )
								H.PB( MP( v[i][j]-1,MP( I,id[i][j] ) ) );
				}
		SORT( H );
		int ans=nid-1;
		for ( i=0; i<H.SZ; i++ ) {
			int u=getfa( H[i].BB.AA );
			int v=getfa( H[i].BB.BB );
			if ( u!=v )fa[u]=v,ans+=H[i].AA;
		}
		cout<<ans<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
/*
1
4 4
A   
   S
A   
####

*/
