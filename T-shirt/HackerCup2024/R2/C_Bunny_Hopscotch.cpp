#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X)                                                                 \
  int(X);                                                                      \
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
LL modPow(LL a, LL b, LL MOD) {
  LL ret = 1;
  for (; b; b >>= 1) {
    if (b & 1)
      ret = ret * a % MOD;
    a = a * a % MOD;
  }
  return ret;
}

int R, C;
LL K;
int B[803][803];

LL ANS[803];

LL readInt() {
  bool minus = false;
  LL result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-')
      break;
    if (ch >= '0' && ch <= '9')
      break;
    ch = getchar();
  }
  if (ch == '-')
    minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9')
      break;
    result = result * 10 + (ch - '0');
  }
  if (minus)
    return -result;
  else
    return result;
}

VPII loc[640005];

void update_less(int id, int mul) {
  //   cerr << "less" << id << " " << loc[id].size() << endl;
  rep(i, 0, loc[id].size()) {
    rep(j, i + 1, loc[id].size()) {
      int i1 = loc[id][i].AA, i2 = loc[id][j].AA;
      int j1 = loc[id][i].BB, j2 = loc[id][j].BB;
      int score = max(abs(i1 - i2), abs(j1 - j2));
      ANS[score] += 2 * mul;
    }
  }
}

int V[803][803];
int Z[803];

inline int zoom(int x1, int y1, int x2, int y2) {
  x2 = min(x2, R - 1);
  y2 = min(y2, C - 1);
  int res = V[x2][y2];
  if (x1 >= 1)
    res -= V[x1 - 1][y2];
  if (y1 >= 1)
    res -= V[x2][y1 - 1];
  if (x1 >= 1 && y1 >= 1)
    res += V[x1 - 1][y1 - 1];
  return res;
}

void update_more(int id, int mul) {
  //   cerr << "more" << id << " " << loc[id].size() << endl;
  rep(i, 0, R) rep(j, 0, C) { V[i][j] = (B[i][j] == id) ? 1 : 0; }
  rep(i, 0, R) rep(j, 1, C) V[i][j] += V[i][j - 1];
  rep(i, 1, R) rep(j, 0, C) V[i][j] += V[i - 1][j];
  memset(Z, 0, sizeof Z);
  // cerr<<"@query"<<id<<" "<<mul<<endl;
  // rep(i,0,R){
  //   rep(j,0,C)cerr<<V[i][j]<<" ";
  //   cerr<<endl;
  // }

  int loc_sz = loc[id].size();
  int mrc = max(R,C);
  rep(i, 0, R) rep(j, 0, C) if (B[i][j] == id) {
    // int xd = max(i, j);
    // xd = max(xd, abs(R - 1 - i));
    // xd = max(xd, abs(C - 1 - j));
    rep(d, 1, mrc) {
      Z[d] += zoom(i - (d), j - (d), i + (d), j + (d)) - 1;
    }
  }
  for (int d = max(R, C); d >= 1; d--)
    Z[d] -= Z[d - 1];
  rep(d, 1, max(R, C)) ANS[d] += mul * Z[d];
}

void update(int id, int mul) {
  int cnt_id = loc[id].size();
  if (cnt_id < max(R, C)) {
    update_less(id, mul);
  } else {
    update_more(id, mul);
  }
}

void readInput() {
  R = readInt();
  C = readInt();
  K = readInt();
  rep(i, 0, R) {
    rep(j, 0, C) { B[i][j] = readInt(); }
  }
}

void fakeInput(int d) {
  R = d;
  C = d;
  K = 1;
  rep(i, 0, R) {
    rep(j, 0, C) { B[i][j] = i + 1; }
  }
}

void solve(int is_fake = 0, int skip=0) {
  if (is_fake)
    fakeInput(800);
  else
    readInput();
  if(skip)return;

  rep(d, 0, max(R, C)) { ANS[d] = 0; }
  rep(x, 1, R * C + 1) loc[x].clear();

  rep(i, 0, R) {
    rep(j, 0, C) { loc[B[i][j]].emplace_back(i, j); }
  }
  rep(x, 1, R * C + 1) if (loc[x].size()) {
    update(x, -1);
  }

  loc[0].clear();
  rep(i, 0, R) {
    rep(j, 0, C) {
      B[i][j] = 0;
      loc[0].emplace_back(i, j);
    }
  }
  update(0, 1);

  rep(d, 1, max(R, C)) {
    if (K <= ANS[d]) {
      printf("%d\n", d);
      return;
    }
    K -= ANS[d];
  }
  printf("%d\n", max(R,C)-1);
  cerr<<"K remain"<<K<<endl;
}

int main() {
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  if (_T == 0) {
    solve(1);
  }
  for (int CA = 1; CA <= _T; CA++) {
    printf("Case #%d: ", CA);
    solve(0, 0);
    cerr << "\nCase #" << CA << " of " << _T << " done." << endl;
  }
  fflush(stdout);
  return 0;
}