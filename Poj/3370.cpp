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
int a[111111];
int S[111111];
int pre[111111];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n,m;
	while ( ~scanf( "%d%d",&m,&n ) ) {
		if ( !n&&!m )break;
		memset( pre,-1,sizeof pre );
		for ( i=1; i<=n; i++ )scanf( "%d",&a[i] );
		for ( S[0]=0,i=1; i<=n; i++ )S[i]=( S[i-1]+a[i] )%m;
		int u,v;
		for ( i=0; i<=n; i++ ) {
			if ( pre[S[i]]==-1 )pre[S[i]]=i;
			else {
				u=pre[S[i]];
				v=i;
				break;
			}
		}
		printf( "%d",u+1 );
		for ( i=u+2; i<=v; i++ )printf( " %d",i );
		printf( "\n" );
	}
	return 0;
}
