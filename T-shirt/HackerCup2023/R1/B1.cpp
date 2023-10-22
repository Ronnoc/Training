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

map<pair<PII,int>,int>dp,pre;

int dfs(int P, int sum, int mx){
  if(dp.count(MP(MP(P, sum), mx)) != 0 ){
    return dp[MP(MP(P, sum), mx)];
  }
  int ret = -1;
  if(sum == 0){
    if(P==1)return 0;
    return -1;
  }
  if(P==1){
    if( ret == -1 || ret > sum){
      pre[MP(MP(P, sum), mx)] = 1;
      ret = sum;
    }
  }
  for(int i=min(sum,mx);i>=2;i--)if(P%i == 0){
    int tmp = dfs(P/i,sum-i,i);
    if(tmp != -1){
      if (ret == -1 || ret > tmp){
        ret = tmp + 1;
        pre[MP(MP(P, sum), mx)] = i;
      }
    }
  }
  // cerr<<P<<" "<<sum<<" "<<mx<<"->"<<ret<<"\n";
  return dp[MP(MP(P, sum), mx)]=ret;
}

void solve(){
  DRI(P);
  int ret = dfs(P,41,41);
  int sum = 41;
  if(ret == -1){
    printf(" -1\n");
    return;
  }
  int cur = P;
  int mx=41;
  VI ans;
  while(sum){
    int x = pre[MP(MP(cur, sum), mx)];
    if(x!=1){
      cur /=x;
      sum-=x;
      mx=x; 
    }else {
      rep(i,0,sum)ans.PB(x);
      break;
    }
    ans.PB(x);
    if(ans.SZ > 100)break;
  }
  printf(" %d",ans.SZ);
  for(auto x:ans)printf(" %d",x);
  printf("\n");
}

int main()
{
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    printf("Case #%d:", CA);
    solve();
  }
  fflush(stdout);
  return 0;
}