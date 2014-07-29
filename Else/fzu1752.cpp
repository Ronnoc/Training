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
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;
ULL mulMod( ULL A,ULL B,ULL C ) {
	ULL y=( ( long double )A*B )/C;
	LL ret=A*B-C*y;
	if ( ret<0 )ret+=C;
//	while ( B ) {
//		if ( B&1 ) {
//			ret+=A;
//			if ( ret>=C )ret-=C;
//		}
//		A<<=1,B>>=1;
//		if ( A>=C )A-=C;
//	}
	return ret;
}
ULL powMod( ULL A,ULL B,ULL C ) {
	ULL ret=1%C;
	A%=C;
	while ( B ) {
		if ( B&1 )ret=mulMod( ret,A,C );
		A=mulMod( A,A,C );
		B>>=1;
	}
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	ULL A,B,C;
	while ( scanf( "%I64u%I64u%I64u",&A,&B,&C )!=EOF )
		printf( "%I64u\n",powMod( A,B,C ) );
	return 0;
}
