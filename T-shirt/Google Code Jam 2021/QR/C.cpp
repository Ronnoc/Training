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
void solve()
{
  DRI(n);
  DRI(c);
  VI L;
  rep(i, 0, n) L.PB(i + 1);
  VPII X;
  int nxt = 1;
  c -= n - 1;
  rep(i, 0, n)
  {
    int l = n - 1 - i;
    if (c >= l)
    {
      X.PB(MP(i, i + l + 1));
      c -= l;
    }
    else if (c >= 0)
    {
      X.PB(MP(i, i + c + 1));
      c -= c;
    }
  }

  if (c > 0 || c < 0)
    printf("IMPOSSIBLE\n");
  else
  {
    reverse(X.OP, X.ED);
    rep(i, 0, X.SZ)
    {
      PII pr = X[i];
      reverse(L.begin() + pr.AA, L.begin() + pr.BB);
    }
    rep(i, 0, n)
    {
      if (i)
        printf(" ");
      printf("%d", L[i]);
    }
    printf("\n");
  }
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
