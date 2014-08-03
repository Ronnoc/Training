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
int x[1111],y[1111];
int mabs( int a ) {return a>0?a:-a;}
int main() {
	int n,m,i,j;
	int CA=0;
	while ( ~scanf( "%d",&n ) ) {
		CA++;
		if ( !n )break;
		for ( i=0; i<n; i++ )scanf( "%d%d", &x[i],&y[i] );
		int ans=0;
		for ( i=0; i<n; i++ ) {
			vector<pair<int,int> >L;
			for ( j=0; j<n; j++ )if ( j!=i ) {
					int dx=x[i]-x[j];
					int dy=y[i]-y[j];
					int g=__gcd( mabs( dx ),mabs( dy ) );
					if ( dx<0 )dx*=-1,dy*=-1;
					if ( dx==0&&dy<0 )dy*=-1;
					dx/=g,dy/=g;
					L.push_back( make_pair( dx,dy ) );
				}
			sort( L.begin(),L.end() );
			L.push_back( make_pair( -1,-1 ) );
			j=0;
			while ( j<L.size() ) {
				int l=j;
				while ( L[j]==L[l] )j++;
				int r=j;
				if ( r-l>=3 )if ( r-l+1>ans )ans=r-l+1;
			}
		}
		printf( "Photo %d: %d points eliminated\n",CA,ans );
	}
	return 0;
}
