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
vector<PII>G[5010];
int dp[5010][5];
void solve() {
  int i,j;
  int n,m;
  while (cin>>n>>m) {
    for (i=1; i<=n; i++) for (j=1; j<=2; j++) dp[i][j]=MOD;
    for (i=1; i<=n; i++) G[i].clear();
    for (i=1; i<=m; i++) {
      int p,q,d;
      scanf ("%d%d%d",&p,&q,&d);
      G[p].PB (MP (q,d));
      G[q].PB (MP (p,d));
    }
    priority_queue<PII>pq;
    pq.push (MP (0,1));
    while (!pq.empty()) {
      PII tp=pq.top();
      pq.pop();
      int u=tp.BB;
      int t=-tp.AA;
//      cout<<u<<" "<<t<<endl;
//      for (j=1; j<=2; j++) {
//        for (i=1; i<=n; i++) cout<<dp[i][j]<<" ";
//        cout<<endl;
//      }
      if (dp[u][2]<t) continue;
      if (dp[u][1]>t) {dp[u][2]=dp[u][1]; dp[u][1]=t;}
      else if (dp[u][2]>t) {dp[u][2]=t;}
      for (i=0; i<G[u].SZ; i++) {
        int v=G[u][i].AA;
        int w=G[u][i].BB;
        pq.push (MP (-w-t,v));
      }
    }
    printf ("%d\n",dp[n][2]);
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
