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
LL F[99];
LL T[99];
LL S[99];
string ans;
void solve( int n,int m ) {
	int cnt=0;
	int l,r;
	for ( l=0; l<n; l++ ) {
		r=n-1-l;
		cnt+=T[l]*T[r];
		if ( cnt>=m )break;
	}
	cnt-=T[l]*T[r];
	m-=cnt;
	if ( l ) {
		ans+="(";
		solve( l,( m-1 )/T[r]+1 );
		ans+=")";
	}
	ans+="X";
	if ( r ) {
		ans+="(";
		solve( r,( m-1 )%T[r]+1 );
		ans+=")";
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	for ( T[0]=1,i=1; i<=50; i++ ) {
		T[i]=0;
		for ( j=0; j<i; j++ )T[i]+=T[j]*T[i-1-j];
	}
	for ( S[0]=0,i=1; i<=50; i++ )
		S[i]=S[i-1]+T[i];
	while ( scanf( "%d",&n )!=EOF&&n ) {
		ans.clear();
		int id;
		for ( id=1;; id++ )if ( S[id]>=n )break;
		solve( id,n-S[id-1] );
		cout<<ans<<endl;
	}
	return 0;
}
