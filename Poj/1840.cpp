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
int P[3375005];
int Q[3375005];
int k[33];
int n,M;
int llpow( int a,int b ) {
	int ret=1;
	while ( b ) {
		if ( b&1 )ret=ret*a;
		a=a*a;
		b/=2;
	}
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,a;
//	while ( cin>>n>>M ) {
//	cin>>n>>M;
	n=5,M=100;
	for ( i=0; i<n; i++ )cin>>k[i];
	int np=0,nq=0;
	for ( i=0; i<=M; i++ )if ( i!=50 )
			for ( j=0; j<=M; j++ )if ( j!=50 )
					P[np++]=( k[0]*llpow( i-50,3 )+k[1]*llpow( j-50,3 ) );
	for ( i=0; i<=M; i++ )if ( i!=50 )
			for ( j=0; j<=M; j++ )if ( j!=50 )
					for ( a=0; a<=M; a++ )if ( a!=50 )
							Q[nq++]=( k[2]*llpow( i-50,3 )+k[3]*llpow( j-50,3 )+k[4]*llpow( a-50,3 ) );
	int ans=0;
	sort( P,P+np );
	sort( Q,Q+nq );
	int iq=nq-1;
	for ( i=0; i<np; ) {
		int l=i;
		while ( P[i]==P[l] )i++;
		while ( iq>=0&&Q[iq]>-P[l] )iq--;
		if ( iq<0 )break;
		if ( Q[iq]+P[l]!=0 )continue;
		int rq=iq;
		while ( Q[iq]==Q[rq] )iq--;
		ans+=( rq-iq )*( i-l );
	}
	cout<<ans<<endl;
//	}
	return 0;
}
