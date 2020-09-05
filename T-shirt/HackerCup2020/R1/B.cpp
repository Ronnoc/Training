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
vector<LL> P, Q;
bool solvable(int s, LL t)
{
  int iq = 0;
  for (int ip = 0; ip < P.SZ; ++ip)
  {
    if (iq == Q.size())
      break;
    int save_iq = iq;
    LL tr = t;
    LL visLe, visRe, cur;
    cur = Q[iq];
    visLe = min(P[ip], Q[iq]);
    visRe = max(P[ip], Q[iq]);
    tr -= visRe - visLe;
    tr -= s;
    if (tr < 0)
      continue;
    iq++;
    while (iq < Q.size())
    {
      LL nq = Q[iq];
      tr -= s;
      if (nq > visRe)
      {
        tr -= nq - cur;
        cur = nq;
      }
      if (tr >= 0)
        iq++;
      else
        break;
    }
    if (iq > save_iq)
    {
      int left_iq = iq;
      iq = save_iq;
      tr = t;
      cur = P[ip];
      int niq = iq;
      while (niq < Q.SZ)
      {
        LL left = Q[iq];
        LL right = Q[niq];
        if (P[ip] < left)
        {
          if (tr >= s * (niq + 1 - iq) + right - P[ip])
            niq++;
          else
            break;
        }
        else if (P[ip] > right)
        {
          if (tr >= s * (niq + 1 - iq) + P[ip] - left)
            niq++;
          else
            break;
        }
        else
        {
          if (tr >= s * (niq + 1 - iq) + P[ip] - left + right - left)
            niq++;
          else if (tr >= s * (niq + 1 - iq) + right - P[ip] + right - left)
            niq++;
          else
            break;
        }
      }
      int right_iq = niq;
      iq = max(left_iq, right_iq);
    }
  }
  return iq == Q.size();
}

void solve()
{
  DRI(n);
  DRI(m);
  DRI(k);
  DRI(s);
  P.clear();
  Q.clear();
  rep(i, 0, k)
  {
    DRI(x);
    P.PB(x);
  }
  DRI(ap);
  DRI(bp);
  DRI(cp);
  DRI(dp);
  rep(i, 0, k)
  {
    DRI(x);
    Q.PB(x);
  }
  DRI(aq);
  DRI(bq);
  DRI(cq);
  DRI(dq);
  rep(i, k, n)
  {
    LL np = (1LL * ap * P[i - 2] + 1LL * bp * P[i - 1] + cp) % dp + 1;
    P.PB(np);
  }
  rep(i, k, m)
  {
    LL nq = (1LL * aq * Q[i - 2] + 1LL * bq * Q[i - 1] + cq) % dq + 1;
    Q.PB(nq);
  }
  sort(all(P));
  sort(all(Q));
  LL mxc = 1LL * s * Q.SZ + 2LL * (max(*max_element(all(P)), *max_element(all(Q))) -
                                   min(*min_element(all(P)), *min_element(all(Q))));
  LL le = 0, re = mxc, ge = -1;
  while (re >= le)
  {
    if (re - le <= 1)
    {
      if (solvable(s, le))
        ge = le;
      else
        ge = re;
      break;
    }
    LL me = (le + re) / 2;
    bool valid = solvable(s, me);
    if (valid)
      re = me;
    else
      le = me;
  }
  cout << ge << "\n";
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
/*
1
3 3 3 0
9 100 200
0 0 0 0
1 10 11
0 0 0 0
*/