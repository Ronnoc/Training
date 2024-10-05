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
const LL MOD = 998244353;
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

char S[27][101];
LL dp[1 << 25 | 1];
LL sum[1 << 25 | 1];
char pm[1 << 25 | 1];
int nxt[1 << 25 | 1];

void solve()
{
  DRI(n);
  memset(S, 0, sizeof S);
  rep(i, 0, n) scanf("%s", S[i]);

  rep(mask, 0, 1 << n) dp[mask] = 1;
  rep(mask, 0, 1 << n) sum[mask] = 1;
  rep(mask, 0, 1 << n) nxt[mask] = -1;
  rep(mask, 1, 1 << n) nxt[mask - 1] = mask;

  rep(d, 0, 100)
  {
    pm[0] = '?';
    for (int mask = nxt[0]; mask != -1; mask = nxt[mask])
    {
      int ld = mask & -mask;
      int ild = __builtin_ctz(ld);
      char &ch = S[ild][d];
      char &pre = pm[mask ^ ld];
      if (ch == 0)
        pm[mask] = '$';
      else if (ch == '?')
        pm[mask] = pre;
      else
      {
        if (pre == '?')
          pm[mask] = ch;
        else if (pre == ch)
          pm[mask] = ch;
        else
          pm[mask] = '$';
      }
    }

    int pre = 0;
    for (int mask = nxt[0]; mask != -1; mask = nxt[mask])
    {
      char ch = pm[mask];
      if (ch == '$')
        dp[mask] = 0;
      else if (ch == '?')
      {
        dp[mask] = dp[mask] * 26 % MOD;
      }
      sum[mask] = sum[mask] + dp[mask];
      if (dp[mask] == 0)
      {
        nxt[pre] = nxt[mask];
      }
        else pre = mask;
    }
  }

  LL final_ans = 0;
  rep(mask, 1, 1 << n)
  {
    LL c = __builtin_popcount(mask);
    LL ans = sum[mask];
    if (c & 1)
      final_ans += ans;
    else
      final_ans -= ans;
  }
  cout << (final_ans % MOD + MOD) % MOD << endl;
}

int main()
{
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    cerr << "solving case " << CA << endl;
    printf("Case #%d: ", CA);
    solve();
  }
  fflush(stdout);
  return 0;
}