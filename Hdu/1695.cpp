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
const int MXN = 100000+10;
int mu[MXN], p[MXN], pn,phi[MXN];
bool flag[MXN];	//trueÎªºÏÊý
void init( int N ) {
	pn = 0;
	mu[1] = 1;
	for ( int i = 2; i < N; i++ ) {
		if ( !flag[i] ) {
			p[pn ++ ] = i;
			mu[i] = -1;
			phi[i]=i-1;
		}
		for ( int j = 0; j < pn && i * p[j] < N; j++ ) {
			flag[i * p [j]] = true;
			if ( i % p[j] == 0 ) {
				mu[i * p[j]] = 0;		phi[i * p[j]] = p[j] * phi[i];
				break;
			} else  mu[i * p[j]] = -mu[i],phi[i * p[j]] = ( p[j] - 1 ) * phi[i];
		}
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	init( 100005 );
	int a,b,c,d,k;
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; ++CA ) {
		scanf( "%d%d%d%d%d",&a,&b,&c,&d,&k );
		LL ans=0;
		if ( k ) {
			if ( d<b )swap( b,d );
			if ( a%k )a+=k-a%k;
			if ( c%k )c+=k-c%k;
			if ( b%k )b-=b%k;
			if ( d%k )d-=d%k;
			a/=k,b/=k,c/=k,d/=k;
			for ( i=a; i<=b; i++ )if ( mu[i] )
					ans+=mu[i]*1LL*( b/i )*( d/i );
			for ( i=a; i<=b; i++ )ans-=phi[i];
		}
		printf( "Case %d: %I64d\n",CA,ans );
	}
	return 0;
}
