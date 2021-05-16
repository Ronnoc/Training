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

const int MXN = 100000 + 10;
vector<int> G[MXN];

int V[MXN];
LL extGcd(LL a, LL b, LL &x, LL &y)
{
  LL ret = a;
  if (b)
  {
    ret = extGcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  else
    x = 1, y = 0;
  return ret;
}

LL modInv(LL a, LL m)
{
  LL x, y;
  extGcd(a, m, x, y);
  return (m + x % m) % m;
} //if m为质数 [费马小定理]a^(m-1)=1 mod m ==>a^(m-2)是a关于m的逆元

LL JC[MXN];
LL JCN[MXN];

struct SEG
{
  int v, vid;
  int l, r, m, lazy;
  SEG(int _l = 0, int _r = 0) { l = _l, r = _r; }
} SGT[MXN << 2 | 1];
void create(SEG &T, int t)
{
  T.m = 0;
  T.lazy = 0;
  T.v = V[t];
  T.vid = t;
}
void fresh(SEG &T, SEG &L, SEG &R)
{
  if (L.v < R.v)
  {
    T.v = L.v;
    T.vid = L.vid;
  }
  else
  {
    T.v = R.v;
    T.vid = R.vid;
  }
}
void build(int id, int l, int r)
{
  SGT[id] = SEG(l, r);
  int mid = (l + r) / 2;
  if (l != r)
  {
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    fresh(SGT[id], SGT[id << 1], SGT[id << 1 | 1]);
  }
  else
    create(SGT[id], l);
}
void update(int id, int l, int r, int w)
{
  SEG &T = SGT[id];
  int mid = (T.l + T.r) / 2;
  if (T.l == l && T.r == r)
  {
    T.m = w;
    return;
  }
  if (T.lazy)
  {
    update(id << 1, T.l, mid, T.lazy);
    update(id << 1 | 1, mid + 1, T.r, T.lazy);
    T.lazy = 0;
  }
  if (r <= mid)
    update(id << 1, l, r, w);
  else if (l > mid)
    update(id << 1 | 1, l, r, w);
  else
  {
    update(id << 1, l, mid, w);
    update(id << 1 | 1, mid + 1, r, w);
  }
  fresh(T, SGT[id << 1], SGT[id << 1 | 1]);
}
void query(int id, SEG &A)
{
  SEG &T = SGT[id];
  if (T.lazy)
  {
    int mid = (T.l + T.r) / 2;
    update(id << 1, T.l, mid, T.lazy);
    update(id << 1 | 1, mid + 1, T.r, T.lazy);
    T.lazy = 0;
  }
  if (T.l == A.l && T.r == A.r)
  {
    A = T;
    return;
  }
  int mid = (T.l + T.r) / 2;
  if (A.r <= mid)
    query(id << 1, A);
  else if (A.l > mid)
    query(id << 1 | 1, A);
  else
  {
    SEG L(A.l, mid), R(mid + 1, A.r);
    query(id << 1, L);
    query(id << 1 | 1, R);
    fresh(A, L, R);
  }
}

LL recur(int l, int r, int d = 0)
{
  // cout << "query " << l << " ~ " << r << " d=" << d << "?vl" << V[l] << endl;
  if (l == r)
  {
    if (V[l] == d + 1)
      return 1;
    return 0;
  }
  SEG A;
  A.l = l, A.r = r;
  A.v = MXN;
  A.vid = MXN;
  query(1, A);
  int p = A.vid;
  if (V[p] != d + 1)
    return 0;
  // cout << "split @ " << p << endl;
  LL ans = JC[r - l] * JCN[p - l] % MOD * JCN[r - p] % MOD;
  // cout << ans << endl;
  if (p - 1 >= l)
    ans = ans * recur(l, p - 1, d) % MOD;
  if (r >= p + 1)
    ans = ans * recur(p + 1, r, d + 1) % MOD;
  return ans;
}

void solve()
{
  rep(i, 0, MXN) G[i].clear();
  memset(V, 0, sizeof(V));
  DRI(N);
  rep(i, 0, N)
  {
    RI(V[i]);
  }
  build(1, 0, N - 1);

  LL ans = recur(0, N - 1);
  cout << ans << endl;
}

int main()
{
  JC[0] = 1;
  JCN[0] = 1;
  rep(i, 1, MXN)
  {
    JC[i] = JC[i - 1] * i % MOD;
    JCN[i] = JCN[i - 1] * modInv(i, MOD) % MOD;
  }
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    printf("Case #%d: ", CA);
    solve();
  }
  return 0;
}