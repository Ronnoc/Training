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
int gao( string s ) {
	if ( s.SZ==1 )return s[0]=='1';
	int i;
	for ( i=0; i+1<s.SZ; i++ )if ( s[i]=='N' )if ( isdigit( s[i+1] ) ) {
				string ret=s.substr( 0,i );
				if ( s[i+1]=='0' )ret+='1';
				else ret+='0';
				if ( i+2<s.SZ )ret+=s.substr( i+2,s.SZ-2-i );
				return gao( ret );
			}
	for ( i=0; i+2<s.SZ; i++ )if ( s[i]=='K' )if ( isdigit( s[i+1] )&&isdigit( s[i+2] ) ) {
				string ret=s.substr( 0,i );
				int p=s[i+1]-'0',q=s[i+2]-'0';
				ret+=( p&q )+'0';
				if ( i+3<s.SZ )ret+=s.substr( i+3,s.SZ-3-i );
				return gao( ret );
			}
	for ( i=0; i+2<s.SZ; i++ )if ( s[i]=='A' )if ( isdigit( s[i+1] )&&isdigit( s[i+2] ) ) {
				string ret=s.substr( 0,i );
				int p=s[i+1]-'0',q=s[i+2]-'0';
				ret+=( p|q )+'0';
				if ( i+3<s.SZ )ret+=s.substr( i+3,s.SZ-3-i );
				return gao( ret );
			}
	for ( i=0; i+2<s.SZ; i++ )if ( s[i]=='C' )if ( isdigit( s[i+1] )&&isdigit( s[i+2] ) ) {
				string ret=s.substr( 0,i );
				int p=s[i+1]-'0',q=s[i+2]-'0';
				ret+=( !p||q )+'0';
				if ( i+3<s.SZ )ret+=s.substr( i+3,s.SZ-3-i );
				return gao( ret );
			}
	for ( i=0; i+2<s.SZ; i++ )if ( s[i]=='E' )if ( isdigit( s[i+1] )&&isdigit( s[i+2] ) ) {
				string ret=s.substr( 0,i );
				int p=s[i+1]-'0',q=s[i+2]-'0';
				ret+=( p==q )+'0';
				if ( i+3<s.SZ )ret+=s.substr( i+3,s.SZ-3-i );
				return gao( ret );
			}
	return -1;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	string s;
	while ( cin>>s ) {
		if ( s=="0" )break;
		string t[1<<6];
		int flag=1;
		for ( i=0; i<1<<5; i++ ) {
			t[i]=s;
			for ( j=0; j<s.SZ; j++ )if ( islower( t[i][j] ) )
					t[i][j]=( ( i>>( t[i][j]-'p' ) )&1 )+'0';
//			cout<<t[i]<<endl;
			if ( !gao( t[i] ) ) {flag=0; break;}
		}
		if ( flag )printf( "tautology\n" );
		else printf( "not\n" );
	}
	return 0;
}
