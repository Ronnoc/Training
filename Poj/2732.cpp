#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace std;
#define PB push_back
vector<string>L;
vector<string>S[1005];
vector<string>T;
int f[1005];
int fa[1005][1005];
int sum[1005];
int main() {
	int n,m,i,j;
	int TT,CA;
	scanf( "%d",&TT );
	for ( CA=1; CA<=TT; CA++ ) {
		if ( CA!=1 )cout<<"\n";
		scanf( "%d%d",&n,&m );
		if ( m>1001 )m=1001;
		L.clear();
		T.clear();
		for ( i=0; i<n; i++ ) {
			char s[11];
			scanf( "%s",s );
			L.PB( string( s ) );
			T.PB( string( s ) );
			int cnt;
			scanf( "%d",&cnt );
			S[i].clear();
			while ( cnt-- ) {
				scanf( "%s",s );
				L.PB( string( s ) );
				S[i].PB( string( s ) );
			}
		}
		sort( L.begin(),L.end() );
		L.erase( unique( L.begin(),L.end() ),L.end() );
		memset( fa,-1,sizeof fa );
		memset( f,-1,sizeof f );
		for ( i=0; i<n; i++ ) {
			int u=lower_bound( L.begin(),L.end(),T[i] )-L.begin();
			for ( j=0; j<S[i].size(); j++ ) {
				int v=lower_bound( L.begin(),L.end(),S[i][j] )-L.begin();
				fa[1][v]=u;
				f[v]=u;
//				cout<<L[v]<<v<<"'f"<<L[u]<<u<<endl;
			}
		}
		for ( i=1; i<m; i++ )for ( j=0; j<L.size(); j++ )if ( fa[i][j]!=-1 )
					fa[i+1][j]=f[ fa[i][j] ];
		memset( sum,0,sizeof sum );
		for ( i=0; i<L.size(); i++ )if ( fa[m][i]!=-1 )sum[fa[m][i]]++;
		vector<pair<int,string> >G;
		for ( i=0; i<L.size(); i++ )if ( sum[i] )G.PB( make_pair( -sum[i],L[i] ) );
		sort( G.begin(),G.end() );
		int b=0;
		if ( G.size()>=3 )b=-G[2].first;
		cout<<"Tree "<<CA<<":\n";
		for ( i=0; i<G.size(); i++ )if ( -G[i].first>=b )
				cout<<G[i].second<<" "<<-G[i].first<<"\n";
	}
	return 0;
}
