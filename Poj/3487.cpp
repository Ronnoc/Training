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
vector<string>m,f;
string L[33],R[33];
int gf[33];
int bf[33];
int rfs[33][33];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; ++CA ) {
		if(CA!=1)printf("\n");
		int n;
		scanf( "%d",&n );
		m.clear();
		f.clear();
		memset( gf,-1,sizeof gf );
		memset( bf,-1,sizeof bf );
		memset( rfs,0,sizeof rfs );
		for ( i=0; i<n; i++ ) {
			char s[5];
			scanf( "%s",s );
			m.PB( s );
		}
		for ( i=0; i<n; i++ ) {
			char s[5];
			scanf( "%s",s );
			f.PB( s );
		}
		for ( i=0; i<n; i++ )cin>>L[i];
		for ( i=0; i<n; i++ )cin>>R[i];
		while ( 1 ) {
			vector<int>G[33];
			for ( i=0; i<n; i++ )if ( gf[i]==-1 ) {
					for ( j=2; j<L[i].SZ; j++ ) {
						int id_girl=lower_bound( f.OP,f.ED,L[i].substr( j,1 ) )-f.OP;
						if ( !rfs[id_girl][i] ) {G[id_girl].PB( i ); break;}
					}
				}
			int flag=1;
			for ( i=0; i<n; i++ )if ( !G[i].empty() ) {
					flag=0;
					if ( bf[i]!=-1 )G[i].PB( bf[i] );
					gf[bf[i]]=-1;
					bf[i]=-1;
					int choice=G[i][0];
					string now=m[choice];
					for ( k=2; k<R[i].SZ; k++ )
						if ( R[i].substr( k,1 )==now )break;
					int mark=k;
					for ( j=0; j<G[i].SZ; j++ ) {
						rfs[i][G[i][j]]=1;
						string may=m[G[i][j]];
						for ( k=2; k<R[i].SZ; k++ )
							if ( R[i].substr( k,1 )==may )break;
						if ( k<mark ) {
							mark=k;
							now=may;
							choice=G[i][j];
						}
					}
					bf[i]=choice;
					gf[bf[i]]=i;
					rfs[i][bf[i]]=0;
				}
			if ( flag )break;
		}
		for(i=0;i<n;i++)cout<<m[i]<<" "<<f[gf[i]]<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
