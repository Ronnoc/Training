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
LL llpow(int a,int b){
	LL ret=1;
	while(b--)ret*=a;
	return ret;
}
LL comb(int a,int b){
	if(b+b>a)return comb(a,a-b);
	if(b==0)return 1;
	return comb(a-1,b-1)*a/b;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,u,v;
	int T=0,CA;
	scanf( "%d",&T );
	while ( T-- ) {
		scanf( "%d",&CA );
		int P,R,C;
		scanf( "%d%d%d",&P,&R,&C );
		LL ans=comb(R,C);
		cout<<CA<<" "<<llpow(P,R-C)*comb(R,C)<<endl;
	}
	return 0;
}
