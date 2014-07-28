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
char s[1000005];
bool v[1<<21];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; ++CA ) {
		scanf( "%s",s );
		int len=strlen( s );
		for ( k=1; k<=7; k++ ) {
			int all=1<<( k*3 );
			int now=0;
			if ( k>len ) {
				while ( k-- )putchar( 'A' );
				putchar( '\n' );
				break;
			}
			for ( i=0; i<k; i++ )now=( now<<3 )|( s[i]-'A' );
			for ( i=0; i<all; i++ )v[i]=0;
			v[now]=1;
			for ( i=k; i<len; i++ ) {
				now=( ( now<<3 )|( s[i]-'A' ) )&( all-1 );
				v[now]=1;
			}
			for ( i=0; i<all; i++ )if ( !v[i] )break;
			if ( i!=all ) {
				vector<char>A;
				for ( j=0; j<k; j++ ) {
					A.PB( i%8+'A' );
					i/=8;
				}
				reverse( A.OP,A.ED );
				for ( i=0; i<A.SZ; i++ )putchar( A[i] );
				putchar( '\n' );
				break;
			}
		}
		//printf("Case #%d:",CA);
	}
	return 0;
}
