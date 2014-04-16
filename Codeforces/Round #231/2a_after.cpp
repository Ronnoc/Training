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
int play( int a,int b,int c ) {
	if ( a<1 )return 0;
	if ( b<1 )return 0;
	if ( c<1 )return 0;
	while ( a-- )cout<<'|';
	cout<<'+';
	while ( b-- )cout<<'|';
	cout<<'=';
	while ( c-- )cout<<'|';
	cout<<endl;
	return 1;
}
int main() {
	int i,j;
	char s[333];
	while ( ~scanf( "%s",s ) ) {
		int a=0,b=0,c=0;
		for ( i=0; s[i]!='+'; i++,a++ );
		for ( i++; s[i]!='='; i++,b++ );
		for ( i++; s[i]; i++,c++ );
		if ( a+b==c ) {
			play( a,b,c );
		} else if ( a+1+b==c-1 ) {
			play( a+1,b,c-1 );
		} else if ( a+b-1==c+1 ) {
			if ( play( a,b-1,c+1 ) );
			else if ( play( a-1,b,c+1 ) );
			else printf( "Impossible\n" );
		} else printf( "Impossible\n" );
	}
	return 0;
}
