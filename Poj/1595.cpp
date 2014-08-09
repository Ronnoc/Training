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
const int MXN = 2000+10;
bool notp[MXN];
int p[MXN],pn;
void shai( int n ) {
	pn=0,notp[0]=1;
	for ( int i=2; i<n; i++ ) {
		if ( !notp[i] )p[pn++]=i;
		for ( int j=0; j<pn&&i*p[j]<n; j++ ) {
			notp[i*p[j]]=1;
			if ( i%p[j]==0 )break;
		}
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n,c;
	shai( 2005 );
	int CA=0;
	while ( ~scanf( "%d%d",&n,&c ) ) {
		if ( CA++ )printf( "\n" );
		vector<int>L;
		L.PB( 1 );
		for ( i=0; p[i]<=n; i++ )L.PB( p[i] );
		int cnt=2*c;
		if ( L.size()%2==1 )cnt--;
		while ( L.SZ>cnt )L.erase( L.OP ),L.erase( --L.ED );
		printf( "%d %d:",n,c );
		for ( i=0; i<L.SZ; i++ )printf( " %d",L[i] );
		printf( "\n" );
	}
	return 0;
}
