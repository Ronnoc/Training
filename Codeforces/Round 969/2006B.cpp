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

const int N = 200005;

// H[edge_i]={dist_j}
vector<int>H[N];

// for tree
// vector<int>G[N];
int fa[N];
int dep[N];
int cov[N];

void solve(){
    LL n;
    cin>>n;
    LL w;
    cin>>w;
    rep(i,1,n+1){
        H[i].clear();
        fa[i]=-1;
        dep[i]=-1;
        cov[i]=0;
    }
    dep[1]=0;
    rep(i,2,n+1){
        RI(fa[i]);
        dep[i]=dep[fa[i]]+1;
    }
    rep(i,1,n+1){
        int u = i;
        int v = i%n+1;
        while(u!=v){
            if (dep[u]>dep[v]){
                H[u].PB(i);
                u=fa[u];
                cov[i]++;
            }else if (dep[u]<dep[v]){
                H[v].PB(i);
                v=fa[v];
                cov[i]++;
            }else {
                H[u].PB(i);
                H[v].PB(i);
                u=fa[u];
                v=fa[v];
                cov[i]+=2;
            }
        }
    }
    LL sy=0;
    LL freeDist = n;
    rep(_,1,n){
        int x;LL y;
        cin>>x>>y;
        sy+=y;
        // cerr<<"set "<<x<<" to "<<y<<" | ";
        for(auto i:H[x]){
            cov[i]--;
            // cerr<<"("<<i<<","<<cov[i]<<") ";
            if (cov[i]==0){
                freeDist--;
            }
        }
        // cerr<<"freeDist="<<freeDist<<",(w-sy)="<<w-sy<<",(sy)"<<sy<<endl;
        LL ans = freeDist*(w-sy)+2LL*sy;
        if(_!=1){
            cout<<" ";
        }
        cout<<ans;
    }
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