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
int next[100015],n,m;
double E[100015];
int main() {
	int i,j;
	int u,v;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		if ( !n&&!m )break;
		memset( next,-1,sizeof next );
//		memset( E,0,sizeof E );
		for ( i=0; i<m; i++ ) {
			scanf( "%d%d",&u,&v );
			if ( ~next[u] )while ( 1 );
			next[u]=v;
		}
		for ( i=n-1; i>=0; i-- ) {
			if ( ~next[i] )E[i]=E[next[i]];
			else {
				E[i]=6;
				for ( j=1; j<=6; j++ )E[i]+=E[i+j];
				E[i]/=6;
			}
		}
		printf( "%.4lf\n",E[0] );
	}
	return 0;
}
/*
100000 13
1 7
2 7
3 7
4 7
5 7
6 7
7 14
8 100000
9 100000
10 100000
11 100000
12 100000
13 100000
*/
