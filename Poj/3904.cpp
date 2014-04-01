#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define N 10010
vector<int>G[N];
vector<int>p;
int tot[N];
int ocur[N];
int a[N];
int isp[N];
int sign[N];
long long cmb[10010][5];
void ini_cmb()
{
	cmb[1][0]=1;
	cmb[1][1]=1;
	int i,j;
	for ( i=2; i<=10000; i++ )
	{
		cmb[i][0]=1;
		for ( j=1; j<=min( 4,i-1 ); j++ )
			cmb[i][j]=cmb[i-1][j-1]+cmb[i-1][j];
		if ( i<=4 )
			cmb[i][i]=1;
	}
}
int main()
{
	int i,j;
	for ( i=2; i<=10000; i++ )
		isp[i]=1;
	for ( i=1; i<=10000; i++ )
	{
		if ( isp[i] )
		{
			p.push_back( i );
			for ( j=2; j*i<=10000; j++ )
				isp[i*j]=0;
			for ( j=1; j*i<=10000; j++ )
				sign[i*j]++;
		}
		for ( j=1; j*i<=10000; j++ )
			G[i*j].push_back( i );
	}
	ini_cmb();
	int n;
	while ( scanf( "%d",&n )!=EOF )
	{
		for ( i=1; i<=n; i++ )
			scanf( "%d",&a[i] );
		int mx=0;
		for ( i=1; i<=n; i++ )
			if ( a[i]>mx )
				mx=a[i];
		for ( i=1; i<=mx; i++ )
			ocur[i]=tot[i]=0;
		for ( i=1; i<=n; i++ )
			tot[a[i]]++;
		for ( i=1; i<=mx; i++ )
			if ( tot[i] )
				for ( j=0; j<G[i].size(); j++ )
					ocur[G[i][j]]+=tot[i];
		for(i=0;i<p.size();i++){
			int tp=p[i]*p[i];
			if(tp>mx)continue;
			for(j=1;j*tp<=mx;j++)ocur[j*tp]=0;
		}
		long long res=cmb[n][4];
		for ( i=2; i<=mx; i++ )
		{
			int s=sign[i]&1?-1:1;
			res+=cmb[ocur[i]][4]*s;
		}
		printf( "%I64d\n",res );
	}
	return 0;
}
