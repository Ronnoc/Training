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
vector<PII>A[4];
void gao( int a,int &x,int &y ) {
	if ( a==1 ) {x=0,y=0; return;}
	for ( int s=0; s<4; s++ ) {
		int id=lower_bound( A[s].OP,A[s].ED,MP( a,a ) )-A[s].OP-1;
		if ( id<0 )continue;
		int l=A[s][id].AA,r=A[s][id].BB;
		if ( l<=a&&a<=r ) {
			int t=id+1;
			if ( s==1 ) {
				if ( a-l<=t )x=t,y=a-l;
				else y=t,x=r-a;
				return;
			}
			if ( s==2 ) {
				x=l-a;
				y=t-a+l;
				return;
			}
			if ( s==3 ) {
				if ( a-l<=t )x=-t,y=l-a;
				else y=-t,x=a-r;
				return;
			}
			t--;
			if ( a==l ) {
				x=-t,y=0; return;
			}
			int d=a-l-1;
			x=1+d;
			y=-t+d;
			return;
		}
	}
}
bool notp[10007];
int p[20007],pn;
int now[20007],fn;
void shai( int n ) {
	pn=0,notp[0]=1;
	for ( int i=2; i<n; i++ ) {
		if ( !notp[i] )p[pn++]=i;
		for ( int j=0; j<pn&&i*p[j]<n; j++ ) {
			notp[i*p[j]]=1;
			if ( i%p[j]==0 )break;
		}
	}
}
void init() {
	fn=0;
	for ( int i=0; i<pn; i++ )now[i]=0;
}
void update( int u,int t ) {
	for ( int i=0; i<pn&&p[i]<=u; i++ )if ( u%p[i]==0 ) {
			int cnt=0;
			while ( u%p[i]==0 )u/=p[i],cnt++;
			now[i]+=cnt*t;
			cmax( fn,i+1 );
		}
}
void gao( vector<int>&L,int t ) {
	int i;
	for ( i=0; i<L.SZ; i++ )L[i]*=t;
	for ( i=0; i<L.SZ; i++ )if ( L[i]>=10000 ) {
			if ( i+1<L.SZ )L[i+1]+=L[i]/10000;
			else L.PB( L[i]/10000 );
			L[i]%=10000;
		}
}
int main() {
	shai( 5000 );
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int p,q;
	int l=1,d=1;
	for ( i=0; l<=1000000; i++ ) {
		int r=l+( ( i%2 )?( d<<1 ):d );
		A[i%4].PB( MP( l,r ) );
		l=r;
		if ( i%4==3 )d++;
	}
	while ( ~scanf( "%d%d",&p,&q ) ) {
		if ( !p&&!q )break;
		int px,py,qx,qy;
		gao( p,px,py );
		gao( q,qx,qy );
		if ( px>qx )swap( px,qx ),swap( py,qy ),swap( p,q );
		int dx=qx-px;
		int dy=qy-py;
//		cout<<p<<" "<<px<<" "<<py<<endl;
//		cout<<q<<" "<<qx<<" "<<qy<<endl;
		int N,M;
		if ( dy<0 )N=dx-dy,M=min( dx,-dy );
		else N=max( dx,dy ),M=min( dx,dy );
		if ( !dx||!dy||dx-dy==0 ) {
			printf( "There is 1 route of the shortest length %d.\n",N );
		} else {
//			cout<<dx<<" "<<dy<<" "<<N<<"C"<<M<<endl;
			init();
			for ( i=1; i<=M; i++ ) {
				int g=__gcd( N-i+1,i );
				update( ( N-i+1 )/g,1 );
				update( i/g,-1 );
			}
//			for ( i=0; i<fn; i++ )if ( now[i] )cout<<::p[i]<<"^"<<now[i]<<" ";
//			cout<<endl;
			vector<int>L;
			L.PB( 1 );
			for ( i=0; i<fn; i++ )if ( now[i] )
					while ( now[i]-- )gao( L,::p[i] );
			reverse( L.OP,L.ED );
			printf( "There are " );
			printf( "%d",L[0] );
			for ( i=1; i<L.SZ; i++ )printf( "%04d",L[i] );
			printf( " routes of the shortest length %d.\n",N );
		}
	}
	return 0;
}
