#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define cmax(x,y) x=max(x,y)
typedef long long LL;
const LL MOD = 1000000007LL;
int _U,A[55];
int _D,B[55];
int mx;
LL dp[201],g[201];
LL f[66][401],F[66];
LL D[2][401],l[66],r[66],t[401];
void Juan( LL *a,LL *b,LL *c ) {
	int j,k;
	for ( j=0; j<mx; j++ )if ( b[j] )
			for ( k=0; k<mx; k++ )if ( c[k] )
					a[j+k]+=b[j]*c[k]%MOD;
}
void Move( LL *a ) {
	int j,k;
	for ( j=mx<<1; j>=mx; j-- )if ( a[j] ) {
			if ( a[j]>=MOD )a[j]%=MOD;
			for ( k=1; k<=_D; k++ )
				a[j-B[k]]+=a[j]*dp[B[k]]%MOD;
		}
	for ( j=0; j<mx; j++ )if ( a[j]>=MOD )a[j]%=MOD;
}
int main() {
	int s,i,j,k;
	LL N;
	while ( ~scanf( "%I64d",&N ) ) {
		for ( scanf( "%d",&_U ),i=1; i<=_U; i++ )scanf( "%d",&A[i] );
		for ( scanf( "%d",&_D ),i=1; i<=_D; i++ )scanf( "%d",&B[i] );
		for ( mx=1,i=1; i<=_D; i++ )cmax( mx,B[i] );
		for ( i=0; i<=mx; i++ )dp[i]=0;
		for ( dp[i=0]=1; i<=mx; i++ )if ( dp[i] ) {
				if ( dp[i]>=MOD )dp[i]%=MOD;
				for ( j=1; j<=_U; j++ )if ( i+A[j]<=mx )
						dp[i+A[j]]+=dp[i];
			}
		for ( i=0; i<=mx; i++ )g[i]=0;
		for ( g[i=0]=1; i<=mx; i++ )if ( g[i] ) {
				if ( g[i]>=MOD )g[i]%=MOD;
				for ( j=1; j<=_D; j++ )if ( i+B[j]<=mx )
						g[i+B[j]]+=g[i]*dp[B[j]]%MOD;
			}
		memset( f,0,sizeof f );
		for ( i=1; i<=_D; i++ )f[0][mx-B[i]]=dp[B[i]];
		for ( F[0]=mx,i=0; F[i]<=N; i++ ) {
			F[i+1]=F[i]<<1;
			Juan( f[i+1],f[i],f[i] );
			Move( f[i+1] );
		}
		if ( N<=mx )printf( "%I64d\n",g[N] );
		else {
			for ( s=0; N>=F[s]; s++ );
			l[0]=N-mx+1,r[0]=N;
			memset( D[0],0,sizeof D[0] );
			D[0][mx-1]=1;
			int x=0,y=1;
			while ( s-- ) {
				if ( l[x]>=F[s] ) {
					l[y]=l[x]-F[s],r[y]=r[x]-F[s];
					memset( D[y],0,sizeof D[y] );
					Juan( D[y],D[x],f[s] );
					Move( D[y] );
					swap( x,y );
				}
			}
			memset( t,0,sizeof t );
			for ( i=l[x]; i<=r[x]; i++ )t[i]=D[x][i-l[x]];
			Move( t );
			LL ans=0;
			for ( i=0; i<mx; i++ )ans+=t[i]*g[i]%MOD;
			printf( "%I64d\n",ans%MOD );
		}
	}
	return 0;
}
