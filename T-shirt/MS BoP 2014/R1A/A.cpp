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
double play( char *a ) {
	int len=strlen(a);
	char q=a[len-1];
	char p=a[len-2];
	char s[111];
	for ( int i=0; i<=len; i++ )s[i]=a[i];
	double ret;
	if ( p=='d' ) {
		sscanf( s,"%lfdm",&ret );
		return ret*100;
	}
	if ( p=='c' ) {
		sscanf( s,"%lfcm",&ret );
		return ret*10;
	}
	if ( p=='m' ) {
		sscanf( s,"%lfmm",&ret );
		return ret;
	}
	if ( p=='u' ) {
		sscanf( s,"%lfum",&ret );
		return ret/1000;
	}
	if ( p=='n' ) {
		sscanf( s,"%lfnm",&ret );
		return ret/1000000;
	}
	sscanf( s,"%lfm",&ret );
	return ret*1000;
}
int main() {
	int i,j;
	int T;
	scanf("%d",&T);
	for ( int CASE=1; CASE<=T; ++CASE ) {
		char A[111],B[111];
		double c;
		scanf("%s%s%lfpx",A,B,&c);
		double a=play( A );
		double b=play( B );
		printf( "Case %d: ",CASE );
		printf( "%.2lfpx\n",a*c/b );
	}
	return 0;
}
