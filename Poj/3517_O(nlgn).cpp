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
const int MXN = 10010;
int BIT[MXN+20];
int LB( int w ) {return w&( -w );}
int query( int w ) {
	int ret=0;
	for ( w+=5; w>0; w-=LB( w ) )ret+=BIT[w];
	return ret;
}
void update( int w,int d ) {
	for ( w+=5; w<MXN; w+=LB( w ) )BIT[w]+=d;
}
int n,m,k,live;
int query( int l,int r ) {
	l%=n,r%=n;
	if ( l<=r )return query( r )-query( l-1 );
	return query( n+1 )-query( l-1 )+query( r );
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	while ( ~scanf( "%d%d%d",&n,&k,&m ) ) {
		if ( !n&&!m&&!k )break;
		live=n;
		memset( BIT,0,sizeof BIT );
		m%=n;
		for ( i=0; i<n; i++ )update( i,1 );
		while ( live>1 ) {
			update( m,-1 );
			live--;
			int l=m+1,r=m+n-1;
			int have=k%live;
			if ( !have )have=live;
			while ( r>=l ) {
				if ( r-l<=1 ) {
					if ( query( m,l )==have )m=l;
					else m=r;
					m%=n;
					break;
				}
				int mid=( l+r )/2;
				if ( query( m,mid )>=have )r=mid;
				else l=mid+1;
			}
		}
		if ( !m )m=n;
		printf( "%d\n",m );
	}
	return 0;
}





