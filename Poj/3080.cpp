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

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;
set<string>S[11][66];
bool inner( string a,int k ) {
	return S[k][a.SZ].count( a )>0;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int T;
	cin>>T;
	for ( int CA=1; CA<=T; ++CA ) {
		int n;
		vector<string>L;
		string s;
		cin>>n;
		for ( i=0; i<n; i++ ) {cin>>s; L.PB( s );}
		string ans="";
		for ( i=0; i<L.SZ; i++ )for ( j=0; j<=L[i].SZ; j++ )S[i][j].clear();
		for ( i=0; i<L.SZ; i++ )for ( j=0; j<L[i].SZ; j++ )for ( int k=j; k<L[i].SZ; k++ )
					S[i][k-j+1].insert( L[i].substr( j,k-j+1 ) );
		for ( i=0; i<L[0].SZ; i++ )
			for ( j=max( ( int )ans.SZ,3 ); i+j<=L[0].SZ; j++ ) {
				string tmp=L[0].substr( i,j );
				int flag=1;
				for ( int k=1; k<L.SZ; k++ )if ( !inner( tmp,k ) ) {flag=0; break;}
				if ( flag )if ( j>ans.SZ )ans=tmp;
					else if ( j==ans.SZ&&tmp<ans )ans=tmp;
			}
		if ( ans.empty() )cout<<"no significant commonalities\n";
		else cout<<ans<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
