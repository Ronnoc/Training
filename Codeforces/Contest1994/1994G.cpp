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

const int MXN = 2000007;

char s[MXN];
char buf[MXN];
int w[MXN];
int c[MXN];
int d[MXN];
int r[MXN];
vector<vector<int>>dp,pre;

void solve(){
    DRI(n);
    DRI(k);
    scanf("%s", s);
    rep(i,0,k)w[i]=s[i]-'0';
    rep(i,0,k)c[i]=0;
    rep(i,0,n){
        scanf("%s", buf);
        rep(j,0,k){
            c[j]+=buf[j]-'0';
        }
    }
    rep(j,0,k){
        int p = n-c[j];
        int q = c[j];
        if(p>=q)r[j]=0;
        else r[j]=1;
        int dpq = min(p,q);
        w[j]-=dpq;
        d[j] = p + q - 2*dpq;
    }
    repd(j,k-1,1){
        int hwj = w[j]/2;
        w[j-1]+=hwj;
        w[j]-=hwj*2;
        if(w[j]<0){
            w[j]+=2;
            w[j-1]--;
        }
    }
    if(w[0]<0){
        cout<<-1<<endl;
        return;
    }
    pre.clear();
    dp.clear();
    pre.resize(k+1,vector<int>(n+1,-1));
    dp.resize(k+1,vector<int>(n+1,0));
    // \sum a_i * d_i * 2^(n-i) = \sum w_i * 2^(n-i)
    // a_i \belong {0,1}
    // d_i <= n
    // w_i >= 0
    // use dp to solve this problem
    // dp[p][q] means \sum_0^p a_i * d_i * 2^(n-i) = q*2^(n-p)
    // dp[*][*] = 0
    // pre[*][*] = -1
    dp[0][w[0]]=1;
    pre[0][w[0]]=0;
    if(w[0]-d[0]>=0){
        pre[0][w[0]-d[0]]=1;
        dp[0][w[0]-d[0]]=1;
    }
    // dp[p][q] -> dp[p+1][2q-d[p+1]] ; pre[p+1][2q-d[p+1]] = 1
    // dp[p][q] -> dp[p+1][2q] ; pre[p+1][2q-d[p+1]] = 0
    // cerr<<"w";rep(i,0,k)cerr<<w[i]<<" ";cerr<<endl;
    // cerr<<"d";rep(i,0,k)cerr<<d[i]<<" ";cerr<<endl;
    rep(p,0,k-1){
        rep(q,0,n+1){
            if(dp[p][q]){
                int qq = 2*q+w[p+1];
                // cerr<<"@p="<<p<<" q="<<q<<" -> qq="<<qq<<" pre="<<pre[p][q]<<endl;
                if(qq-d[p+1]<=n && qq-d[p+1]>=0){
                    dp[p+1][qq-d[p+1]]=1;
                    pre[p+1][qq-d[p+1]]=1;
                }
                if(qq<=n){
                    if(dp[p+1][qq]==0){
                        dp[p+1][qq]=1;
                        pre[p+1][qq]=0;
                    }
                }
            }
        }
    }
    if(dp[k-1][0]==0){
        cout<<-1<<endl;
        return;
    }
    int p = k-1;
    int q = 0;
    vector<int>ans;
    while(p>=0){
        // cerr<<"?p="<<p<<" q="<<q<<" pre="<<pre[p][q]<<endl;
        if(pre[p][q]==1){
            ans.PB(1);
            q = (q+d[p])/2;
        }else{
            ans.PB(0);
            q = q/2;
        }
        p--;
    }
    reverse(all(ans));
    rep(i,0,k)cout<<int(ans[i]^r[i]);
    cout<<endl;
}

int main()
{
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    // printf("Case #%d:", CA);
    solve();
  }
  fflush(stdout);
  return 0;
}