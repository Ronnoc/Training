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
const double PI=acos(-1.);
const LL MOD = 1000000007;

LL dp[2][200005];
bool vis[2][200005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	int r,g;
	while(cin>>r>>g) {
		if(g<r)swap(r,g);
		LL ans=0;
		dp[0][r]=1;
		vis[0][r]=1;
		for(int ii=0;; ii++) {
			i=ii&1;
			int y=1^i;
			memset(dp[y],0,sizeof dp[y]);
			memset(vis[y],0,sizeof vis[y]);
			int flag=0;
			int sum=ii*(ii+1)/2;
			LL now=0;
			for(j=0; j<=r; j++)if(vis[i][j]) {
					if(dp[i][j]>=MOD)dp[i][j]%=MOD;
					now+=dp[i][j];
					k=sum-(r-j);
					if(k<0||k>g)continue;
					k=g-k;
					flag=1;
					if(j>ii)dp[y][j-ii-1]+=dp[i][j],vis[y][j-ii-1]=1;
					if(k>ii)dp[y][j]+=dp[i][j],vis[y][j]=1;
				}
			if(!flag)break;
			else ans=now%MOD;
		}
		cout<<ans%MOD<<endl;
	}
	return 0;
}
