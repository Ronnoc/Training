#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
double pow2( double x ) {return x*x;}
int main() {
	int OFFL=0;
#ifndef ONLINE_JUDGE
	OFFL=1;
#endif
	int n,d;
	int T=0;
	while ( scanf( "%d%d",&n,&d )!=EOF ) {
		if ( !n&&!d )
			break;
		int x[1010],y[1010];
		for ( int i=1; i<=n; i++ )
			scanf( "%d%d",&x[i],&y[i] );
		int jump=0,i;
		for ( int i=1; i<=n; i++ )
			if ( y[i]>0 && y[i]>d )
				jump=1;
		printf( "Case %d: ",++T );
		if ( jump ) {
			printf( "-1\n" );
			continue;
		}
		vector<pair<double,double> >L;
		int clr[2010];
		for ( i=1; i<=n; i++ ) {
			double l=sqrt( d*d-y[i]*y[i] );
			L.push_back( make_pair( -( x[i]-l ),( x[i]+l ) ) );
		}
		sort( L.begin(),L.end() );
		for ( i=0; i<L.size(); i++ )
			L[i].first=-L[i].first;
		int res=L.size();
		double ll=L[0].first;
		for ( i=1; i<L.size(); i++ )
			if ( L[i].second>=ll )
				res--;
			else
				ll=L[i].first;
		printf( "%d\n",res );
	}
	return 0;
}
