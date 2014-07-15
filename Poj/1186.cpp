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
int p[33];
int n,M;
int llpow( int a,int b ) {
	int ret=1;
	while ( b ) {
		if ( b&1 )ret=ret*a%MOD;
		a=a*a%MOD;
		b/=2;
	}
	return ret;
}
void gao( int *P,int l,int r,int &np ) {
	int i,j,a;
	np=0;
	if ( r-l==1 )
		for ( i=1; i<=M; i++ )
			P[np++]=( k[l]*llpow( i,p[l] ) );
	else if ( r-l==2 )
		for ( i=1; i<=M; i++ )
			for ( j=1; j<=M; j++ )
				P[np++]=( k[l]*llpow( i,p[l] )+k[l+1]*llpow( j,p[l+1] ) );
	else
		for ( i=1; i<=M; i++ )
			for ( j=1; j<=M; j++ )
				for ( a=1; a<=M; a++ )
					P[np++]=( k[l]*llpow( i,p[l] )+k[l+1]*llpow( j,p[l+1] )+k[l+2]*llpow( a,p[l+2] ) );
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
//	while ( cin>>n>>M ) {
	cin>>n>>M;
	for ( i=0; i<n; i++ )cin>>k[i]>>p[i];
	int np=0,nq=0;
	if ( n==1 ) gao( P,0,1,np ),Q[nq++]=0;
	else if ( n==2 )gao( P,0,1,np ),gao( Q,1,2,nq );
	else if ( n==3 )gao( P,0,1,np ),gao( Q,1,3,nq );
	else gao( P,0,3,np ),gao( Q,3,n,nq );
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
