#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
    LL ret=1;for(;b;b>>=1){
        if(b&1)ret=ret*a%MOD;a=a*a%MOD;
    }return ret;
}

const int MXN = 100005;
inline int LB(int x) {return x & (-x);}
struct BIT {
    LL _[MXN+5];
    int n;
    void init(int m) {
        n = m + 5;
        for (int i = 0; i <= n; i++)_[i] = 0;
    }
    LL query(int w) {
        LL ret = 0;
        for (w += 3; w > 0; w -= LB(w))ret += _[w];
        return ret;
    }
    void update(int w, LL d) {
        for (w += 3; w < n; w += LB(w))_[w] += d;
    }
    int find_Kth(int k) {        //UESTC_Dagon
        int ans=0,cnt=0;
        for(int i=22;i>=0;i--){
            ans+=1<<i;
            if(ans>=n||cnt+_[ans]>=k)ans-=1<<i;
            else cnt+=_[ans];
        }
        return ans - 2;
    }
}Y;
LL w[MXN];
VI G[MXN];
int fa[MXN];
VL Z;
int tz[MXN];
void rll(LL &w){
    scanf("%I64d",&w);
}
LL N,K;
LL ans;
void dfs(int u){
    if(w[u]==0){
        ans+=Y.query(sz(Z));
    }else {
        LL t=K/w[u];
        int it=upper_bound(Z.OP,Z.ED,t)-Z.OP-1;
        ans+=Y.query(it);
    }
    Y.update(tz[u],1);
    rep(i,0,sz(G[u]))
        dfs(G[u][i]);
    Y.update(tz[u],-1);
}
int main(){
    DRI(T);
    while(T--){
        rll(N);
        rll(K);
        rep(i,1,N+1)rll(w[i]),G[i].clear(),fa[i]=-1;
        rep(i,1,N){
            DRI(u);DRI(v);
            fa[v]=u;
            G[u].PB(v);
        }
        Z.clear();
        rep(i,1,N+1)Z.PB(w[i]);
        sort(all(Z));
        Z.erase(unique(all(Z)),Z.ED);
        rep(i,1,N+1)
            tz[i]=lower_bound(Z.OP,Z.ED,w[i])-Z.OP;
        int root=-1;
        rep(i,1,N+1)if(fa[i]==-1)root=i;
        Y.init(sz(Z));
        ans=0;
        dfs(root);
        cout<<ans<<"\n";
    }
    return 0;
}