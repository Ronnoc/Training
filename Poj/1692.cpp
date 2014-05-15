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
int dp[111][111];
int a[111],b[111];
int main(){
	int i,j;
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(dp,0,sizeof dp);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(j=1;j<=m;j++)scanf("%d",&b[j]);
		for(i=1;i<=n;i++)for(j=1;j<=m;j++){
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			int l=i-1,r=j-1;
			while(l>=1&&a[l]!=b[j])l--;
			while(r>=1&&b[r]!=a[i])r--;
			if(l>=1&&r>=1&&a[i]!=b[j])cmax(dp[i][j],dp[l-1][r-1]+1);
		}
		printf("%d\n",dp[n][m]*2);
	}
	return 0;
}
