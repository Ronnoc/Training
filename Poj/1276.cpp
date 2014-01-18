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
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;
int dp[4][100010];
int w[22];
int cnt[22];
int m,n;
void solve() {
  int i,j;
  while (~scanf("%d%d",&m,&n)) {
    for (i=1; i<=n; i++) scanf("%d%d",&cnt[i],&w[i]);
    vector<int>L;
    for(i=1;i<=n;i++){
			int now=1;
			int tot=0;
			int all=0;
			while(cnt[i]>=tot+now){
				tot+=now;
				L.PB(now*w[i]);
				now*=2;
			}
			L.PB((cnt[i]-tot)*w[i]);
    }
    SORT(L);
    int ans=0;
    memset(dp[0],0,sizeof dp[0]);
    dp[0][0]=1;
    for(i=0;ans!=m&&i<L.SZ;i++){
			int x=i%2;
			int y=(i+1)%2;
			for(j=0;j<=m;j++)dp[y][j]=dp[x][j];
			for(j=0;j<=m;j++)if(dp[x][j]&&j+L[i]<=m){
				dp[y][j+L[i]]=1;
				ans=max(ans,j+L[i]);
			}
    }
    printf("%d\n",ans);
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
/*
100000 10
1000 1
1000 2
1000 4
1000 8
1000 16
1000 32
1000 64
1000 128
1000 256
1000 512
*/
