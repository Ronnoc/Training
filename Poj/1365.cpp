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
bool notp[500007];
int p[500007],pn;
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
vector<PII>L,R;
LL llpow( LL a,LL b,LL m ) {
	a%=m;
	LL ret=1;
	while ( b ) {if ( b&1 )ret=ret*a%m; a=a*a%m; b/=2;}
	return ret;
}
bool check( int P ) {
	int now=1;
	for ( int j=0; j<L.SZ; j++ )now=now*llpow( L[j].AA,L[j].BB,P )%P;
	now=( now+P-1 )%P;
	return now==0;
}
char s[11111];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,x,y;
	shai( 32768 );
	while ( gets( s )!=NULL ) {
		string ss=s;
		istringstream sin( ss );
		L.clear();
		R.clear();
		LL n=1;
		while ( sin>>x ) {
			if ( !x )return 0;
			sin>>y;
			L.PB( MP( x,y ) );
			n*=llpow( x,y,1LL<<62 );
		}
		n--;
		for ( i=0; i<pn&&p[i]*p[i]<=n; i++ ) {
			int cnt=0;
			while ( n%p[i]==0 )n/=p[i],cnt++;
			if ( cnt )R.PB( MP( p[i],cnt ) );
		}
		if ( n>1 )R.PB( MP( n,1 ) );
		reverse( R.OP,R.ED );
		if ( !R.empty() ) {
			printf( "%d %d",R[0].AA,R[0].BB );
			for ( i=1; i<R.SZ; i++ )printf( " %d %d",R[i].AA,R[i].BB );
		}
		printf( "\n" );
	}
}
