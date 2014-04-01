#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int OFFL=0;
#ifndef ONLINE_JUDGE
	OFFL=1;
#endif
	int T;
	for ( cin>>T; T--; )
	{
		int n;
		cin>>n;
		int x[1010],y[1010],i,j;
		for ( i=1; i<=n; i++ )
			cin>>x[i]>>y[i];
		int h[210];
		for ( i=1; i<=200; i++ )
			h[i]=0;
		for ( i=1; i<=n; i++ )
		{
			int l=min( ( x[i]+1 )/2,( y[i]+1 )/2 );
			int r=max( ( x[i]+1 )/2,( y[i]+1 )/2 );
			for ( j=l; j<=r; j++ )
				h[j]++;
		}
		int ans=0;
		for ( i=1; i<=200; i++ )
			ans=max( ans,h[i] );
		cout<<ans*10<<endl;
	}
	return 0;
}
