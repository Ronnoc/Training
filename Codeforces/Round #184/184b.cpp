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
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	LL p,q;
	while ( cin>>p>>q ) {
		vector<LL>D;
		int n;
		cin>>n;
		while ( n-- ) {
			LL x;
			cin>>x;
			D.PB( x );
		}
		if ( D[D.SZ-1]==1&&D.SZ>=2 ) {
			D[D.SZ-2]++;
			D.pop_back();
		}
		int flag=1;
		for ( i=0; i<D.SZ; i++ ) {
			if ( q==0 ) {flag=0; break;}
			LL a=p/q;
			if ( a!=D[i] ) {flag=0; break;}
			p-=a*q;
			swap( p,q );
		}
		if ( q!=0 )flag=0;
		printf( "%s\n",flag?"YES":"NO" );
	}
	return 0;
}
