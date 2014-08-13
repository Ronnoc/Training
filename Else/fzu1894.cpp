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
char s[7];
char q[1000005][7];
int w[1000005];
int nextid,fi,la;
int Q[1000005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T;
	scanf( "%d",&T );
	while ( T-- ) {
		fi=0,la=0,nextid=0;
		int cnt=0;
		scanf( "%s",s );
		while ( scanf( "%s",s )!=EOF ) {
			if ( strcmp( s,"END" )==0 )break;
			if ( s[0]=='C' ) {
				scanf( "%s%d",q[nextid],&w[nextid] );
				while(la>fi&&w[Q[la-1]]<w[nextid])la--;
				Q[la]=nextid;
				nextid++,la++;
			} else if ( s[0]=='Q' ) {
				if(la==fi)printf("-1\n");
				else printf("%d\n",w[Q[fi]]);
			} else if ( s[0]=='G' ) {
				if(Q[fi]==cnt)fi++;
				cnt++;
			}
		}
	}
	return 0;
}
