#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X)                                                                 \
  int(X);                                                                      \
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
const LL MOD = 998244353;
const long double PI = acos(-1.);
const long double eps = 1e-9;
LL modPow(LL a, LL b, LL MOD) {
  LL ret = 1;
  for (; b; b >>= 1) {
    if (b & 1)
      ret = ret * a % MOD;
    a = a * a % MOD;
  }
  return ret;
}

LL F[2][503][503];
LL G[2][503][503];

LL SF[503], SG[503];

LL dp[503][503];

inline void update(LL &a, LL b) { a = (a + b) % MOD; }

void solve() {
  DRI(n);
  DRI(m);

  rep(i, 0, 2) rep(j, 0, m + 1) rep(k, 0, m + 1) F[i][j][k] = 0;
  rep(i, 0, 2) rep(j, 0, m + 1) rep(k, 0, m + 1) G[i][j][k] = 0;

  F[0][0][0] = 1;
  int curf = 0;
  rep(i, 0, m) {
    int nxtf = curf ^ 1;
    rep(j, 0, m + 1) rep(k, 0, m + 1) F[nxtf][j][k] = 0;
    rep(j, 0, m + 1) rep(k, 0, m + 1) if (F[curf][j][k]) {
      if (j > 0)
        update(F[nxtf][j - 1][k], F[curf][j][k]);
      update(F[nxtf][j + 1][k + 1], F[curf][j][k]);
    }
    curf = nxtf;
  }

  rep(j, 0, m + 1) SF[j] = 0;
  rep(j, 0, m + 1) rep(k, 0, m + 1) {
    if (F[curf][j][k]) {
      // cerr<<j<<" "<<k<<" "<<F[curf][j][k]<<endl;
      // assert(j == k-(m-k));
      SF[k] = F[curf][j][k];
      // cerr<<"SF["<<k<<"] = "<<SF[k]<<endl;
    }
  }

  int curg = 0;
  G[0][0][0] = 1;
  rep(i, 0, m) {
    int nxtg = curg ^ 1;
    rep(j, 0, m + 1) rep(k, 0, m + 1) G[nxtg][j][k] = 0;
    rep(j, 0, m + 1) rep(k, 0, m + 1) if (G[curg][j][k]) {
      if (j > 0)
        update(G[nxtg][j - 1][k + 1], G[curg][j][k]);
      update(G[nxtg][j + 1][k], G[curg][j][k]);
    }
    curg = nxtg;
  }
  rep(j, 0, m + 1) SG[j] = 0;
  rep(j, 0, m + 1) rep(k, 0, m + 1) {
    if (G[curg][j][k]) {
      // cerr<<j<<" "<<k<<" "<<G[curg][j][k]<<endl;
      // assert(j == (m-k)-k);
      SG[k] = G[curg][j][k];
      // cerr<<"SG["<<k<<"] = "<<SG[k]<<endl;
    }
  }

  rep(j, 0, n + 1) rep(k, 0, m + 1) dp[j][k] = 0;
  rep(k, 0, m + 1) if (k >= m - k) update(dp[0][k - (m - k)], SF[k]);
  rep(i, 0, n - 1) {
    rep(j, 0, m + 1) if (dp[i][j]) {
      // cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
      rep(k, 0, m + 1) if (SG[k]) {
        int t = (m - k) - k;
        if(t<=j)
          update(dp[i + 1][j - t], 1LL * dp[i][j] * SG[k] % MOD);
      }
    }
  }
  cout << dp[n - 1][0] << endl;
}

int main() {
  int i, j, k, _T = 1;
  // scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++) {
    // printf("Case #%d:", CA);
    solve();
  }
  fflush(stdout);
  return 0;
}