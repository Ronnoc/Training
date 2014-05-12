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
int fa[111];
int getfa( int u ) {return fa[u]==u?u:fa[u]=getfa( fa[u] );}
int main() {
	int i,j,k;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int n;
		scanf( "%d",&n );
		vector<string>S;
		string s;
		int mask[111];
		memset( mask,0,sizeof mask );
		int has[33];
		memset( has,0,sizeof has );
		for ( i=1; i<=n; i++ ) {
			cin>>s;
			for ( j=0; j<s.SZ; j++ )mask[i]|=1<<( s[j]-'a' );
			S.PB( s );
		}
		printf( "Case #%d: ",CASE );
		int flag=1;
		for ( i=0; i<S.SZ; i++ ) {
			set<char>D;
			int l=0,r=S[i].SZ-1;
			while ( l<S[i].SZ&&S[i][l]==S[i][0] )l++;
			while ( r>=0&&S[i][r]==S[i][S[i].SZ-1] )r--;
			if(S[i][0]==S[i][S[i].SZ-1]&&l!=S.SZ)flag=0;
			if ( r<l )continue;
			for ( j=l; j<=r; j++ )D.insert( S[i][j] );
			for ( k=0; k<S.SZ; k++ )if ( k!=i )
					for ( j=0; j<S[k].SZ; j++ )if ( D.count( S[k][j] ) )
							flag=0;
			if ( D.count( S[i][0] ) )flag=0;
			if ( D.count( S[i][S[i].SZ-1] ) )flag=0;
		}
		if ( !flag ) {
			printf( "0\n" );
			continue;
		}
		int G[33][33];
		memset( G,0,sizeof G );
		for ( i=0; i<S.SZ; i++ )
			G[S[i][0]-'a'][S[i][S[i].SZ-1]-'a']++;
		LL ans=1;
		memset(has,0,sizeof has);
		for ( i=0; i<26; i++ ) {
			int mul=G[i][i];
			if(mul)has[i]=1;
			LL tp=1;
			for ( j=1; j<=mul; j++ )tp=tp*j%MOD;
			ans=ans*tp%MOD;
			G[i][i]=0;
		}
		for ( i=0; i<26; i++ ) {
			int cnt1=0;
			for ( j=0; j<26; j++ )cnt1+=G[i][j];
			if ( cnt1>1 )flag=0;
			int cnt2=0;
			for ( j=0; j<26; j++ )cnt2+=G[j][i];
			if ( cnt2>1 )flag=0;
			if ( flag&&(cnt1>0||cnt2>0) )has[i]=1;
		}
		if ( !flag ) {
			printf( "0\n" );
			continue;
		}
		for ( i=0; i<26; i++ )if ( has[i] )fa[i]=i;
		for ( i=0; i<26; i++ )for ( j=0; j<26; j++ )if ( G[i][j] ) {
					int fi=getfa( i );
					int fj=getfa( j );
					if ( fi==fj )ans*=0;
					else fa[fi]=fj;
				}
		set<int>SS;
		for ( i=0; i<26; i++ )if ( has[i] )SS.insert( getfa( i ) );
		int mul=SS.SZ;
		LL tp=1;
		for ( j=1; j<=mul; j++ )tp=tp*j%MOD;
		ans=ans*tp%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
/*
4
3 ab bbbc cd
4 aa aa bc c
2 abc bcd
3 ab bc ca
*/
