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
int vis[1111111];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; ++CA ) {
		scanf( "%d",&n );
		vector<int>L;
		for ( i=1; i<=n; i++ ) {
			scanf( "%d",&k );
			L.PB( k );
		}
		int m;
		for ( m=1;; m++ ) {
			for ( j=0; j<m; j++ )vis[j]=0;
			for ( i=0; i<n; i++ ) {
				int w=L[i]%m;
				if ( vis[w] )break;
				vis[w]=1;
			}
			if ( i==n )break;
		}
		cout<<m<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
