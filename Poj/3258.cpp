#include <cstdio>
#include <algorithm>
using namespace std;
int x[50010],l,n,m;
int del ( int d ) {
	int i;
	int last=0,ret=0;
	for ( i=1; i<=n; i++ ) {
		if(x[i]-last<d)ret++;//,printf("~%d ",x[i]);
		else last=x[i];
	}
	if(last&&x[n+1]-last<d)ret++;//,printf("!%d ",last);
//	printf("del(%d)=%d\n",d,ret);
	return ret;
}
int bfind(int l,int r){
	while(r>=l){
//			printf("%d %d\n",l,r);
		if(r-l<=1){
			if(del(r)<=m)return r;
			if(del(l)<=m)return l;
			return -1;
		}
		int mid=(l+r)/2;
		if(del(mid)>m)r=mid-1;
		else l=mid;
	}
	return -1;
}
int main() {
	int OFFL=0;
#ifndef ONLINE_JUDGE
	OFFL=1;
#endif
	while ( scanf ( "%d%d%d",&l,&n,&m ) !=EOF ) {
		int i,p;
		for ( i=1; i<=n; ++i ) 
			scanf ( "%d",&x[i] );
		x[0]=0;
		x[n+1]=l;
		sort ( x,x+n+2 );
		int ans=bfind ( 0,l );
		printf ( "%d\n",ans );
	}
	return 0;
}
