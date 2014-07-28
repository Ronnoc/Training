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
vector<int>L[555],R[555];
int gf[555];
int bf[555];
int rfs[555][555];
vector<string>sl[555],sr[555];
int vm[555],vf[555];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n;
	while ( ~scanf( "%d",&n ) ) {
		m.clear();
		f.clear();
		memset( gf,-1,sizeof gf );
		memset( bf,-1,sizeof bf );
		memset( rfs,0,sizeof rfs );
		for ( i=0; i<n; i++ ) {
			sl[i].clear();
			L[i].clear();
			string name;
			cin>>name;
			m.PB( name );
			for ( j=0; j<n; j++ ) {
				cin>>name;
				sl[i].PB( name );
			}
		}
		for ( i=0; i<n; i++ ) {
			sr[i].clear();
			R[i].clear();
			string name;
			cin>>name;
			f.PB( name );
			for ( j=0; j<n; j++ ) {
				cin>>name;
				sr[i].PB( name );
			}
		}
		for ( i=0; i<n; i++ )for ( j=i+1; j<n; j++ ) {
				if ( m[i]>m[j] ) {
					vector<string>tmp=sl[i];
					sl[i]=sl[j];
					sl[j]=tmp;
					swap( m[i],m[j] );
				}
			}
		for ( i=0; i<n; i++ )for ( j=i+1; j<n; j++ ) {
				if ( f[i]>f[j] ) {
					vector<string>tmp=sr[i];
					sr[i]=sr[j];
					sr[j]=tmp;
					swap( f[i],f[j] );
				}
			}
		for ( i=0; i<n; i++ ) {
			memset( vm,0,sizeof vm );
			for ( j=0; j<n; j++ ) {
				int id=lower_bound( f.OP,f.ED,sl[i][j] )-f.OP ;
				while ( vm[id] )id++;
				vm[id]=1;
				L[i].PB( id );
			}
		}
		for ( i=0; i<n; i++ ) {
			memset( vf,0,sizeof vf );
			for ( j=0; j<n; j++ ) {
				int id=lower_bound( m.OP,m.ED,sr[i][j] )-m.OP ;
				while ( vf[id] )id++;
				vf[id]=1;
				R[i].PB( id );
			}
		}
		while ( 1 ) {
			vector<int>G[555];
			for ( i=0; i<n; i++ )if ( gf[i]==-1 ) {
					for ( j=0; j<L[i].SZ; j++ ) {
						int id_girl=L[i][j];
						if ( !rfs[id_girl][i] ) {G[id_girl].PB( i ); break;}
					}
				}
			int flag=1;
			for ( i=0; i<n; i++ )if ( !G[i].empty() ) {
					flag=0;
					if ( bf[i]!=-1 ) {
						G[i].PB( bf[i] );
						gf[bf[i]]=-1;
						bf[i]=-1;
					}
					int choice=-1;
					int mark=n+1;
					for ( j=0; j<G[i].SZ; j++ ) {
						rfs[i][G[i][j]]=1;
						for ( k=0; k<R[i].SZ; k++ )
							if ( R[i][k]==G[i][j] )break;
						if ( k<mark ) {
							mark=k;
							choice=G[i][j];
						}
					}
					bf[i]=choice;
					gf[bf[i]]=i;
					rfs[i][bf[i]]=0;
					G[i].clear();
				}
			if ( flag )break;
		}
		for ( i=0; i<n; i++ )cout<<m[i]<<" "<<f[gf[i]]<<endl;
		cout<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
