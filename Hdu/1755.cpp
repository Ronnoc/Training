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
string tmp[111][111];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int n,m;
	while ( cin>>n>>m ) {
		int a[9];
		for ( i=0; i<n; i++ )cin>>a[i];
		string s;
		for ( i=0; i<n; i++ )s+=a[i]+'0';
		SORT( s );
		for ( i=1; i<=100; i++ )for ( j=0; j<i; j++ )tmp[i][j].clear();
		do {
			if ( s[0]!='0' ) {
				istringstream sin( s );
				sin>>j;
				for ( i=1; i<=100; i++ )if ( tmp[i][j%i].empty()||tmp[i][j%i]>s )
						tmp[i][j%i]=s;
			}
		} while ( next_permutation( s.OP,s.ED ) );
		while ( m-- ) {
			int p,q;
			cin>>p>>q;
			p=( q-p%q )%q;
			if ( tmp[q][p].empty() )cout<<"None\n";
			else cout<<tmp[q][p]<<endl;
		}
	}
	return 0;
}
