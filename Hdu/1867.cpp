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
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;

char a[111111];
char b[111111];
LL mod = 1000000007;
LL llpow( LL a,LL x ) {
	LL ret=1;
	while ( x ) {
		if ( x&1 )ret=ret*a%mod;
		a=a*a%mod;
		x/=2;
	}
	return ret;
}
LL ha[111111];
int play( char *a,char *b ) {
	int la=strlen( a );
	int lb=strlen( b );
	int i;
	LL temp=0;
	for ( i=la-1; i>=0; i-- ) {
		temp=( temp+llpow( 29,la-1-i )*( a[i]-'a'+1 ) )%mod;
		ha[la-1-i]=temp;
	}
	temp=0;
	int s=0;
	for ( i=0; i<lb&&i<la; i++ ) {
		temp=( temp*29LL+b[i]-'a'+1 )%mod;
		if ( ha[i]==temp )s=i+1;
	}
	return la+lb-s;
}
int main() {
	int i,j;
	while ( ~scanf( "%s%s",a,b ) ) {
		int la=strlen( a );
		int lb=strlen( b );
		int ab=play( a,b );
		int ba=play( b,a );
		if ( ab<ba||((strcmp(a,b)<0&&ab==ba))) {
			int s=lb-ab+la;
			printf("%s",a);
			for(i=s;i<lb;i++)printf("%c",b[i]);
			printf("\n");
		}else {
			int s=la-ba+lb;
			printf("%s",b);
			for(i=s;i<la;i++)printf("%c",a[i]);
			printf("\n");
		}
	}
	return 0;
}
