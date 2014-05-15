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
LL dp[111][111];
int w[111];
int main(){
	int i,j;
	int n;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)scanf("%d",&w[i]);
		memset(dp,0,sizeof dp);
		for(i=1;i+2<=n;i++)
			dp[i][i+2]=w[i]*w[i+1]*w[i+2];
		for(int l=4;l<=n;l++){
			for(i=1;i<=n;i++){
				j=i+l-1;
				if(j>n)break;
				dp[i][j]=dp[i][j-1]+w[i]*w[j-1]*w[j];
				for(int k=i+1;k<j;k++)cmin(dp[i][j],dp[i][k]+dp[k][j]+w[i]*w[k]*w[j]);
			}
		}
		cout<<dp[1][n]<<endl;
	}
	return 0;
}
