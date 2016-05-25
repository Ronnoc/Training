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
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(p) sort(p.OP,p.ED)
typedef long long LL;
typedef pair<int, int> PII;

bool s[111][111][111][2];
class TheMatrix {
public:
	int MaxArea( vector <string> b ) {
		int ret=0;
		int i,j,k;
		memset( s,0,sizeof s );
		for ( i=0; i<b.SZ; i++ ) {
			for ( j=0; j<b[i].SZ; j++ ) {
				if ( b[i][j]=='0' )s[i][j][j][0]=1;
				else s[i][j][j][1]=1;
				for ( k=j+1; k<b[i].SZ; k++ ) {
					if ( b[i][k]=='0' )s[i][j][k][0]=s[i][j][k-1][1],s[i][j][k][1]=0;
					else s[i][j][k][1]=s[i][j][k-1][0],s[i][j][k][0]=0;
				}
			}
		}
		for ( j=0; j<b[0].SZ; j++ )for ( k=j; k<b[0].SZ; k++ ) {
				vector<int>L;
				for ( i=0; i<b.SZ; i++ )L.PB( s[i][j][k][i&1] );
				int id,l,r;
				id=0;
				while ( id<L.SZ ) {
					while ( id<L.SZ&&!L[id] )id++;
					l=id;
					while(id<L.SZ&&L[id])id++;
					r=id;
					ret=max(ret,(r-l)*(k-j+1));
				}
				L.clear();
				for ( i=0; i<b.SZ; i++ )L.PB( s[i][j][k][1-i&1] );
				id=0;
				while ( id<L.SZ ) {
					while ( id<L.SZ&&!L[id] )id++;
					l=id;
					while(id<L.SZ&&L[id])id++;
					r=id;
					ret=max(ret,(r-l)*(k-j+1));
				}
			}
		return ret;
	}
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
