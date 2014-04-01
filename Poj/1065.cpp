#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> >L;
int main()
{
	int T,i,j;
	cin>>T;
	while ( T-- )
	{
		int n,x,y;
		L.clear();
		cin>>n;
		for ( i=1; i<=n; i++ )
		{
			cin>>x>>y;
			L.push_back( make_pair( x,y ) );
		}
		sort( L.begin(),L.end() );
//		for(i=0;i<L.size();i++)cout<<L[i].first<<" "<<L[i].second<<endl;
		int did[5010],res=0;
		for ( i=0; i<L.size(); i++ )
			did[i]=0;
		for ( i=0; i<L.size(); i++ )
		{
			if ( did[i] )
				continue;
//			cout<<i<<"+"<<endl;
			res++;
			int nx=L[i].first,ny=L[i].second;
			for ( j=i+1; j<L.size(); j++ )
			{
				if ( did[j] )
					continue;
				if ( L[j].first>=nx&&L[j].second>=ny )
				{
					did[j]=1;
					nx=L[j].first,ny=L[j].second;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
