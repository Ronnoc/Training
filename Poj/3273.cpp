#include <cstdio>
int x[100010],n,m;
int cut ( int d ) {
	int res=1,now=0,i;
	for ( i=1; i<=n; i++ ) {
		if ( now+x[i]<=d )
			now+=x[i];
		else {
			now=x[i];
			res++;
		}
	}
	return res;
}
int bfind ( int l,int r ) {
	while (r>=l) {
		if ( r-l<=1 ) {
			if ( cut ( l ) <=m )
				return l;
			if ( cut ( r ) <=m )
				return r;
			return -1;
		}
		int mid= ( l+r ) /2;
		if ( cut ( mid ) <=m )r=mid;
		else l=mid+1;
	}
	return -1;
}
int main() {
//	while ( scanf ( "%d%d",&n,&m ) !=EOF ) {
		scanf ( "%d%d",&n,&m );
		int i;
		for ( i=1; i<=n; i++ )
			scanf ( "%d",&x[i] );
		int xmax= 0;
		for ( i=1; i<=n; i++ )
			if ( xmax<x[i] )
				xmax=x[i];
		int sum=0;
		for ( i=1; i<=n; i++ )
			sum+=x[i];
		int l=xmax,r=sum;
		int ans=bfind ( l,r );
		printf ( "%d\n",ans );
//	}
	return 0;
}
