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
const double PI=acos ( -1. );
const LL MOD = 1000000007;

int eulerPhi ( int n ) {
	int res = n;
	for ( int i = 2; i * i <= n; i++ )		//可用质数加速
		if ( n % i == 0 ) {
			res = res / i * ( i - 1 );
			for ( ; n % i == 0; n /= i );
		}
	if ( n != 1 ) res = res / n * ( n - 1 );
	return res%MOD;
}
const int MAX_N = 5000001;
int euler[MAX_N+5];
void tableEuler ( int n ) {
	for ( int i = 0; i < n; i++ )
		euler[i] = i;
	for ( int i = 2; i < n; i++ )
		if ( euler[i] == i )
			for ( int j = i; j < n; j += i ) euler[j] = euler[j] / i * ( i - 1 );
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	tableEuler(MAX_N);
	while ( ~scanf ( "%d",&n ) ) {
		LL ans=1;
		for(i=1;i<=n;i++){
			int w;
			scanf("%d",&w);
			if(w<MAX_N)ans=ans*euler[w]%MOD;
			else ans=ans*eulerPhi(w)%MOD;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
