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
string cut( string s,int l,int r ) {
	return s.substr( l,r-l );
}
int dp[105][105];
int pre[105][105];
string s;
int solve( int l,int r ) {
	int &tp=dp[l][r];
	if ( ~tp )return tp;
	if ( r==l )return tp=0;
	if ( s[l]==')' )return tp=2+solve( l+1,r );
	if ( s[l]==']' )return tp=2+solve( l+1,r );
	string rp,lp,ap;
	char pp;
	if ( s[l]=='(' )pp=')',lp="(",rp=")",ap="()";
	else pp=']',lp="[",rp="]",ap="[]";
	int ret=2+solve( l+1,r );
	pre[l][r]=r;
	for ( int i=l+1; i<r; i++ ) {
		int tmp;
		if ( s[i]==pp )
			tmp=2+solve( l+1,i )+solve( i+1,r );
		else
			tmp=2+solve( l+1,i )+solve( i,r );
		if ( tmp<ret )ret=tmp,pre[l][r]=i;
	}
	return tp=ret;
}
string get( int l,int r ) {
	if ( r==l )return "";
	if ( s[l]==')' )return "()"+get( l+1,r );
	if ( s[l]==']' )return "[]"+get( l+1,r );
	string rp,lp,ap;
	char pp;
	if ( s[l]=='(' )pp=')',lp="(",rp=")",ap="()";
	else pp=']',lp="[",rp="]",ap="[]";
	if ( pre[l][r]==r )return lp+get( l+1,r )+rp;
	int id=pre[l][r];
	if ( s[id]==pp )return lp+get( l+1,id )+rp+get( id+1,r );
	return lp+get( l+1,id )+rp+get( id,r );
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while ( getline( cin,s )!=NULL ) {
		memset( dp,-1,sizeof dp );
		solve( 0,s.SZ );
		cout<<get( 0,s.SZ )<<endl;
	}
	return 0;
}
