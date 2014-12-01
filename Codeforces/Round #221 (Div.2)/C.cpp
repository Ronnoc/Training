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
int p[]= {1,3,2,6,4,5};
string s;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	while ( cin>>s ) {
		reverse( s.OP,s.ED );
		string t;
		int f1,f6,f8,f9;
		f1=f6=f8=f9=0;
		for ( i=0; i<s.SZ; i++ ) {
			if ( s[i]=='1' ) {if ( !f1 )f1=1; else t+=s[i];}
			else if ( s[i]=='6' ) {if ( !f6 )f6=1; else t+=s[i];}
			else if ( s[i]=='8' ) {if ( !f8 )f8=1; else t+=s[i];}
			else if ( s[i]=='9' ) {if ( !f9 )f9=1; else t+=s[i];}
			else t+=s[i];
		}
		int w=t.SZ;
		t+="1689";
		do {
			int now=0;
			for ( i=0; i<t.SZ; i++ )now=( now+( t[i]-'0' )*p[i%6] )%7;
			if ( now==0 )break;
		} while ( next_permutation( t.OP+w,t.ED ) );
		reverse( t.OP,t.ED );
		cout<<t<<endl;
	}
	return 0;
}
