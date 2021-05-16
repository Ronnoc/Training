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
}

vector<int> L[1000005];

int B[1000005];
int A[1000005];
int main()
{
  int i, j, k, _T = 1;
  rep(i, 2, 1000001)
  {
    for (int j = i; j < 1000001; j += i)
      L[j].PB(i);
  }
  B[0] = 0;
  B[1] = 0;
  B[2] = 1;
  rep(i, 3, 1000001)
  {
    B[i] = 1;
    for (auto k : L[i])
    {
      B[i] = max(B[i], 1 + B[(i - k) / k]);
    }
  }
  A[0] = 0;
  A[1] = 0;
  A[2] = 0;
  A[3] = 1;
  rep(i, 4, 1000001)
  {
    A[i] = 1;
    for (auto k : L[i])
    {
      if (k >= 3)
        A[i] = max(A[i], 1 + B[(i - k) / k]);
    }
  }

  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    printf("Case #%d: ", CA);
    DRI(n);
    printf("%d\n", A[n]);
    // solve();
  }
  return 0;
}