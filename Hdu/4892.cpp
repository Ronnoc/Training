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
int ax[333],ay[333];
int x[44],y[44];
int A[333];
int sf[5];
int n,m,o;
int ID[44][44][44];
int nextid;
int mask[9999];
double len[9999];
double d[44][44];
double dp[9999][1<<6];
vector<int>has[9999];
priority_queue<pair<double,pair<int,int> > >Q;
int mabs( int a ) {return a>0?a:-a;}
int xmult( int x1,int y1,int x2,int y2 ) {
	return mabs( x1*y2-x2*y1 );
}
bool fitin( int id,int p,int q,int r ) {
	int S=xmult( x[q]-x[p],y[q]-y[p],x[r]-x[p],y[r]-y[p] );
	int S1=xmult( ax[id]-x[p],ay[id]-y[p],x[r]-x[p],y[r]-y[p] );
	int S2=xmult( ax[id]-x[p],ay[id]-y[p],x[q]-x[p],y[q]-y[p] );
	int S3=xmult( ax[id]-x[q],ay[id]-y[q],x[r]-x[q],y[r]-y[q] );
	return S1+S2+S3==S;
}
void dfs( int h ) {
	if ( h>3 ) {
		ID[sf[1]][sf[2]][sf[3]]=++nextid;
		mask[nextid]=0;
		for ( int i=0; i<n; i++ )
			if ( fitin( i,sf[1],sf[2],sf[3] ) )
				mask[nextid]|=1<<A[i];
		len[nextid]=d[sf[1]][sf[2]]+d[sf[1]][sf[3]]+d[sf[2]][sf[3]];
		has[nextid].PB( sf[1] );
		has[nextid].PB( sf[2] );
		has[nextid].PB( sf[3] );
//		cout<<nextid<<":";
//		for ( int i=1; i<=3; i++ )cout<<"("<<x[sf[i]]<<","<<y[sf[i]]<<")";
//		cout<<len[nextid]<<" "<<mask[nextid]<<endl;
		return;
	}
	for ( int i=sf[h-1]+1; i<m; i++ ) {
		sf[h]=i;
		dfs( h+1 );
	}
}
int main() {
	freopen( "1006.in","r",stdin );
	freopen( "m1006.out","w",stdout );
	int i,j,k,l;
	while ( ~scanf( "%d%d%d",&n,&m,&o ) ) {
//		for ( i=0; i<n; i++ )ax[i]=rand();
//		for ( i=0; i<n; i++ )ay[i]=rand();
//		for ( i=0; i<n; i++ )A[i]=rand()%o;
//		for ( i=0; i<m; i++ )x[i]=rand();
//		for ( i=0; i<m; i++ )y[i]=rand();
		for ( i=0; i<n; i++ )scanf( "%d%d",&ax[i],&ay[i] );
		for ( i=0; i<n; i++ )scanf( "%d",&A[i] );
		for ( i=0; i<n; i++ )A[i]--;
		for ( i=0; i<m; i++ )scanf( "%d%d",&x[i],&y[i] );
//		cerr<<n<<" "<<m<<" "<<o<<endl;
		for ( i=0; i<m; i++ )for ( j=0; j<m; j++ )
				d[i][j]=sqrt( 0.0+ SQ( x[i]-x[j] )+SQ( y[i]-y[j] ) );
		sf[0]=-1,nextid=0;
		for ( i=1; i<=9880; i++ )has[i].clear();
		dfs( 1 );
		while ( !Q.empty() )Q.pop();
		for ( i=1; i<=nextid; i++ ) {
			for ( j=0; j<1<<o; j++ )dp[i][j]=1e100;
			int S=mask[i];
			do {
				dp[i][S]=len[i];
				S=( S-1 )&mask[i];
			} while ( S&mask[i] );
			dp[i][0]=len[i];
		}
		double ans=1e100;
		for ( i=1; i<=nextid; i++ ) {
			Q.push( MP( -dp[i][mask[i]],MP( mask[i],i ) ) );
		}
		while ( !Q.empty() ) {
			pair<double,pair<int,int> >tp=Q.top();
			Q.pop();
			double dd=-tp.AA;
			int u=tp.BB.BB;
			int mk=tp.BB.AA;
//			cout<<d<<" "<<u<<" "<<mk<<endl;
			if ( dd>ans )break;
			if ( mk+1==( 1<<o ) ) {
				ans=dd;
				break;
			}
			for ( j=0; j<3; j++ )for ( k=0; k<m; k++ )if ( k!=has[u][j] ) {
						vector<int>V;
						for ( l=0; l<3; l++ )if ( l!=j )V.PB( has[u][l] );
						double g=d[V[0]][V[1]];
						V.PB( k );
						SORT( V );
						int v=ID[V[0]][V[1]][V[2]];
						double e=len[v]-g*2;
						if ( dd+e<dp[v][mk|mask[v]] ) {
							dp[v][mk|mask[v]]=dd+e;
							Q.push( MP( -dp[v][mk|mask[v]],MP( mk|mask[v],v ) ) );
						}
					}
		}
		while ( !Q.empty() )Q.pop();
		if ( ans==1e100 )printf( "Impossible\n" );
		else printf( "%.12f\n",ans );
	}
	return 0;
}
