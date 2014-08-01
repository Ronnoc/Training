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
int a[100005];
int N,M;
int check( int w ) {
	int ret=0,sum=0;
	for ( int i=0; i<N; i++ ) {
		if ( a[i]>w )return N+1;
		sum+=a[i];
		if ( sum>w )sum=a[i],ret++;
	}
	if ( sum )ret++;
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while ( ~scanf( "%d%d",&N,&M ) ) {
		for ( i=0; i<N; i++ )scanf( "%d",&a[i] );
		int l=0,r=0,ans=-1;
		for ( i=0; i<N; i++ )r+=a[i];
		for ( i=0; i<N; i++ )cmax( l,a[i] );
		while ( r>=l ) {
			if ( r-l<=1 ) {
				if ( check( l )<=M )ans=l;
				else if ( check( r )<=M )ans=r;
				break;
			}
			int mid=( r+l )>>1;
			if ( check( mid )<=M )r=mid;
			else l=mid;
		}
		printf( "%d\n",ans );
	}
	return 0;
}
