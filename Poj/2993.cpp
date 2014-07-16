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
string a="+---+---+---+---+---+---+---+---+";
string b="|...|:::|...|:::|...|:::|...|:::|";
string c="|:::|...|:::|...|:::|...|:::|...|";
string w,W,bb,B;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	while ( cin>>w>>W>>bb>>B ) {
		vector<string>O;
		for ( i=0; i<8; i++ ) {
			O.PB( a );
			if ( i&1 )O.PB( c );
			else O.PB( b );
		}
		O.PB( a );
		for ( i=0; i<W.SZ; i++ )if ( W[i]==',' )W[i]=' ';
		for ( i=0; i<B.SZ; i++ )if ( B[i]==',' )B[i]=' ';
		istringstream win( W ),bin( B );
		while ( win>>w ) {
			if ( w.SZ==3 ) {
				int x=w[1]-'a';
				int y=w[2]-'0';
				x=4*x+2;
				y=2*( 9-y )-1;
				O[y][x]=toupper( w[0] );
			} else {
				int x=w[0]-'a';
				int y=w[1]-'0';
				x=4*x+2;
				y=2*( 9-y )-1;
				O[y][x]='P';
			}
		}
		while ( bin>>w ) {
			if ( w.SZ==3 ) {
				int x=w[1]-'a';
				int y=w[2]-'0';
				x=4*x+2;
				y=2*( 9-y )-1;
				O[y][x]=tolower( w[0] );
			} else {
				int x=w[0]-'a';
				int y=w[1]-'0';
				x=4*x+2;
				y=2*( 9-y )-1;
				O[y][x]='p';
			}
		}
		for ( i=0; i<O.SZ; i++ )cout<<O[i]<<endl;
	}
	return 0;
}
