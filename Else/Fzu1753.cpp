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
int n[155],m[155];
int isp[100005];
int prime[100005],npm;
int solve( int w,int p ) {
	if ( w<p )return 0;
	return w/p+solve( w/p,p );
}
int main() {
	int i,j;
	int T;
	for ( i=2; i<=100000; i++ )isp[i]=i&1;
	for ( isp[2]=1,i=3; i<=100000; i+=2 )if ( isp[i] )
			for ( LL j=1LL*i*i; j<=100000; j+=i*2 )isp[j]=0;
	npm=0;
	for ( i=2; i<=100000; i++ )if ( isp[i] )prime[++npm]=i;
	while ( ~scanf( "%d",&T ) ) {
		int mxn=INF;
		for ( i=1; i<=T; i++ )scanf( "%d%d",&n[i],&m[i] );
		for ( i=1; i<=T; i++ )cmin( mxn,n[i] );
		LL ans=1;
		for ( i=1; i<=npm&&prime[i]<=mxn; i++ ) {
			int now=MOD;
			for ( j=1; j<=T; j++ ) {
				int tp=solve( n[j],prime[i] )-solve( m[j],prime[i] )-solve( n[j]-m[j],prime[i] );
				cmin( now,tp );
			}
			while(now--)ans*=prime[i];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
