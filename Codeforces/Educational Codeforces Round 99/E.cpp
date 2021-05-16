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

PLL fast(LL a, LL b)
{
  LL l = min(a, b);
  LL r = max(a, b);
  return MP(l, r);
}

void solve()
{
  VPLL L;
  rep(i, 0, 4)
  {
    DRI(x);
    DRI(y);
    L.PB(MP(x, y));
  }
  sort(all(L));
  LL ans = -1;
  do
  {
    PLL lx = fast(L[0].AA, L[1].AA);
    PLL rx = fast(L[2].AA, L[3].AA);
    PLL dy = fast(L[0].BB, L[3].BB);
    PLL uy = fast(L[1].BB, L[2].BB);
    LL cost = lx.BB - lx.AA + rx.BB - rx.AA + dy.BB - dy.AA + uy.BB - uy.AA;
    VL vx;
    vx.PB(rx.AA - lx.AA);
    vx.PB(rx.AA - lx.BB);
    vx.PB(rx.BB - lx.BB);
    vx.PB(rx.BB - lx.AA);
    sort(all(vx));
    PLL xx = MP(max(0LL, vx[0]), vx[3]);
    VL vy;
    vy.PB(uy.AA - dy.AA);
    vy.PB(uy.AA - dy.BB);
    vy.PB(uy.BB - dy.BB);
    vy.PB(uy.BB - dy.AA);
    sort(all(vy));
    PLL yy = MP(max(0LL, vy[0]), vy[3]);
    if (yy.BB >= 0 && xx.BB >= 0)
    {
      if (yy.BB < xx.AA)
      {
        cost += 2 * (xx.AA - yy.BB);
      }
      else if (xx.BB < yy.AA)
      {
        cost += 2 * (yy.AA - xx.BB);
      }
      if (ans == -1 || ans > cost)
      {
        ans = cost;
      }
    }
  } while (next_permutation(L.OP, L.ED));
  cout << ans << endl;
}

int main()
{
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    // printf("Case #%d: ", CA);
    solve();
  }
  return 0;
}