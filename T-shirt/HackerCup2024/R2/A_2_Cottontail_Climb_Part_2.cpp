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
const LL MOD = 1000000007;
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

vector<LL> ANS;
void solve() {
  LL A, B, M;
  cin >> A >> B >> M;
  int ans = 0;
  for (auto t : ANS) {
    if (A <= t && t <= B && t % M == 0)
      ans++;
  }
  cout << ans;
  cout << endl;
}

int dig[23];
void dfs(int k, int i, LL pre) {
  if (i == 2 * k + 1) {
    ANS.PB(pre);
    return;
  }
  if (i == 0) {
    rep(d, 1, 10) {
      dig[i] = d;
      dfs(k, i + 1, pre * 10 + d);
    }
    return;
  }
  if (i == k) {
    // enumurate peak
    rep(d, dig[i - 1] + 1, 10) {
      dig[i] = d;
      dfs(k, i + 1, pre * 10 + d);
    }
    return;
  }
  if (i < k) {
    rep(d, dig[i - 1], 10) {
      dig[i] = d;
      dfs(k, i + 1, pre * 10 + d);
    }
    return;
  }
  if (i == k + 1) {
    rep(d, 1, dig[i - 1]) {
      dig[i] = d;
      dfs(k, i + 1, pre * 10 + d);
    }
    return;
  }
  if (i > k) {
    rep(d, 1, dig[i - 1] + 1) {
      dig[i] = d;
      dfs(k, i + 1, pre * 10 + d);
    }
    return;
  }
}

int main() {
  rep(k, 0, 9) {
    dfs(k, 0, 0);
    cerr << k << " " << ANS.SZ << endl;
  }
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++) {
    printf("Case #%d: ", CA);
    solve();
    cerr << "Case #" << CA << " of " << _T << " done." << endl;
  }
  fflush(stdout);
  return 0;
}