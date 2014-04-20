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
int n;
int a[111];
int p[111];
int dp[111];
int main(){
	int i,j,k;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d%d",&a[i],&p[i]);
		int dp[111];
		dp[0]=0;
		for(i=1;i<=n;i++){
			dp[i]=dp[i-1]+p[i]*(a[i]+10);
			for(j=i-2;j>=0;j--){
				int tot=0;
				for(k=j+1;k<=i;k++)tot+=a[k];
				cmin(dp[i],dp[j]+p[i]*(tot+10));
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
