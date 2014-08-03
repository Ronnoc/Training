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
#define SQ ((x)*(x))
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int,int> PII;

void dlt() {
	while ( getchar()!='\n' );
}
char s[666];
LL dp[222][222];
vector<LL> gao( string a,string b ) {
	LL dp[155][155];
	int i,j;
	for ( i=0; i<=a.SZ; i++ )for ( j=0; j<=b.SZ; j++ )dp[i][j]=0;
	dp[0][0]=1;
	for ( i=0; i<=a.SZ; i++ ) {
		for ( j=0; j<=b.SZ; j++ ) if ( dp[i][j] ) {
				if ( i<a.SZ&&j<b.SZ&&a[i]==b[j] )dp[i+1][j+1]+=dp[i][j];
				dp[i][j+1]+=dp[i][j];
			}
	}
//	cout<<a<<" vs "<<b<<endl;
//	for ( i=0; i<=a.SZ; i++,printf( "\n" ) )
//		for ( j=0; j<=b.SZ; j++ )printf( " %I64d",dp[i][j] );
	vector<LL>ret;
	for ( i=0; i<=a.SZ; i++ )ret.PB( dp[i][b.SZ] );
	return ret;
}
int main() {
	int n,m,i,j,k;
	int CA=0;
//	gao( "acm","academy" );
	while ( ~scanf( "%d",&n ) ) {
		dlt();
		++CA;
		if ( !n )break;
		set<string>A;
		for ( i=0; i<n; i++ ) {
			gets( s );
			istringstream sin( s );
			string tmp;
			sin>>tmp;
			A.insert( string( tmp ) );
		}
		while ( 1 ) {
			gets( s );
			char jump[]="LAST CASE";
			j=0;
			for ( i=0; i<9; i++ )if ( jump[i]!=s[i] )j=1;
			if ( !j )break;
			istringstream sin( s );
			vector<string>L;
			string S,tmp;
			sin>>S;
			for ( i=0; i<S.SZ; i++ )S[i]=tolower( S[i] );
			while ( sin>>tmp ) {
//				cout<<"`"<<tmp<<"`"<<A.count(tmp)<<endl;
				if ( !A.count( tmp ) )L.PB( tmp );
			}
			memset( dp,0,sizeof dp );
			dp[0][0]=1;
			for ( i=0; i<S.SZ; i++ )for ( j=0; j<L.SZ; j++ )if ( dp[i][j] ) {
						vector<LL>p=gao( S.substr( i,S.SZ-i ),L[j] );
						for ( k=1; k<p.SZ; k++ )
							dp[i+k][j+1]+=p[k]*dp[i][j];
					}
			for ( i=0; i<S.SZ; i++ )S[i]=toupper( S[i] );
			LL ans=dp[S.SZ][L.SZ];
			if ( ans )cout<<S<<" can be formed in "<<ans<<" ways\n";
			else cout<<S<<" is not a valid abbreviation\n";
		}
	}
	return 0;
}

