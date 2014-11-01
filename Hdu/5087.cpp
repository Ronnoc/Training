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
#define NAME ""
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;

int a[1005];
int dp[1005][2];
void update(int *P,int w){
	if(P[0]<=w){
		P[1]=P[0];
		P[0]=w;
	}else cmax(P[1],w);
}
int main() {
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--){
		int n;
		scanf("%d",&n);
		memset(dp,-1,sizeof dp);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		dp[1][0]=1;
		dp[1][1]=-1;
		for(i=2;i<=n;i++){
			vector<int>L;
			L.PB(1);
			int P[2];
			P[0]=1,P[1]=-1;
			for(j=1;j<i;j++)if(a[j]<a[i]){
				if(~dp[j][0])update(P,dp[j][0]+1);
				if(~dp[j][1])update(P,dp[j][1]+1);
			}
			dp[i][0]=P[0];
			dp[i][1]=P[1];
		}
		vector<int>L;
		for(i=1;i<=n;i++)L.PB(dp[i][0]);
		for(i=1;i<=n;i++)L.PB(dp[i][1]);
		sort(L.OP,L.ED);
		reverse(L.OP,L.ED);
		printf("%d\n",L[1]<0?0:L[1]);
	}
	return 0;
}
