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

LL T, N, B;

vector<int> L;

void gao(int f)
{
  L[f] += 1;
  printf("%d\n", f + 1);
  fflush(stdout);
}
void solve()
{
  L.resize(N);
  rep(i, 0, N) L[i] = 0;
  rep(_t, 0, N * B)
  {
    DRI(x);
    bool ok = false;
    int not_f = 0;
    rep(i, 0, N) if (L[i] < B) not_f += 1;
    int per_9 = int((N * B - _t) * (1.0 - (x + 1) * 0.1) / not_f);
    while (!ok)
    {
      rep(i, 0, N) if (L[i] + per_9 < B)
      {
        gao(i);
        ok = true;
        break;
      }
      per_9 -= 1;
    }
  }
}
int main()
{
  double P;
  cin >> T >> N >> B >> P;
  rep(_t, 0, T)
      solve();
  return 0;
}