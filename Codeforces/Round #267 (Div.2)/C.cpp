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

LL dp[5005][5005];
int p[5005];
LL S[5005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n,m,o;
	while(~scanf("%d%d%d",&n,&m,&o)){//o¸ö³¤Îªm
		for(i=1;i<=n;i++)scanf("%d",&p[i]);
		memset(dp,0,sizeof dp);
		for(S[0]=0,i=1;i<=n;i++)S[i]=S[i-1]+p[i];
		for(i=1;i<=n;i++)for(j=0;j<=o;j++){
			cmax(dp[i+1][j],dp[i][j]);
			if(i+m-1<=n&&j<o)cmax(dp[i+m][j+1],dp[i][j]+S[i+m-1]-S[i-1]);
//			cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
		}
		cout<<dp[n+1][o]<<endl;
	}
	return 0;
}
