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
int a[10005],b[10005],c[10005];
int n;
double gao( double x ) {
	double ret=( a[0]*x+b[0] )*x+c[0];
	for ( int i=1; i<n; i++ ) {
		double f=( a[i]*x+b[i] )*x+c[i];
		cmax( ret,f );
	}
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; ++CA ) {
		scanf( "%d",&n );
		for ( i=0; i<n; i++ )
			scanf( "%d%d%d",&a[i],&b[i],&c[i] );
		double le=0,re=1000.0;
		while ( re-le>1e-10 ) {		//误差估计 or 次数限制?
			double l=le+( re-le )/3;
			double r=re-( re-le )/3;
			double fl=gao( l );
			double fr=gao( r );
			if ( fl<fr )re=r;
			else le=l;
		}
		printf( "%.4f\n",gao( ( le+re )/2 ) );
		//printf("Case #%d:",CA);
	}
	return 0;
}
