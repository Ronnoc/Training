#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int x[10010];
int p[10010];
int main() {
	int n;
	while ( scanf( "%d",&n )!=EOF&&n ) {
		vector<pair<int,int> >L;
		int i,j,y,v[10010]= {0};
		long long res=0;
		for ( i=0; i<n; i++ ) {
			scanf( "%d",&y );
			x[i]=y;
			L.push_back( make_pair( y,i ) );
		}
		stable_sort( L.begin(),L.end() );
		for ( i=0; i<L.size(); i++ )
			p[L[i].second]=i;
		for ( i=0; i<n; i++ )
			if ( !v[i] ) {
				int mn=int(1e8);
				int tot=0;
				for ( j=0,y=i; !v[y=p[y]]; ++j ) {
					v[y]=1;
					mn=min(mn,x[y]);
					tot+=x[y];
				}
//				cout<<tot<<" "<<mn<<" "<<j<<endl;
//				cout<<max(0,tot-mn+(j-1)*mn)<<" "<<L[0].first*j+tot<<endl;
				res+=min( max(0,tot+(j-2)*mn) , L[0].first*(j+1)+tot+mn );
			}
		cout<<res<<endl;
	}
	return 0;
}

/*
1 8 9 7 6 0
6 8 9 7 1 +7=7
6 8 1 7 9 +10=17
6 8 7 1 9 +8=25
6 1 7 8 9 +9=34
1 6 7 8 9 +7=41
*/
