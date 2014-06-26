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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
int st[111][2];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,p,q;
	int n;
	while ( cin>>n ) {
		string s[111];
		for ( i=0; i<n; i++ )cin>>s[i];
		map<char,int>M;
		int mid=0;
		int cnt[6][6];
		int clr[6];
		int num[6];
		memset( cnt,0,sizeof cnt );
		for ( i=0; i<n; i++ ) {
			if ( M[s[i][0]]==0 )M[s[i][0]]=++mid;
			st[i][0]=M[s[i][0]];
			st[i][1]=s[i][1]-'0';
			cnt[st[i][0]][st[i][1]]++;
		}
		int ans=M.SZ+5;
		for ( i=0; i<1<<M.SZ; i++ )for ( j=0; j<1<<5; j++ ) {
				memset( clr,0,sizeof clr );
				memset( num,0,sizeof num );
				vector<PII>L;
				int nc=0,nn=0;
				for ( p=0; p<M.SZ; p++ )for ( q=0; q<5; q++ )if ( cnt[p+1][q+1] ) {
							clr[p+1]+=cnt[p+1][q+1];
							num[q+1]+=cnt[p+1][q+1];
							if ( i>>p&1 );
							else nc+=cnt[p+1][q+1];
							if ( j>>q&1 );
							else nn+=cnt[p+1][q+1];
							L.PB( MP( p,q ) );
						}
				int fail=0;
				while ( !L.empty() ) {
					int got=-1;
					for ( k=0; k<L.SZ; k++ ) {
						int C=L[k].AA,N=L[k].BB;
						int fc=0,fn=0;
						if ( i>>C&1 )fc=1;
						else if ( nc==clr[C+1] )fc=3;
						if ( j>>N&1 )fn=1;
						else if ( nn==num[N+1] )fn=3;
						if ( ( fc&&fn )||( fn&&num[N+1]==cnt[C+1][N+1] )||( fc&&clr[C+1]==cnt[C+1][N+1] ) ) {
							clr[C+1]-=cnt[C+1][N+1];
							num[N+1]-=cnt[C+1][N+1];
							if ( i>>C&1 );
							else nc-=cnt[C+1][N+1];
							if ( j>>N&1 );
							else nn-=cnt[C+1][N+1];
							got=k;
							break;
						}
					}
					if ( got<0 ) {fail=1; break;}
					else L.erase( L.OP+got );
				}
				if ( !fail&&L.empty() )cmin( ans,__builtin_popcount( i )+__builtin_popcount( j ) );
			}
		cout<<ans<<endl;
	}
	return 0;
}
