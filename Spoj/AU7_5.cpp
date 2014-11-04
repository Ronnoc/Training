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
const LL MOD = 5000011;

LL dp[100005];
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--){
		int n,m;
		scanf("%d%d",&n,&m);
		m++;
		dp[1]=2;
		for(i=2;i<=n;i++){
			dp[i]=dp[i-1];
			if(i>m)dp[i]+=dp[i-m];
			else dp[i]++;
			if(dp[i]>=MOD)dp[i]-=MOD;
		}
		printf("%d\n",(int)dp[n]);
	}
	return 0;
}
