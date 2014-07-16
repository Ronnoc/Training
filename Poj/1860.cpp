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
double dp[111];
vector<pair<int,pair<double,double> > >G[111];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int n,m;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		int s; double t;
		scanf( "%d%lf",&s,&t );
		for ( i=1; i<=n; i++ )dp[i]=0;
		for ( i=1; i<=n; i++ )G[i].clear();
		for ( i=1; i<=m; i++ ) {
			int u,v;
			scanf( "%d%d",&u,&v );
			double ruv,cuv,rvu,cvu;
			scanf( "%lf%lf%lf%lf",&ruv,&cuv,&rvu,&cvu );
			G[u].PB( MP( v,MP( ruv,cuv ) ) );
			G[v].PB( MP( u,MP( rvu,cvu ) ) );
		}
		dp[s]=t;
		queue<int>Q;
		Q.push( s );
		int flag=0;
		while ( !Q.empty()&&!flag ) {
			if ( dp[s]>t+eps ) {flag=1; break;}
			int u=Q.front();
			Q.pop();
			for ( i=0; i<G[u].SZ; i++ ) {
				int v=G[u][i].AA;
				double r=G[u][i].BB.AA;
				double c=G[u][i].BB.BB;
				double tmp=( dp[u]-c )*r;
				if ( tmp>dp[v] ) {
					dp[v]=tmp;
					Q.push( v );
				}
			}
		}
		if ( flag )printf( "YES\n" );
		else printf( "NO\n" );
	}
	return 0;
}
