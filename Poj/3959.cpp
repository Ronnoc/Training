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

char s[222];
vector<string>L[1010];
string A[1010];
int main() {
	int i,j;
//	freopen( "alignment.in", "r", stdin );
//	freopen( "alignment.out", "w", stdout );
	int id=0;
	while ( gets( s )!=NULL ) {
		istringstream sin( s );
		string a;
		while ( sin>>a )L[id].PB( a );
		id++;
	}
	int mx=0;
	for ( i=0; i<id; i++ )cmax( mx,( int )L[i].SZ );
	for ( i=0; i<mx; i++ ) {
		int len=0;
		for ( j=0; j<id; j++ )if ( i<L[j].SZ )cmax( len,( int )L[j][i].SZ );
		for ( j=0; j<id; j++ )if ( i<L[j].SZ ) {
				int cnt=1+len-L[j][i].SZ;
				A[j]+=L[j][i];
				if ( i+1!=L[j].SZ )while ( cnt-- )A[j]+=" ";
			}
	}
	for ( i=0; i<id; i++,printf( "\n" ) )
		for ( j=0; j<A[i].SZ; j++ )printf( "%c",A[i][j] );
	return 0;
}
/*
  start:  integer;    // begins here
stop: integer; //  ends here
 s:  string;
c:   char; // temp
*/
