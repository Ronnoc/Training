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

const int MXN = 200005;
int d[MXN];
int a[MXN];

void solve(){
    DRI(n);
    DRI(m); // per day
    DRI(k); // keep day
    rep(i,0,n){
        RI(d[i]);
        RI(a[i]);
        a[i]=min(1LL*a[i],1LL*m*k);
    }
    int dx = 2000000;
    int dy = 2000000;
    int tofill = m;
    stack<tuple<int,int,int>>S;
    S.emplace(dx,dy,tofill);
    // [d_x,d_y) are ok, need m to make d_y ok
    repd(i,n-1,0){
        int dq = d[i];
        int qa = a[i];
        int t = a[i]/m;
        int r = a[i]%m;
        tuple<int,int,int> now = {dq,dq+t,m-r};
        while(true){
            tuple<int,int,int> cur = S.top();
            int c0 = get<0>(cur);
            int c1 = get<1>(cur);
            int c2 = get<2>(cur);
            int n0 = get<0>(now);
            int n1 = get<1>(now);
            int n2 = get<2>(now);
            // if we could not merge
            if(n1<c0){
                S.push(now);
                break;
            }
            // n1>=c0
            int r=m-n2+(n1-c0)*m;
            if(c1<n0+k){
                if(c2<=r){
                    r-=c2;
                    int tr=r/m;
                    int rr = r%m;
                    int z1 = c1+1+tr;
                    int z2 = m-rr;
                    if(z1>=n0+k){
                        z1=n0+k;
                        z2=0;
                    }
                    n1=z1;
                    n2=z2;
                }else {
                    n1 = c1;
                    n2 = c2 - r;
                }
            }else{
                // c1 already outdated
                n1 = c1;
                n2 = c2;
            }
            now = make_tuple(n0,n1,n2);
            S.pop();
        }
        
    }
    int ans = 0;
    while(!S.empty()){
        tuple<int,int,int> cur = S.top();
        S.pop();
        int c0 = get<0>(cur);
        int c1 = get<1>(cur);
        int c2 = get<2>(cur);
        ans += c1-c0;
    }
    cout<<ans<<endl;
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