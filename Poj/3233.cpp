#include <iostream>
#include <cstdio>
using namespace std;
int mod;
struct mtx {
	long long x[62][62];
	int n;
};

void show ( mtx out ) {
	int i,j;
	int n=out.n;
	for ( i=1; i<=n; i++ ) {
		for ( j=1; j<=n; j++ ) {
			if ( j!=1 )
				printf ( " " );
			printf ( "%d",out.x[i][j] );
		}
		printf ( "\n" );
	}
}

mtx mutip ( mtx a,mtx b ) {
	mtx ret;
	int n=ret.n=a.n;
	int i,j,k;
	for ( i=1; i<=n; i++ )
		for ( j=1; j<=n; j++ ) {
			long long &tp=ret.x[i][j]=0;
			for ( k=1; k<=n; k++ ) {
				tp+=a.x[i][k]*b.x[k][j];
				tp%=mod;
			}
		}
	return ret;
};
int main() {
	int OFFL=0;
#ifndef ONLINE_JUDGE
	OFFL=1;
#endif
	int n,k;
	while ( scanf ( "%d%d%d",&n,&k,&mod ) !=EOF ) {
		mtx a,res,z,tp,out;
		a.n=2*n;
		res.n=2*n;
		z.n=n;
		tp.n=n;
		out.n=n;
		int i,j;
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=n; j++ )
				scanf ( "%d",&z.x[i][j] );
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=n; j++ )
				a.x[i][j]= ( i==j ) ?1:0;
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=n; j++ )
				a.x[i][j+n]= ( i==j ) ?1:0;
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=n; j++ )
				a.x[i+n][j]=0;
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=n; j++ )
				a.x[i+n][j+n]=z.x[i][j];
		for ( i=1; i<=2*n; i++ )
			for ( j=1; j<=2*n; j++ )
				res.x[i][j]= ( i==j ) ?1:0;
//		show(res);
//		show(a);
		//k++;
		while ( k ) {
			if ( k&1 )
				res=mutip ( res,a );
			a=mutip ( a,a );
//			printf(">> %d :: \n",k);
			k/=2;
//			show(res);
//			show(a);
		}
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=n; j++ )
				tp.x[i][j]=res.x[i][j+n];
		out=mutip ( tp,z );
//		show(tp);
//		show(z);
		show ( out );
	}
	return 0;
}
