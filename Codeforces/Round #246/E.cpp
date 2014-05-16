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
char s[111][111];
bool vis[111][111];
int n,m;
char check( int si,int sj ) {
	bool v[33];
	memset( v,0,sizeof v );
	if ( si>0&&vis[si-1][sj] )v[s[si-1][sj]-'A']=1;
	if ( si+1<n&&vis[si+1][sj] )v[s[si+1][sj]-'A']=1;
	if ( sj>0&&vis[si][sj-1] )v[s[si][sj-1]-'A']=1;
	if ( sj+1<m&&vis[si][sj+1] )v[s[si][sj+1]-'A']=1;
	int id=0;
	while ( v[id] )id++;
	return id+'A';
}
bool valid(int si,int sj,char C){
	if ( si>0&&vis[si-1][sj]&&C==s[si-1][sj] )return 0;
	if ( si+1<n&&vis[si+1][sj]&&C==s[si+1][sj])return 0;
	if ( sj>0&&vis[si][sj-1]&&C==s[si][sj-1])return 0;
	if ( sj+1<m&&vis[si][sj+1]&&C==s[si][sj+1])return 0;
	return 1;
}
int main() {
	int i,j;
	int len;
	while ( cin>>n>>m ) {
		memset( vis,0,sizeof vis );
		for ( len=1;; len++ ) {
			if ( len-1>=n||len-1>=m )break;
			int ok=1;
			for ( i=0; i<len; i++ )for ( j=0; j<len; j++ )if ( vis[i][j] )ok=0;
			if ( !ok )break;
		}
		len--;
		for ( i=0; i<len; i++ )for ( j=0; j<len; j++ )s[i][j]='A',vis[i][j]=1;
		while ( 1 ) {
			int got=0,si,sj;
			for ( i=0; !got&&i<n; i++ )for ( j=0; !got&&j<m; j++ )if ( !vis[i][j] )got=1,si=i,sj=j;
			if ( !got )break;
			s[si][sj]=check( si,sj ),vis[si][sj]=1;
			if ( sj+1<m ) {
				char tp=check( si,sj+1 );
				//cout<<si<<" "<<sj<<" "<<s[si][sj]<<" "<<tp<<endl;
				if ( tp>s[si][sj] ) {
					vis[si][sj]=0;
					for ( len=1;; len++ ) {
						if ( si+len-1>=n||sj+len-1>=m )break;
						int ok=1;
						for ( i=0; i<len; i++ )for ( j=0; j<len; j++ )
							if ( vis[si+i][sj+j]||!valid(si+i,sj+j,s[si][sj]) )ok=0;
						if ( !ok )break;
					}
					len--;
					//cout<<len<<endl;
					for ( i=0; i<len; i++ )for ( j=0; j<len; j++ )
							s[si+i][sj+j]=s[si][sj],vis[si+i][sj+j]=1;
				}
			}
		}
		for ( i=0; i<n; i++ ) {
			for ( j=0; j<m; j++ )printf( "%c",s[i][j] );
			printf( "\n" );
		}
	}
	return 0;
}
// 14 35
// 35 14
