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
int dp[1111][1111];
int pre[1111];
int a[1111];
int solve( int l,int r ) {
	int &tp=dp[l][r];
	if ( ~tp )return tp;
	if ( l==r )return tp=a[l];
	if ( l>r ) return tp=0;
	int lp,rp,lq,rq;
	int wp=max( a[l+1],a[r] ),wq=max( a[l],a[r-1] );
	if ( a[l+1]>=a[r] )lp=l+2,rp=r;
	else lp=l+1,rp=r-1;
	if ( a[l]>=a[r-1] )lq=l+1,rq=r-1;
	else lq=l,rq=r-2;
	return tp=max( solve( lp,rp )+a[l]-wp,solve( lq,rq )+a[r]-wq );
}
int main() {
	int CA=0;
	int n,m,i,j;
	while ( ~scanf( "%d",&n ) ) {
		if ( !n )break;
		CA++;
		for ( i=1; i<=n; i++ )scanf( "%d",&a[i] );
		pre[0]=0;
		for ( i=1; i<=n; i++ )pre[i]=pre[i-1]+a[i];
		memset( dp,-1,sizeof dp );
		printf( "In game %d, the greedy strategy might lose by as many as %d points.\n",CA,solve( 1,n ) );
	}
	return 0;
}
