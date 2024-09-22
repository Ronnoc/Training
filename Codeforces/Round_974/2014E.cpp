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

const int MXN = 200005;
VPII G[MXN];
int ih[MXN];
LL p[MXN<<1];
LL q[MXN<<1];

void Dijkstra(int s,int n,LL *d){
    priority_queue<PLL,vector<PLL>,greater<PLL> >Q;
    rep(i,1,n*2+2)d[i]=1LL<<60;
    d[s<<1]=0;
    Q.push(MP(0,s<<1));
    while(!Q.empty()){
        PLL tp=Q.top();Q.pop();
        int uh=tp.BB;
        int u=tp.BB>>1;
        int h=tp.BB&1;
        // cerr<<u<<" "<<h<<" "<<tp.AA<<endl;
        if(d[uh]<tp.AA)continue;
        rep(i,0,sz(G[u])){
            int v=G[u][i].AA;
            int nh = h | ih[u];
            LL w=G[u][i].BB;
            if(nh)w/=2;
            int vh=v<<1|nh;
            if(d[vh]>d[uh]+w){
                d[vh]=d[uh]+w;
                Q.push(MP(d[vh],vh));
            }
        }
    }
}

void solve(){
    DRI(n);
    DRI(m);
    DRI(h);
    rep(i,1,n+1)G[i].clear();
    rep(i,1,n+1)ih[i]=0;
    rep(i,1,h+1){
        DRI(a);
        ih[a]=1;
    }
    rep(i,1,m+1){
        DRI(u);
        DRI(v);
        DRI(w);
        G[u].PB(MP(v,w));
        G[v].PB(MP(u,w));
    }
    Dijkstra(1,n,p);
    Dijkstra(n,n,q);
    LL ans=-1;
    rep(i,1,n+1)rep(a,0,2)rep(b,0,2){
        LL dp=p[i<<1|a];
        LL dq=q[i<<1|b];
        if(dp!=1LL<<60&&dq!=1LL<<60){
            LL t=max(dp,dq);
            if(ans==-1||t<ans)ans=t;
        }
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