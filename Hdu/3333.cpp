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

int a[33333];
LL ans[111111];
int main() {
	int i,j;
	int T;
	scanf( "%d",&T );
	while ( T-- ) {
		int n;
		scanf( "%d",&n );
		for ( i=1; i<=n; i++ )scanf( "%d",&a[i] );
		int tong=sqrt( 1.0*n );
		vector<pair<PII,int> >Q[200];
		memset( ans,-1,sizeof ans );
		int qq;
		scanf( "%d",&qq );
		for ( i=1; i<=qq; i++ ) {
			int l,r;
			scanf( "%d%d",&l,&r );
			Q[r/tong].PB( MP( MP( l,r ),i ) );
		}
		map<int,int>M;
		LL now=0;
		int p=0,q=0;
		for ( i=0; i<200; i++ ) {
			if ( Q[i].empty() )continue;
			SORT( Q[i] );
			for ( j=0; j<Q[i].SZ; j++ ) {
				int l=Q[i][j].AA.AA,r=Q[i][j].AA.BB,id=Q[i][j].BB;
				while ( q<r ) {
					q++;
					int tot=++M[a[q]];
					if ( tot==1 )now+=a[q];
				}
				while ( q>r ) {
					int tot=--M[a[q]];
					if ( tot==0 )now-=a[q];
					q--;
				}
				while ( p<l ) {
					int tot=--M[a[p]];
					if ( tot==0 )now-=a[p];
					p++;
				}
				while(p>l){
					p--;
					int tot=++M[a[p]];
					if ( tot==1 )now+=a[p];
				}
				ans[id]=now;
			}
		}
		for ( i=1; i<=qq; i++ )printf( "%I64d\n",ans[i] );
	}
	return 0;
}
