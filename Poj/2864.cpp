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
	int i,j,k,T;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(!n&&!m)break;
		int ans[111];
		for(i=1;i<=n;i++)ans[i]=1;
		for(j=1;j<=m;j++)
			for(i=1;i<=n;i++){scanf("%d",&k);ans[i]&=k;}
		int ret=0;
		for(i=1;i<=n;i++)cmax(ret,ans[i]);
		if(ret)puts("yes");
		else puts("no");
	}
	return 0;
}
