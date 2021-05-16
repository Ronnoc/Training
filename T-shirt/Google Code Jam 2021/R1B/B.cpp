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

LL S[55][22];
LL U[22];
LL T[22];
void solve()
{
  LL N, A, B;
  cin >> N >> A >> B;
  memset(U, 0, sizeof U);
  rep(i, 1, N + 1) cin >> U[i];
  memset(S, 0, sizeof S);
  memset(T, 0, sizeof T);
  for (int i = 1;; ++i)
  {
    if (i <= 20)
      S[i][i] = 1;
    else
    {
      rep(j, 1, 21) S[i % 40][j] = S[(i - A) % 40][j] + S[(i - B) % 40][j];
    }
    bool exit = false;
    rep(j, 1, 21) if (S[i][j] >= 1000000) exit = true;
    if (exit)
    {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
    memset(T, 0, sizeof T);
    rep(j, 1, 21) T[j] = S[(i % 40)][j];
    bool succ = true;
    for (int j = 20; j >= 1; j--)
    {
      // cout << "@" << i << "?" << j << " ";
      // rep(k, 1, 21) cout << T[k] << " ";
      // cout << endl;
      if (T[j] < U[j])
      {
        // cout << "fail" << endl;
        succ = false;
        break;
      }
      if (T[j] > U[j])
      {
        LL x = T[j] - U[j];
        T[j] -= x;
        if (j > B)
          T[j - B] += x;
        if (j > A)
          T[j - A] += x;
      }
    }
    if (succ)
    {
      cout << i << endl;
      return;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return;
}

int main()
{
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    printf("Case #%d: ", CA);
    fflush(stdout);
    solve();
  }
  return 0;
}
/*
1
20 1 2
20 20 20 20 20
20 20 20 20 20
20 20 20 20 20
20 20 20 20 20
*/