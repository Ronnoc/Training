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
int main() {
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int n;
		double x;
		vector<double>L,R,S;
		L.clear(),R.clear(),S.clear();
		scanf( "%d",&n );
		for ( i=1; i<=n; i++ ) {
			scanf( "%lf",&x );
			L.PB( x );
			S.PB( x );
		}
		SORT( L );
		for ( i=1; i<=n; i++ ) {
			scanf( "%lf",&x );
			R.PB( x );
			S.PB( x );
		}
		SORT( R );
		SORT( S );
		bool vl[1005];
		bool vr[1005];
		memset( vl,0,sizeof vl );
		memset( vr,0,sizeof vr );
		int cl=0,cr=0;
		for ( i=0; i<R.SZ; i++ ) {
			int got=0;
			for ( j=L.SZ-1; j>=0; j-- )if ( !vl[j]&&L[j]<R[i] ) {
					got=1;
					vl[j]=vr[i]=1;
//					cout<<R[i]<<" "<<L[j]<<endl;
					break;
				}
			if ( !got ) {
				j=L.SZ-1;
				while ( vl[j] )j--;
				vl[j]=vr[i]=1;
//				cout<<R[i]<<" "<<L[j]<<endl;
				cl++;
			}
		}
		memset( vl,0,sizeof vl );
		memset( vr,0,sizeof vr );
		for ( i=0; i<L.SZ; i++ ) {
			int got=0;
			for ( j=R.SZ-1; j>=0; j-- )if ( !vr[j]&&R[j]<L[i] ) {
					got=1; vr[j]=vl[i]=1,cr++;
//					cout<<R[j]<<" "<<L[i]<<endl;
					break;
				}
			if ( !got ) {
				j=R.SZ-1;
				while ( vr[j] )j--;
				vr[j]=vl[i]=1;
//				cout<<R[j]<<" "<<L[i]<<endl;
			}
		}
		printf( "Case #%d: %d %d\n",CASE,cr,cl );
	}
	return 0;
}
