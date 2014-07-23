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
int x[222],y[222];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	while ( cin>>n ) {
		for ( i=0; i<n; i++ )cin>>x[i]>>y[i];
		int ans=0;
		for ( i=0; i<n; i++ ) {
			vector<PII>L;
			for ( j=0; j<n; j++ )if ( j!=i ) {
					int dx=x[j]-x[i];
					int dy=y[j]-y[i];
					if ( dx<0 )dx=-dx,dy=-dy;
					int g=__gcd( abs( dx ),abs( dy ) );
					dx/=g;
					dy/=g;
					L.PB( MP( dx,dy ) );
				}
			SORT( L );
			for ( j=0; j<L.SZ; ) {
				int l=j;
				while ( j<L.SZ&&L[j]==L[l] )j++;
				cmax( ans,j-l+1 );
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
