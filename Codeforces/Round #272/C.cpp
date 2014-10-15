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
char s[4005],p[505];
int q[4005];
int f[4005];
int dp[4005][4005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	while(~scanf("%s%s",s,p)){
		memset(dp,-1,sizeof dp);
		int ls=strlen(s),lp=strlen(p);
		for(i=0;i<=ls;i++){
			int id=0,j=i;
			while(id<lp&&j<=ls){
				if(s[j]==p[id])id++;
				j++;
			}
			q[i]=j;
		}
//		for(i=0;i<ls;i++)cout<<q[i]<<" ";cout<<endl;
		dp[0][0]=0;
		for(i=0;i<=ls;i++)for(j=0;j<=i;j++)if(~dp[i][j]){
			cmax(dp[q[i]][j+q[i]-i-lp],dp[i][j]+1);
			cmax(dp[i+1][j],dp[i][j]);
			cmax(dp[i+1][j+1],dp[i][j]);
		}
		for(i=0;i<=ls;i++)cout<<dp[ls][i]<<" ";cout<<endl;
	}
	return 0;
}
