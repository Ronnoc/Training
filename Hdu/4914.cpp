#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
#define cmax(x,y) x=max(x,y)
typedef int LL;
const LL MOD = 119;
const double PI = acos( -1. );
int mx;
double ax[88888],ay[88888];
double bx[88888],by[88888];
double ansx[88888],ansy[88888];
LL f[66][88888],F[66];
LL D[2][88888],l[66],r[66],t[88888],g[88888];
int revv( int x,int mask ) {
	int ret=0;
	for ( int i=0; i<mask; i++ ) {
		ret<<=1;
		ret|=x&1;
		x>>=1;
	}
	return ret;
}
void fft( double * rl, double * ig, int n, bool sign ) {
	int d=0;
	while ( ( 1<<d ) <n ) ++d;
	for ( int i=0; i<n; i++ ) {
		int j=revv( i,d );
		if ( i<j ) swap( rl[i],rl[j] ),swap( ig[i],ig[j] );
	}
	for ( int m=2; m<=n; m<<=1 ) {
		int mh=m>>1;
		double _wr=cos( 2*PI/m ),_wi=sin( 2*PI/m );
		if ( sign ) _wi*=-1.0;
		for ( int i=0; i<n; i+=m ) {
			double wr=1,wi=0;
			for ( int j=i; j<mh+i; j++ ) {
				int k=j+mh;
				double er=rl[k]*wr-ig[k]*wi;
				double ei=rl[k]*wi+ig[k]*wr;
				double cr=rl[j],ci=ig[j];
				rl[j]+=er,ig[j]+=ei;
				rl[k]=cr-er,ig[k]=ci-ei;
				double qr=wr*_wr-wi*_wi;
				double qi=wr*_wi+wi*_wr;
				wr=qr,wi=qi;
			}
		}
	}
	if ( sign ) for ( int i=0; i<n; i++ )
			rl[i]/=n,ig[i]/=n;
}
int fftmultiply( LL *a,int la,LL *b,int lb,LL *ans ) {
	int lans=max( la,lb ),ln=0,i;
	while ( ( 1<<ln ) <lans ) ++ln;
	lans=2<<ln;
	for ( i=0; i<lans; i++ )
		ax[i]=i<la?a[i]:0,ay[i]=0;
	fft( ax,ay,lans,0 );
	for ( i=0; i<lans; i++ )
		bx[i]=i<lb?b[i]:0,by[i]=0;
	fft( bx,by,lans,0 );
	for ( i=0; i<lans; i++ ) {
		ansx[i]=ax[i]*bx[i]-ay[i]*by[i];
		ansy[i]=ax[i]*by[i]+ay[i]*bx[i];
	}
	fft( ansx,ansy,lans,1 );
	for ( i=0; i<lans; i++ )
		ans[i]=ansx[i]+0.5;
	return lans;
}
void BJuan( LL *a,LL *b,LL *c ) {
	int j,k;
	for ( j=0; j<mx; j++ )if ( b[j] )
			for ( k=0; k<mx; k++ )if ( c[k] )
					a[j+k]+=b[j]*c[k]%MOD;
}
void Juan( LL *c,LL *a,LL *b ) {
	fftmultiply( a,mx,b,mx,c );
}
int a,b,p,q;
void Move( LL *a ) {
	int j,k;
	for ( j=mx<<1; j>=mx; j-- )if ( a[j] ) {
			if ( a[j]>=MOD )a[j]%=MOD;
			a[j-p]+=a[j]*f[0][mx-p];
			a[j-q]+=a[j]*f[0][mx-q];
//			for ( k=0; k<mx; k++ )if ( f[0][k] )
//					a[j-mx+k]+=a[j]*f[0][k]%MOD;
		}
	for ( j=0; j<mx; j++ )if ( a[j]>=MOD )a[j]%=MOD;
}
LL gao( int N ) {
	int i,j,s;
	mx=max( p,q )+1;
	memset( f,0,sizeof f );
	memset( g,0,sizeof g );
	a%=MOD,b%=MOD;
	for ( i=0; i<=mx; i++ ) {
		if ( i<=0 )g[i]=1;
		else {
			if ( i>=p )g[i]+=a*g[i-p]%MOD;
			else g[i]+=a;
			if ( i>=q )g[i]+=b*g[i-q]%MOD;
			else g[i]+=b;
		}
	}
	f[0][mx-p]=a;
	f[0][mx-q]=b;
	for ( F[0]=mx,i=0; F[i]<=N; i++ ) {
		F[i+1]=F[i]<<1;
		Juan( f[i+1],f[i],f[i] );
		Move( f[i+1] );
	}
//	for ( i=0; i<=mx; i++ )cout<<g[i]<<" ";
//	cout<<endl;
	if ( N<=mx )return g[N];
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
	return ans%MOD;
}
int main() {
//	freopen( "1004.in","r",stdin );
//	freopen( "m1004.out","w",stdout );
	int s,i,j,k;
	LL N;
	while ( ~scanf( "%I64d",&N ) ) {
		scanf( "%d%d%d%d",&a,&b,&p,&q );
		cout<<gao( N )<<endl;
	}
	return 0;
}
