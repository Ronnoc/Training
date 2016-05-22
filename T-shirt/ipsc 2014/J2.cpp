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
bool can[1<<16];
set<int>S,SS;
set<int>::iterator it;
void show( int w ) {
	if ( w%3==0 )printf( "bad" );
	else if ( w%3==1 )printf( "good" );
	else printf( "ones" );
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int x=1;
	for ( i=0; i<15; i++ )x*=3;
	for ( j=0; j<x; j++ ) {
		int v=j,tp=0;
		int cnt=0;
		for ( i=0; i<15; i++ ) {
			if ( tp%3==v%3 )cnt++;
			tp/=3; v/=3;
		}
		if(cnt==5)S.insert(j);
	}
	while ( !S.empty() ) {
		printf("SZ:%d ~ ",S.SZ);
		int u=*S.begin();
		int tp=u;
		cout<<u<<endl;
		show( tp );
		tp/=3;
		for ( i=1; i<15; i++ ) {
			printf( " " );
			show( tp );
			tp/=3;
		}
		printf("\n");
		int w;
		scanf( "%d",&w );
		SS.clear();
		for ( it=S.OP; it!=S.ED; ++it ) {
			int v=*it;
			tp=u;
			int cnt=0;
			for ( i=0; i<15; i++ ) {
				if ( tp%3==v%3 )cnt++;
				tp/=3; v/=3;
			}
			if ( cnt==w )SS.insert( *it );
		}
		cout<<S.SZ<<"->"<<SS.SZ<<endl;
		S=SS;
		cout<<S.SZ<<endl;
	}
	return 0;
}
