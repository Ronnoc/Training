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
LL modPow(LL a, LL b, LL MOD)
{
  LL ret = 1;
  for (; b; b >>= 1)
  {
    if (b & 1)
      ret = ret * a % MOD;
    a = a * a % MOD;
  }
  return ret;
}
#define COST_INF 1e9
int R,C,F,S;
LL greedy;
template <typename T>
class MinCostFlow
{
private:
  struct edge
  {
    int to;
    LL cap;
    T cost;
    int rev;
  };

  int V;
  vector<vector<edge> > adj;
  vector<T> pot;

  pair<LL, T> dijkstra(int s, int t, LL FLOW_BOUND)
  {
    vector<int> used(V, 0);
    vector<T> dist(V, COST_INF);
    vector<PII> path(V, MP(-1, -1));
    priority_queue<pair<T, int> > Q;
    dist[s] = 0;
    Q.push(MP(0, s));
    while (!Q.empty())
    {
      int x = Q.top().BB;
      Q.pop();
      if (used[x])
        continue;
      used[x] = 1;
      for (int i = 0; i < adj[x].SZ; i++)
        if (adj[x][i].cap > 0)
        {
          edge e = adj[x][i];
          int y = e.to;
          T d = dist[x] + e.cost + pot[x] - pot[y];
          if (d < dist[y] && !used[y])
          {
            dist[y] = d;
            path[y] = MP(x, i);
            Q.push(MP(-d, y));
          }
        }
    }
    for (int i = 0; i < V; i++)
      pot[i] += dist[i];
    if (dist[t] == COST_INF)
      return MP(0, 0);
    LL f = FLOW_BOUND;
    T sum = 0;
    int x = t;
    while (x != s)
    {
      int y = path[x].AA;
      int id = path[x].BB;
      sum += adj[y][id].cost;
      cmin(f, adj[y][id].cap);
      x = y;
    }
    x = t;
    while (x != s)
    {
      int y = path[x].AA;
      int id = path[x].BB;
      adj[y][id].cap -= f;
      int id2 = adj[y][id].rev;
      adj[x][id2].cap += f;
      // cout<<x<<"~"<<y<<endl;
      x = y;
    }
    // cout<<endl;
    return MP(f, f * sum);
  }

public:
  MinCostFlow(int n)
  { //[0,n)
    V = n;
    adj.resize(V, vector<edge>(0));
    pot.resize(V, 0);
  }
  void add_edge(int s, int t, LL f, T c)
  {
    edge e1 = {t, f, c, (int)adj[t].SZ};
    edge e2 = {s, 0LL, -c, (int)adj[s].SZ};
    adj[s].PB(e1);
    adj[t].PB(e2);
  }
  LL mincostflow(int s, int t, LL FLOW_BOUND = (1LL << 48))
  {
    pair<LL, T> ans = MP(0LL, 0);
    LL ret = greedy;
    // cout<<ret<<endl;
    while (FLOW_BOUND > 0)
    {
      pair<LL, T> tmp = dijkstra(s, t, FLOW_BOUND);
      if (tmp.AA == 0)
        break;
      ans.AA += tmp.AA;
      ans.BB += tmp.BB;
      LL candi = greedy - 2 * ans.AA*F + ans.BB;
      // cout << greedy<<" "<<ans.AA<<" "<<ans.BB<<" "<<candi << endl;
      ret = min(ret, candi);
      FLOW_BOUND -= tmp.AA;
    }
    return ret;
  }
};

vector<string> A;
vector<string> B;
void solve()
{
  RI(R);
  RI(C);
  RI(F);
  RI(S);
  A.clear();
  B.clear();
  rep(i, 0, R)
  {
    string s;
    cin >> s;
    A.PB(s);
  }
  rep(i, 0, R)
  {
    string s;
    cin >> s;
    B.PB(s);
  }
  auto Z = MinCostFlow<LL>(2 + R * C + R * C + 5);
  int SRC = 0;
  int TGT = 2 * R * C + 1;
  rep(i, 0, R) rep(j, 0, C)
  {
    int u = 1 + 0 * R * C + i * C + j;
    int v = 1 + 1 * R * C + i * C + j;
    if (A[i][j] == 'M')
    {
      Z.add_edge(SRC, u, 1, 0);
    }
    if (B[i][j] == 'M')
    {
      Z.add_edge(v, TGT, 1, 0);
    }
  }
  rep(a, 0, R) rep(b, 0, C) if (A[a][b] == 'M')
      rep(i, 0, R) rep(j, 0, C) if (B[i][j] == 'M')
  {
    int u = 1 + 0 * R * C + a * C + b;
    int v = 1 + 1 * R * C + i * C + j;
    if(A[a][b]!=B[a][b]&&A[i][j]!=B[i][j])
    Z.add_edge(u, v, 1, S * (fabs(a - i) + fabs(b - j)));
  }
  greedy = 0;
  rep(i,0,R)rep(j,0,C){
    if(A[i][j]!=B[i][j])greedy+=F;
  }
  auto res = Z.mincostflow(SRC, TGT);
  cout << res << endl;
}

int main()
{
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    printf("Case #%d: ", CA);
    solve();
  }
  return 0;
}