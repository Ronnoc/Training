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

const int MXN = 500005;
int x[MXN],y[MXN];
int Y[MXN];
struct SEG {
    int l, r, sum;
    SEG( int _l = 0, int _r = 0 ) {l = _l, r = _r;}
} SGT[MXN<<4];
int nextid;
int root[MXN];
inline void update(SEG &de,SEG &l,SEG &r){
    de.sum=l.sum+r.sum;
}
void build(int id,int le,int re){
    SEG &de=SGT[id];
    if(re-le==1){
        de.sum=0;
        return;
    }
    int me=(le+re)>>1;
    build(de.l=nextid++,le,me);
    build(de.r=nextid++,me,re);
    update(de,SGT[de.l],SGT[de.r]);
}
void dfs(int id,int c,int w,int le,int re){
    SEG &de=SGT[id];
    int me=(le+re)/2;
    if(re-le==1){
        de.sum+=w;
        return;
    }
    if(c<me){
        SGT[nextid]=SGT[de.l];
        dfs(de.l=nextid++,c,w,le,me);
    }else {
        SGT[nextid]=SGT[de.r];
        dfs(de.r=nextid++,c,w,me,re);
    }
    update(de,SGT[de.l],SGT[de.r]);
}
int query(int id,int jd,int pe,int qe,int le,int re){
    if(pe==qe)return 0;
    SEG &di=SGT[id],&dj=SGT[jd];
    int me=(le+re)/2;
    if(pe==le&&qe==re)return dj.sum-di.sum;
    if(qe<me)return query(di.l,dj.l,pe,qe,le,me);
    if(pe>=me)return query(di.r,dj.r,pe,qe,me,re);
    return query(di.l,dj.l,pe,me,le,me)+query(di.r,dj.r,me,qe,me,re);
}
VI G[MXN];
void solve(){
    int n;
    while(~scanf("%d",&n)&&n){
        rep(i,0,n)scanf("%d%d",&x[i],&y[i]);
        rep(i,1,50001)G[i].clear();
        rep(i,0,n)G[x[i]].PB(y[i]);
        rep(i,1,50001){
            if(G[i].empty())continue;
            sort(all(G[i]));
        }
        int flag=1;
        rep(i,1,50001)Y[i]=0;
        int mn=50001;
        nextid=0;
        build(root[0]=nextid++,1,50001);
        rep(i,1,50001){
            SGT[root[i]=nextid++]=SGT[root[i-1]];
            int la=0;
            rep(j,0,sz(G[i])){
                int w=G[i][j];
                if(w-1>la+1&&query(root[i-1],root[Y[w]],la+1,w-1,1,50001))
                    flag=0;
                la=w;
                Y[w]=i;
                dfs(root[i],w,1,1,50001);
            }
        }
        int mx=0;
        rep(i,1,50001)Y[i]=0;
        nextid=0;
        build(root[0]=nextid++,1,50001);
        rep(i,1,50001){
            SGT[root[i]=nextid++]=SGT[root[i-1]];
            int la=50001;
            repd(j,sz(G[i])-1,0){
                int w=G[i][j];
                if(la-1>w+1&&query(root[i-1],root[Y[w]],w+1,la-1,1,50001))
                    flag=0;
                la=w;
                Y[w]=i;
                dfs(root[i],w,1,1,50001);
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
}

int main(){
    int _T=1;
    //scanf("%d",&_T);
    rep(CA,0,_T){
        solve();
    }
    return 0;
}