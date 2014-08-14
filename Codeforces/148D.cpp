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
double dp[1005][1005];
bool vis[1005][1005];
double solve( int w,int b ) {
	if(vis[w][b])return dp[w][b];
	vis[w][b]=1;
	double &tp=dp[w][b];
	tp=0;
	if(!w)return tp;
	tp+=1.0*w/(w+b);
	double p=1.0*b/(w+b);
	if(!b)return tp;
	b--;
	double fw=1.0*w/(w+b);
	double fb=1.0*b/(w+b);
	if(!b)return tp;
	b--;
	if(w)tp+=p*fb*solve(w-1,b)*w/(w+b);
	if(b)tp+=p*fb*solve(w,b-1)*b/(w+b);
	return tp;
}
int main() {
	int i,j;
	int w,b;
	memset( vis,0,sizeof vis );
	while ( ~scanf( "%d%d",&w,&b ) ) {
		printf( "%.16f\n",solve( w,b ) );
	}
	return 0;
}
