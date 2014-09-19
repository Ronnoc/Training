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

LL dp[33][1<<3|1];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	memset(dp,0,sizeof dp);
	dp[0][7]=1;
	for(i=0;i<30;i++)for(j=0;j<1<<3;j++)if(dp[i][j]){
		for(k=0;k<1<<3;k++){
			if(k&1)continue;
			if(k&(k>>1))continue;
			int put=k|(k>>1);
			if((put&j)!=put)continue;
			int rem=j^put;
			int next=7^rem;
			dp[i+1][next]+=dp[i][j];
		}
	}
	int n;
	while(~scanf("%d",&n)&&(~n))
		cout<<dp[n][7]<<endl;	
	return 0;
}
