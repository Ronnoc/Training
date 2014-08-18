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
const double PI=acos ( -1. );
const LL MOD = 1000000007;

priority_queue<int,vector<int>,greater<int> >R;
priority_queue<int,vector<int>,less<int> >L;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int p,q,n;
	while ( ~scanf ( "%d%d%d",&q,&p,&n ) ) {
		if ( !p&&!q&&!n ) break;
		LL sum=0;
		LL m=n-p-q;
		for ( i=1; i<=n; i++ ) {
			scanf ( "%d",&k );
			if ( L.size()<p||k<L.top() ) {
				L.push ( k );
				if ( L.size() >p ) L.pop();
			}
			if ( R.size()<q ||k>R.top() ) {
				R.push ( k );
				if ( R.size() >q ) R.pop();
			}
			sum+=k;
		}
		while ( !L.empty() ) {
			sum-=L.top();
			L.pop();
		}
		while ( !R.empty() ) {
			sum-=R.top();
			R.pop();
		}
		printf ( "%.6f\n",sum*1.0/m );
	}
	return 0;
}
