#include <cstdio>
#include <iostream>
using namespace std;
long long sum[33333];
long long now[33333];
int bfind( int l,int r,int key,long long *sum )
{
	while ( r>=l )
	{
		if ( r-l==1 )
		{
			if ( sum[l]>=key )
				return l;
			if ( sum[r]>=key )
				return r;
			return -1;
		}
		int mid=( l+r )/2;
		if ( sum[mid]>=key )
			r=mid;
		else
			l=mid;
	}
}
int main()
{
	int OFFL=0;
#ifndef ONLINE_JUDGE
	OFFL=1;
#endif
	int i;
	sum[0]=now[0]=0;
	for ( i=1; i<=33000; i++ )
	{
		int t=0,tp=i;
		while ( tp )
		{tp/=10; t++;}
		now[i]=now[i-1]+t;
		sum[i]=sum[i-1]+now[i];
	}
	int T;
	for ( scanf( "%d",&T ); T; T-- )
	{
		int n;
		scanf( "%d",&n );
		int where=bfind( 1,33000,n,sum );
		int m=n-sum[where-1];
		int tp=bfind( 1,33000,m,now );
		int b=m-now[tp-1];
		char s[20];
		sprintf( s,"%d",tp );
		printf( "%c\n",s[b-1] );
	}
	return 0;
}
