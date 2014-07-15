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
LL G( LL n ) {
	LL ret=0;
	for ( LL i=1; i<=n; ) {
		LL add=n/i;
		LL last=n/add;
		ret+=1LL*add*( last-i+1 );
		i=last+1;
	}
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	LL n;
	int T;
	cin>>T;
	for ( int CA=1; CA<=T; ++CA ) {
		cin>>n;
		cout<<G( n )<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
