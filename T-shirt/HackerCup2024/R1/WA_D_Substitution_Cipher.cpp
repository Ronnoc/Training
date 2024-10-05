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
const LL MOD = 998244353;
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

const int MXN = 100005;

char E[MXN];
int e[MXN];
LL dp[MXN];

LL C[MXN][11];

void solve(){
  scanf("%s", E);
  int ne = strlen(E);
  DRI(K);
  rep(i,0,ne) {
    if(E[i]!='?')
      e[i+1] = E[i] - '0';
    else
      e[i+1]=1;
  }
  rep(i,0,ne+1)dp[i]=0;
  dp[0]=1;
  rep(i,1,ne+1){
    dp[i]=0;
    if(e[i]!=0)dp[i]+=dp[i-1];
    if(i>1 && e[i-1]!=0){
      int w = e[i-1]*10+e[i];
      if(1<=w && w<=26)
        dp[i]+=dp[i-2];
    }
    dp[i]%=MOD;
  }
  cout<<dp[ne]<<endl;
  rep(i,0,ne+2)rep(j,0,10)C[i][j]=0;
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
  fflush(stdout);
  return 0;
}