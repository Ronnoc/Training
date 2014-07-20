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
int a[1111],b[1111];
double s[1111];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int n,k;
	while ( ~scanf( "%d%d",&n,&k ) ) {
		if ( !n&&!k )break;
		for ( i=0; i<n; i++ )scanf( "%d",&a[i] );
		for ( i=0; i<n; i++ )scanf( "%d",&b[i] );
		double l=0,r=100;
		while ( r-l>1e-2 ) {
			double mid=( l+r )/2;
			for ( i=0; i<n; i++ )s[i]=100.0*a[i]-mid*b[i];
			sort( s,s+n );
			double sum=0;
			for ( i=k; i<n; i++ )sum+=s[i];
			if ( sum>-eps )l=mid;
			else r=mid;
		}
		printf( "%d\n",( int )( round( ( l+r )/2 )+0.5 ) );
	}
	return 0;
}
