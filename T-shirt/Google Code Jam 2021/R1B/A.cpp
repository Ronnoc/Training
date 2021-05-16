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

LL FULL = 360LL * 12LL * 10000000000LL;

// This means that the hours hand rotates exactly 1 tick each nanosecond,
// the minutes hand rotates exactly 12 ticks each nanosecond
// the seconds hand rotates exactly 720 ticks each nanosecond.
bool valid(LL H, LL M, LL S)
{
  for (int _r = 0; _r < 12; _r++)
  {
    // rh = deg + t*1
    // rm = deg + t*12
    // rs = deg + t*720
    LL ele_x = M + _r * FULL;
    if (ele_x >= H && (ele_x - H) % 11 == 0)
    {
      LL t = (ele_x - H) / 11;
      LL deg = H - t;
      LL rh = deg + t * 1;
      LL rm = deg + t * 12;
      LL rs = deg + t * 720;
      rh %= FULL;
      rm %= FULL;
      rs %= FULL;
      if (rh == H && rm == M && rs == S)
      {
        // cout << t << endl;
        LL ns = t % 1000000000LL;
        t -= ns;
        t /= 1000000000LL;
        LL s = t % 60;
        t -= s;
        t /= 60LL;
        LL m = t % 60;
        t -= m;
        t /= 60;
        LL h = t % 24;
        t -= h;
        t /= 24;
        cout << h << " " << m << " " << s << " " << ns << endl;
        return true;
      }
    }
  }
  return false;
}

void solve()
{
  LL A, B, C;
  cin >> A >> B >> C;
  if (valid(A, B, C))
    return;
  if (valid(A, C, B))
    return;
  if (valid(B, A, C))
    return;
  if (valid(B, C, A))
    return;
  if (valid(C, A, B))
    return;
  if (valid(C, B, A))
    return;
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