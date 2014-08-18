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
const double PI=acos ( -1. );
const LL MOD = 9973;

int phi[50005], p[50005], pn;
bool flag[50005];	//trueÎªºÏÊý
void init ( int N ) {
	pn = 0;
	phi[1] = 1;
	for ( int i = 2; i < N; i++ ) {
		if ( !flag[i] ) {
			p[pn ++ ] = i;
			phi[i]=i-1;
		}
		for ( int j = 0; j < pn && i * p[j] < N; j++ ) {
			flag[i * p [j]] = true;
			if ( i % p[j] == 0 ) {
				phi[i * p[j]] = p[j] * phi[i];
				break;
			}
			else  phi[i * p[j]] = ( p[j] - 1 ) * phi[i];
		}
	}
}
vector<PII>Q;
vector<int>B;
map<int,int>TP;
int dt[33];
void dfs ( int h,int now ) {
	int i;
	if ( h==Q.SZ ) {
		B.PB ( now );
		if ( now>=50000 ) {
			int p=now;
			for ( i=0; i<h; i++ ) if ( dt[i] )
					p=p/Q[i].AA* ( Q[i].AA-1 );
			TP[now]=p;
		}
		else TP[now]= ( phi[now] );
		return;
	}
	for ( dt[h]=0,i=0; i<=Q[h].BB; i++ ) {
		dfs ( h+1,now );
		now*=Q[h].AA;
		dt[h]++;
	}
}
void gao ( int n ) {
	Q.clear(),B.clear(),TP.clear();
	for ( int j = 0; j<pn&&p[j] * p[j] <= n; j++ )
		if ( n % p[j] == 0 ) {
			int cnt=0;
			while ( n%p[j]==0 ) n/=p[j],cnt++;
			Q.PB ( MP ( p[j],cnt ) );
		}
	if ( n>1 ) Q.PB ( MP ( n,1 ) );
	dfs ( 0,1 );
}
LL extGcd ( LL a, LL b, LL &x, LL &y ) {
	LL ret = a;
	if ( b ) {
		ret = extGcd ( b, a % b, y, x );
		y -= ( a / b ) * x;
	}
	else x = 1, y = 0;
	return ret;
}
LL modInv ( LL a, LL m ) {
	LL x, y;
	extGcd ( a,m,x,y );
	return ( m+x%m ) %m;
}
int n,m;
int G[22][22];
struct mat {
	LL w[12][12];
	int n;
	mat ( int _n=0 ) :n ( _n ) {memset ( w,0,sizeof w );}
	void unit ( int _n ) {
		n=_n;
		memset ( w,0,sizeof w );
		for ( int i=0; i<n; i++ ) w[i][i]=1;
	}
	friend mat operator * ( mat A,mat B ) {
		mat ret ( A.n );
		for ( int i=0; i<A.n; i++ ) for ( int j=0; j<A.n; j++ ) if ( A.w[i][j] )
					for ( int k=0; k<A.n; k++ ) ret.w[i][k]+=A.w[i][j]*B.w[j][k];
		for ( int i=0; i<A.n; i++ ) for ( int j=0; j<A.n; j++ )
				ret.w[i][j]%=MOD;
		return ret;
	}
	friend mat operator + ( mat A,mat B ) {
		mat ret ( A.n );
		for ( int i=0; i<A.n; i++ ) for ( int j=0; j<A.n; j++ )
				ret.w[i][j]= ( A.w[i][j]+B.w[i][j] ) %MOD;
		return ret;
	}
	void output() {
		for ( int i=0; i<n; i++,puts ( "" ) ) {
			printf ( "%d", ( int ) w[i][0] );
			for ( int j=1; j<n; j++ ) printf ( " %d", ( int ) w[i][j] );
		}
	}
};
mat matPow ( mat A,int B ) {
	mat ret;
	ret.unit ( A.n );
	while ( B ) {
		if ( B&1 ) ret=ret*A;
		A=A*A;
		B>>=1;
	}
	return ret;
}
int solve ( int n ) {
	int i,j,k,t;
	int ret=0;
	mat A ( m );
	for ( i=0; i<m; i++ ) for ( j=0; j<m; j++ )
			A.w[i][j]=1-G[i+1][j+1];
	A=matPow ( A,n-1 );
	for ( i=1; i<=m; i++ ) for ( j=1; j<=m; j++ ) if ( !G[i][j] )
				ret+=A.w[i-1][j-1];
	return ret%MOD;
}
int main() {
	init ( 50000 );
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int T;
	scanf ( "%d",&T );
	while ( T-- ) {
		int k,a,b;
		memset ( G,0,sizeof G );
		scanf ( "%d%d%d",&n,&m,&k );
		while ( k-- ) {
			scanf ( "%d%d",&a,&b );
			G[a][b]=G[b][a]=1;
		}
		gao ( n );
		int ans=0;
		for ( i=0; i<B.SZ; i++ )
			ans+=TP[n/B[i]]%MOD*solve ( B[i] ) %MOD;
		ans%=MOD;
		ans*=modInv ( n,MOD );
		ans%=MOD;
		printf ( "%d\n",ans );
	}
	return 0;
}
