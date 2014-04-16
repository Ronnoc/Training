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
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

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
int h[1111],n;
bool can( int d,int &l,int &r ) {
	for ( r=0; h[1]-d+r*( n-1 )<=h[n]+d; r++ ) {
		int L=h[1]-d,R=h[1]+d;
		for(int i=2;i<=n;i++){
			int z=h[i]-(i-1)*r;
			if(z-d>L)L=z-d;
			if(z+d<R)R=z+d;
		}
		if(L<=R){l=L;return 1;}
	}
	return 0;
}
int main() {
	int i,j;
	while ( ~scanf( "%d",&n ) ) {
		for ( i=1; i<=n; i++ )scanf( "%d",&h[i] );
		sort( h+1,h+1+n );
		int l=0,r=20000;
		int ans,p,q;
		while ( r>=l ) {
			if ( r-l<=1 ) {
				if ( can( l,p,q ) ) {ans=l; break;}
				if ( can( r,p,q ) ) {ans=r; break;}
			}
			int mid=( l+r )/2;
			if ( can( mid,p,q ) )r=mid;
			else l=mid+1;
		}
		cout<<ans<<" "<<p<<" "<<q<<endl;
	}
	return 0;
}
