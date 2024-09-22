#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) \
  int(X);      \
  scanf("%d", &X)
#define rep(i, a, n) for (int i = (a); i < (int)(n); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
const LL MOD = 1000000007;
const long double PI = acos(-1.);
const long double eps = 1e-9;

const int MXN = 200005;
VI G[MXN];
int a[MXN];
// dp[u][s][t]: at u, select[u]=s, select[fa[u]]=t
LL dp[MXN][2][2];
int N,C;

void dfs(int u,int fa){
    for(auto v:G[u]){
        if(v==fa)continue;
        dfs(v,u);
    }
    rep(s,0,2)rep(t,0,2){
        LL cur=0;
        if(s){
            cur=a[u];
            if(t)cur-=C;
        }
        for(auto v:G[u]){
            if(v==fa)continue;
            cur+=max(dp[v][0][s],dp[v][1][s]-(s?C:0));
        }
        // cerr<<"dp@<"<<u<<","<<s<<","<<t<<">="<<cur<<endl;
        dp[u][s][t]=cur;
    }
}

void solve(){
    RI(N);
    RI(C);
    rep(i,1,N+1)G[i].clear();
    rep(i,1,N+1)RI(a[i]);
    rep(i,1,N+1)rep(j,0,2)rep(k,0,2)dp[i][j][k]=-1;
    rep(i,1,N){
        DRI(u);
        DRI(v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1,-1);
    cout<<max(dp[1][0][0],dp[1][1][0])<<endl;
}

int main()
{
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    // printf("Case #%d:", CA);
    solve();
  }
  fflush(stdout);
  return 0;
}