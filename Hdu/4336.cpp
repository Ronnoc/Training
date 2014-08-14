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
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const LL MOD = 1000000007;
double E[1<<20];
double sum[1<<20];
double p[20];
int n;
int main() {
	int i,j;
	while ( ~scanf( "%d",&n ) ) {
		for ( i=0; i<n; i++ )scanf( "%lf",&p[i] );
		double tmp=1;
		for ( i=0; i<n; i++ )tmp-=p[i];
		for ( sum[0]=tmp,i=0; i<n; i++ )sum[1<<i]=sum[0]+p[i];
		for ( i=1; i<1<<n; i++ ) {
			int la=i&-i;
			if ( i^la )sum[i]=sum[i^la]+p[__builtin_ctz( la )];
		}
		int ALL=( 1<<n )-1;
		E[ALL]=0;
		for ( i=ALL-1; i>=0; i-- ) {
			j=i^ALL;
			E[i]=1;
			while ( j ) {
				int la=j&-j;
				j^=la;
				E[i]+=p[__builtin_ctz( la )]*E[i^la];
			}
			E[i]/=1-sum[i];
		}
		printf( "%.6f\n",E[0] );
	}
	return 0;
}
