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
LL f( LL u,LL A ) {
	LL B=A+u;
	LL C=( A*B+1 )/u;
	return B+C;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	LL A;
	while ( cin>>A ) {
		LL u;
		LL ans=( A*( A+1 )+1 )+A+1;
		for ( u=1; u*u<=A*A+1; u++ )if ( ( A*A+1 )%u==0 ) {
				cmin( ans,f( u,A ) );
				cmin( ans,f( ( A*A+1 )/u,A ) );
			}
		cout<<ans<<endl;
	}
	return 0;
}
