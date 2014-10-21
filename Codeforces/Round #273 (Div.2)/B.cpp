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
LL f(LL n,LL m){
	n-=m;
	n++;
	return n*(n-1)/2;
}
LL g(LL n,LL m){
	LL pa=n/m;
	LL qa=pa+1;
	LL qn=n%m;
	LL pn=m-n%m;
	return pn*f(pa,1)+qn*f(qa,1);
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	LL n,m;
	while(cin>>n>>m){
		LL amin=f(n,m),amax=f(n,m);
		cmin(amin,g(n,m));
		cmax(amax,g(n,m));
		cout<<amin<<" "<<amax<<"\n";
	}
	return 0;
}
