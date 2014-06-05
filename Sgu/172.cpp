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
vector<int>G[222];
int clr[222];
int main() {
	int i,j,u,v,w;
	int n,m;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		for ( i=1; i<=n; i++ )G[i].clear();
		memset( clr,-1,sizeof clr );
		for ( i=1; i<=m; i++ ) {
			scanf( "%d%d",&u,&v );
			G[u].PB( v );
			G[v].PB( u );
		}
		int flag=1;
		for ( i=1; i<=n; i++ ) {
			if(clr[i]!=-1)continue;
			queue<PII>Q;
			Q.push( MP( i,0 ) );
			while ( !Q.empty() ) {
				PII tp=Q.front(); Q.pop();
				u=tp.AA,w=tp.BB;
				if ( clr[u]!=-1&&clr[u]!=w )flag=0;
				clr[u]=w;
				for ( i=0; i<G[u].SZ; i++ ) {
					v=G[u][i];
					if ( clr[v]!=-1 )
					{if ( clr[v]==clr[u] )flag=0;}
					else Q.push( MP( v,1-w ) );
				}
			}
		}
		if ( flag ) {
			printf( "yes\n" );
			int tot=n;
			for ( i=1; i<=n; i++ )tot-=clr[i];
			printf("%d\n",tot);
			printf("%d",1);
			for(i=2;i<=n;i++)if(!clr[i])printf(" %d",i);
			printf("\n");
		}else printf("no\n");
	}
	return 0;
}
