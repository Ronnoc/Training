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

vector<LL> L, H;
void solve()
{
  DRI(n);
  DRI(k);
  DRI(w);
  L.clear();
  H.clear();
  rep(i, 0, k)
  {
    DRI(x);
    L.PB(x);
  }
  DRI(al);
  DRI(bl);
  DRI(cl);
  DRI(dl);
  rep(i, 0, k)
  {
    DRI(x);
    H.PB(x);
  }
  DRI(ah);
  DRI(bh);
  DRI(ch);
  DRI(dh);
  rep(i, k, n)
  {
    LL nl = (1LL * al * L[i - 2] + 1LL * bl * L[i - 1] + cl) % dl + 1;
    L.PB(nl);
  }
  rep(i, k, n)
  {
    LL nh = (1LL * ah * H[i - 2] + 1LL * bh * H[i - 1] + ch) % dh + 1;
    H.PB(nh);
  }
  // rep(i,0,n)cout<<L[i]<<" ";cout<<"\n";
  // rep(i,0,n)cout<<H[i]<<" ";cout<<"\n";
  stack<pair<pair<LL, LL>, LL> > S;
  LL curP = 0;
  LL ans = 1;
  rep(i, 0, n)
  {
    if (S.empty())
    {
      S.push(MP(MP(L[i], L[i] + w), H[i]));
      curP += 2 * w + 2 * H[i];
    }
    else
    {
      while (S.SZ > 0)
      {
        auto stop = S.top();
        // cout<<"stop="<<stop.AA.AA<<","<<stop.AA.BB<<"^"<<stop.BB<<"@curp="<<curP<<"\n";
        if (stop.AA.BB < L[i])
        {
          S.push(MP(MP(L[i], L[i] + w), H[i]));
          curP += 2 * w + 2 * H[i];
          break;
        }
        else
        {
          S.pop();
          curP -= 2 * (stop.AA.BB - stop.AA.AA);
          if (stop.AA.AA >= L[i])
          {
            if (stop.BB >= H[i])
            {
              curP += 2 * (stop.AA.BB - stop.AA.AA);
              S.push(stop);
              // cout << "push1=" << stop.AA.BB << "," << L[i]+w << "^" << H[i] << "\n";
              S.push(MP(MP(stop.AA.BB, L[i] + w), H[i]));
              curP += 2 * (L[i] + w - stop.AA.BB);
              break;
            }
          }
          else
          {
            if (stop.BB >= H[i])
            {
              curP += 2 * (stop.AA.BB - stop.AA.AA);
              S.push(stop);
              // cout << "push2=" << stop.AA.BB << "," << L[i] + w << "^" << H[i] << "\n";
              S.push(MP(MP(stop.AA.BB, L[i] + w), H[i]));
              curP += 2 * (L[i] + w - stop.AA.BB);
              break;
            }
            else
            {
              S.push(MP(MP(stop.AA.AA, L[i]), stop.BB));
              curP += 2 * (L[i] - stop.AA.AA);
              // cout << "push3=" << L[i] << "," << L[i] + w << "^" << H[i] << "\n";
              S.push(MP(MP(L[i], L[i] + w), H[i]));
              curP += 2 * w + 2 * H[i] - 2 * stop.BB;
              break;
            }
          }
        }
      }
    }
    // cout << curP << ",";
    if (false)
    {
      set<LL> SX;
      rep(j, 0, i + 1) SX.insert(L[j]);
      rep(j, 0, i + 1) SX.insert(L[j] + w);
      vector<LL> X(all(SX));
      LL lasth = 0;
      LL newP = 0;
      rep(j, 1, X.SZ)
      {
        LL h = 0;
        LL le = X[j-1], re = X[j];
        rep(k, 0, i + 1)
        {
          if (L[k] + w >= re && le >= L[k])
            h = max(h, H[k]);
        }
        // cout<<j<<" "<<le<<"~"<<re<<" "<<h<<"\n";
        if (h > 0)
        {
          newP += 2 * (re - le);
          if (h > lasth)
            newP += 2 * (h - lasth);
        }
        lasth = h;
      }
      
      if (newP != curP){
        cerr << curP << "," << newP << "," << newP - curP << "\n";
        cerr << "!!!!!!\n";
        break;
      }
    }

    ans = ans * (curP % 1000000007) % 1000000007;
  }
  ans %= 1000000007;
  cout << ans << "\n";
}
/*
1
5 5 3
2 4 5 9 12
0 0 0 100
4 3 6 3 2
0 0 0 100
*/
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