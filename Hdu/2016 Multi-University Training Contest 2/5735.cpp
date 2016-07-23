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
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
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

int n;
char opt[5];
int w[1<<16];
vector<int>G[1<<16];
LL f[1<<8][1<<8];
LL dp[1<<16];
LL play(LL a,LL b){
    if(opt[0]=='A')return a&b;
    if(opt[0]=='O')return a|b;
    if(opt[0]=='X')return a^b;
    return -1;
}
LL mem[1<<24];
void dfs(int u,int dph){
    int a=w[u]>>8,b=w[u]&((1<<8)-1);
    rep(i,0,1<<8)if(~f[i][b])
        cmax(dp[u],f[i][b]+(play(a,i)<<8));
    memcpy(mem+(dph<<8),f[a],sizeof(f[a]));
    rep(i,0,1<<8)
        cmax(f[a][i],dp[u]+play(b,i));
    rep(i,0,sz(G[u]))
        dfs(G[u][i],dph+1);
    memcpy(f[a],mem+(dph<<8),sizeof(f[a]));
}
void solve(){
    scanf("%d%s",&n,opt);
    rep(i,0,n)scanf("%d",&w[i]);
    rep(i,0,n)G[i].clear();
    rep(i,1,n){
        int fa;
        scanf("%d",&fa);
        fa--;
        G[fa].PB(i);
    }
    memset(f,-1,sizeof f);
    memset(dp,0,sizeof dp);
    dfs(0,0);
    LL ans=0;
    rep(i,0,n)
        ans=(ans+(1LL+i)*(dp[i]+w[i]))%MOD;
    printf("%d\n",(int)(ans));
}

int main(){
    int _T=1;
    scanf("%d",&_T);
    rep(CA,0,_T){
        solve();
    }
    return 0;
}