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
int main() {
	int i,j;
	double P,N,C;
	while ( ~scanf( "%lf%lf%lf",&P,&N,&C ) ) {
		if ( P<0&&N<0&&C<0 )break;
		double Q=( 1+N*C )*P;
		double l=0,r=PI;
		for ( int t=0; t<100; t++ ) {
			double a=( l+r )/2;
			double p=2*Q/a*sin( a/2 );
			if ( p>P )l=a;
			else r=a;
		}
		double a=( l+r )/2;
		printf( "%.3f\n",Q/a-Q/a*cos( a/2 ) );
	}
	return 0;
}
