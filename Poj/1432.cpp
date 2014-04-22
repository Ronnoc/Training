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
char mp[33][33] = {
	".-", "-...", "-.-.", "-..",
	".", "..-.", "--.", "....",
	"..", ".---", "-.-", ".-..",
	"--", "-.", "---", ".--.",
	"--.-", ".-.", "...", "-",
	"..-", "...-", ".--", "-..-",
	"-.--", "--.."
};
int what( char x ) {
	if ( x == '.' ) return 1;
	return 2;
}
char morse[10105];
int ndic;
char dic[10105][30];

int dp[10105];
LL H[10105][88];
map<LL,int>HD[88];
int main() {
	int i,j,k;
	int T;
	scanf( "%d",&T );
	while ( T-- ) {
		for ( i=1; i<=80; i++ )HD[i].clear();
		scanf( "%s",morse );
		for ( i=1; morse[i-1]; i++ )dp[i]=0;
		scanf( "%d",&ndic );
		for ( i=0; i<ndic; i++ ) {
			scanf( "%s",dic[i] );
			int ld=0;
			LL hh=0;
			for ( j=0; dic[i][j]; j++ )for ( k=0; mp[dic[i][j]-'A'][k]; k++ )
					hh=hh*3+what( mp[dic[i][j]-'A'][k] ),ld++;
			HD[ld][hh]++;
		}
		int len_morse=strlen( morse );
		for ( i=0; i<len_morse; i++ ) {
			for ( j=1; j<=80; j++ )if ( i+j-1<len_morse ) {
					H[i][j]=0;
					for ( k=i; k<i+j; k++ )H[i][j]=H[i][j]*3+what( morse[k] );
				}
		}
		dp[0]=1;
		for ( i=0; i<len_morse; i++ ) if ( dp[i] ) {
				for ( j=1; j<=80; j++ )if ( i+j-1<len_morse )
						dp[i+j]+=HD[j][H[i][j]]*dp[i];
			}
		printf( "%d\n",dp[len_morse] );
	}
	return 0;
}
