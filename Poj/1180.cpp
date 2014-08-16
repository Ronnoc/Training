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
LL D[10010],X[10010],Y[10010];
int T[10010],F[10010];
int N,C;
int sv[10010];
int dq[10010],op,ed;
LL cal( int x,int y ) {
	LL ret=D[y]-F[N]*C+F[y]*( C+T[x]-T[y] );
	return ret;
}
int slope( LL X,LL Y,LL P,LL Q ) {
	if ( P*Y<X*Q )return -1;
	return P*Y>X*Q;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while ( ~scanf( "%d",&N ) ) {
		scanf( "%d",&C );
		for ( i=1; i<=N; i++ )scanf( "%d%d",&T[i],&F[i] );
		for ( i=1; i<=N; i++ )T[i]+=T[i-1];
		for ( i=1; i<=N; i++ )F[i]+=F[i-1];
		op=ed=0;
		dq[ed++]=0;
		for ( i=1; i<=N; i++ ) {
			while ( ed-op>=2 ) {
				int l=dq[op],r=dq[op+1];
				if ( slope( X[r]-X[l],Y[r]-Y[l],1,C+T[i] )<=0 )op++;
				else break;
			}
			D[i]=cal( i,dq[op] );
			X[i]=F[i];
			Y[i]=1LL*F[i]*T[i]-D[i];
			while ( ed-op>=2 ) {
				int l=dq[ed-2],r=dq[ed-1];
				if ( slope( X[r]-X[l],Y[r]-Y[l],X[i]-X[r],Y[i]-Y[r] )>=0 )ed--;
				else break;
			}
			dq[ed++]=i;
		}
		LL ans=F[N]*T[N];
		printf( "%I64d\n",ans-D[N] );
	}
	return 0;
}
