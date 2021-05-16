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
  VI L;
  int x;
  DRI(n);
  cin >> x;
  rep(i, 0, n)
  {
    DRI(t);
    L.PB(t);
  }
  int ans = 0;
  int last = L.SZ - 1;
  while (last > 0 && L[last - 1] <= L[last])
    last--;
  if (last == 0)
  {
    cout << 0 << endl;
    return;
  }
  rep(i, 0, last + 1)
  {
    if (L[i] > x)
    {
      swap(x, L[i]);
      ans++;
    }
  }
  // rep(i, 0, n) cout << L[i] << " ";
  // cout << "x" << x << endl;
  last = L.SZ - 1;
  while (last > 0 && L[last - 1] <= L[last])
    last--;
  if (last == 0)
  {
    cout << ans << endl;
    return;
  }
  cout << -1 << endl;
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
/*
6
4 1
2 3 5 4
5 6
1 1 3 4 4
1 10
2
2 10
11 9
2 10
12 11
5 18
81 324 218 413 324
*/