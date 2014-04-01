#include <cstdio>
int isp[1000010];
void make_prime()
{
	int i,j;
	isp[1]=0;
	for ( i=2; i<=1000000; i++ )
		isp[i]=1;
	for ( i=2; i<=1000000; i++ )
		if ( isp[i] )
			for ( j=2; j*i<=1000000; j++ )
				isp[i*j]=0;
}
int main()
{
	make_prime();
	int a,d,n;
	while ( scanf( "%d%d%d",&a,&d,&n )!=EOF )
	{
		if ( !a&&!d&&!n )
			break;
		while ( n-- ){
			while ( !isp[a] )
				a+=d;a+=d;}a-=d;
		printf( "%d\n",a );
	}
	return 0;
}
