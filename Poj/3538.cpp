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
set<int>::iterator it;
bool dp[1005][10005];
int pre[1005][10005];
int fa[1111];
int getfa( int x ) {return fa[x]==x?x:fa[x]=getfa( fa[x] );}
int main() {
//	freopen("domestic.in","r",stdin);
//	freopen("domestic.out","w",stdout);
	int i,j;
	int n,m;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		int a,b,l;
		vector<pair<PII,PII> >L;
		for ( i=1; i<=n; i++ )fa[i]=i;
		memset( dp,0,sizeof dp );
		memset( pre,-1,sizeof pre );
		for ( i=1; i<=m; i++ ) {
			scanf( "%d%d%d",&a,&b,&l );
			L.PB( MP( MP( l,i ),MP( a,b ) ) );
		}
		int p5,q5,p6,q6;
		scanf( "%d%d%d%d",&p5,&q5,&p6,&q6 );
		set<int>s5,s6,s;
		SORT( L );
		vector<PII>G;
		int tot=0;
		for ( i=0; i<L.SZ; i++ ) {
			int u=L[i].BB.AA;
			int v=L[i].BB.BB;
			int fu=getfa( u );
			int fv=getfa( v );
			if ( fu==fv )continue;
			G.PB( L[i].AA );
			tot+=L[i].AA.AA;
			fa[fu]=fv;
		}
		set<int>tree;
		for ( i=1; i<=n; i++ )tree.insert( getfa( i ) );
		if ( tot>q5+q6||tree.SZ>1 ) {
			printf( "Impossible\n" );
			continue;
		}
		SORT( G );
		int w[1111],id[1111];
		for ( i=0; i<G.SZ; i++ )w[i]=G[i].AA;
		for ( i=0; i<G.SZ; i++ )id[i]=G[i].BB;
		dp[0][0]=1,pre[0][0]=0;
		int mxn=max(q5,q6);
		for ( i=0; i<G.SZ; i++ ) {
			for ( j=0; j<=mxn; j++ ) {
				if ( !dp[i][j] )continue;
				dp[i+1][j]=1;
				pre[i+1][j]=j;
				int nxt=j+w[i];
				if ( nxt>mxn )continue;
				dp[i+1][nxt]=1;
				pre[i+1][nxt]=j;
			}
		}
		int f=5;
		int fq=q5;
		if ( p6<p5 )fq=q6,f=6;
		int elq=q5+q6-fq;
		while ( fq&&!dp[G.SZ][fq] )fq--;
		if ( elq<tot-fq ) {
			printf( "Impossible\n" );
			continue;
		}
		i=G.SZ,j=fq;
		while ( 1 ) {
			if ( !i )break;
			int p=pre[i][j];
			i--;
			if ( p!=j )
				s.insert( i );
			j=p;
		}
//		cout<<fq<<" "<<f<<"ssz"<<s.SZ<<endl;
		if ( f==5 )for(it=s.OP;it!=s.ED;++it)s5.insert(*it);
		else for(it=s.OP;it!=s.ED;++it)s6.insert(*it);
//		cout<<s5.SZ<<" "<<s6.SZ<<endl;
//		for(it=s.OP;it!=s.ED;++it)cout<<(*it)<<" ";cout<<endl;
		for ( i=0; i<G.SZ; i++ ) {
			if ( f==5 ) {
				if ( s5.count( i )==0 )s6.insert( i );//cout<<i<<"in6"<<endl;}
				continue;
			}
			if ( s6.count( i )==0 )s5.insert( i );//cout<<i<<"in5"<<endl;}
//			else cout<<i<<"in6"<<endl;
		}
		vector<PII>ans;
		int len5=0,len6=0;
		for ( it=s5.OP; it!=s5.ED; ++it ) {
			int z=*it;
//			cout<<z<<" ";
			len5+=w[z];
			ans.PB( MP( id[z],5 ) );
		}
//		cout<<endl;
		for ( it=s6.OP; it!=s6.ED; ++it ) {
			int z=*it;
			len6+=w[z];
//			cout<<z<<" ";
			ans.PB( MP( id[z],6 ) );
		}
//		cout<<endl;
		SORT( ans );
		printf( "%d\n",len5*p5+len6*p6 );
		for ( i=0; i<ans.SZ; i++ )printf( "%d %d\n",ans[i].AA,ans[i].BB );
	}
	return 0;
}
/*
4 5
1 2 5
1 3 3
1 4 7
2 4 2
3 4 6
3 4 2 6

4 5
1 2 5
1 3 3
1 4 7
2 4 2
3 4 4
3 4 2 5

4 3
1 2 5
2 3 5
3 4 5
2 15 3 4

*/
