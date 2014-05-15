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
map<char,int>M;
bool hv( char x ) {
	if ( x<='9'&&x>='0' )return 1;
	if ( x<='Z'&&x>='A' )return 1;
	if ( x<='z'&&x>='a' )return 1;
	return 0;
}
LL give( char x ) {
	LL ret;
	if ( x<='9'&&x>='0' )ret=x-'0';
	if ( x<='Z'&&x>='A' )ret=M[x];
	if ( x<='z'&&x>='a' )ret=M[x];
	return ret;
}
LL save( LL x ) {
	return ( x%MOD+MOD )%MOD;
}
LL play( char *s,int l,int r ) {
	if ( l==r )return 0;
	//for ( int i=l; i<r; i++ )printf( "%c",s[i] );
	//printf( "\n" );
	int i,flag=0;
	for(i=l;i<r;i++)if(!hv(s[i]))flag=1;
	if ( !flag ) {
		int allint=1;
		for(i=l;i<r;i++)if(s[i]>='0'&&s[i]<='9');else allint=0;
		if(!allint)return M[s[l]];
		LL ret=0;
		for(i=l;i<r;i++)ret=(ret*10+s[i]-'0')%MOD;
		return ret;
	}
	i=r-1;
	set<PII>SS;
	while ( i>=l ) {
		while ( hv( s[i] ) )i--;
		if ( i<l )break;
		if ( s[i]==')' ) {
			int cnt=0;
			int rr=i;
			while ( 1 ) {
				if ( s[i]==')' )cnt++;
				if ( s[i]=='(' )cnt--;
				if ( !cnt )break;
				i--;
			}
			SS.insert( MP( i,rr ) );
			i--;
		}
		if ( i<l )break;
		if ( s[i]=='*' ) {i--; continue;}
		if ( s[i]=='-' ) {
			//cout<<play( s,l,i )<<" - "<<play( s,i+1,r )<<endl;
			return save( play( s,l,i )-play( s,i+1,r ) );
		}
		
		if ( s[i]=='+' ) {
			//cout<<play( s,l,i )<<" + "<<play( s,i+1,r )<<endl;
			return save( play( s,l,i )+play( s,i+1,r ) );
		}
	}
	if ( SS.count( MP( l,r-1 ) ) )return play( s,l+1,r-1 );
	i=r-1;
	while ( i>=l ) {
		while ( hv( s[i] ) )i--;
		if ( i<l )break;
		if ( s[i]==')' ) {
			int cnt=0;
			int rr=i;
			while ( 1 ) {
				if ( s[i]==')' )cnt++;
				if ( s[i]=='(' )cnt--;
				if ( !cnt )break;
				i--;
			}
			SS.insert( MP( i,rr ) );
			i--;
		}
		if ( i<l )break;
		if ( s[i]=='*' ) {
			//cout<<play( s,l,i )<<" * "<<play( s,i+1,r )<<endl;
			return save( play( s,l,i )*play( s,i+1,r ) );
		}
	}
}
int main() {
	int i,j;
	int T;
	scanf( "%d%*c",&T );
	while ( T-- ) {
		char a[111],b[111];
		gets(a);
		gets(b);
		int ia=0,ib=0;
		for(i=0;a[i];i++)if(a[i]!=' '&&a[i]!='\t')a[ia++]=a[i];
		a[ia]='\0';
		for(i=0;b[i];i++)if(b[i]!=' '&&b[i]!='\t')b[ib++]=b[i];
		b[ib]='\0';
		int same=1;
		for ( int t=0; t<=100; t++ ) {
			for ( j=0; j<26; j++ )M[j+'a']=rand();
			for ( j=0; j<26; j++ )M[j+'A']=rand();
			if ( play( a,0,strlen( a ) )!=play( b,0,strlen( b ) ) ) {
				same=0; break;
			}
		}
		if ( same )printf( "YES\n" );
		else printf( "NO\n" );
	}
	return 0;
}
