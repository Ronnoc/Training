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
const int MXN = 200000+5;
int N,M,S;
VI G[MXN];
set<int>g[MXN];
int ia[MXN];
int ib[MXN];
int d[MXN];
int main(){
    DRI(T);while(T--){
        RI(N);RI(M);
        rep(i,1,N+1)G[i].clear(),g[i].clear(),ia[i]=ib[i]=0;
        rep(i,0,M){
            DRI(u);
            DRI(v);
            G[u].PB(v);
            G[v].PB(u);
            g[u].insert(v);
            g[v].insert(u);
        }
        RI(S);
        VI B(all(G[S]));
        rep(i,0,sz(B))ib[B[i]]=1;
        rep(i,0,sz(B)){
            int u=B[i];
            rep(j,0,sz(G[u])){
                int v=G[u][j];
                if(!ib[v])
                    ia[v]=1;
            }
        }
        int na=accumulate(ia+1,ia+N+1,0);
        int nb=accumulate(ib+1,ib+N+1,0);
        VI A;
        if(na+nb==N){
            rep(i,1,N+1)d[i]=-1;
            rep(i,1,N+1)if(ia[i])d[i]=1;
            d[S]=0;
            VI C;
            queue<int>Q;
            rep(i,0,sz(B)){
                int u=B[i];
                int del=sz(G[u]);
                rep(j,0,sz(G[u])){
                    int v=G[u][j];
                    if(ib[v])del--;
                }
                if(del==na){
                    C.PB(u);
                }else d[u]=2,Q.push(u);
            }
            while(!Q.empty()){
                int u=Q.front();
                Q.pop();
                rep(i,0,sz(C)){
                    int v=C[i];
                    if(d[v]==-1&&!g[u].count(v)){
                        d[v]=d[u]+1;
                        Q.push(v);
                    }
                }
            }
        }else {
            rep(i,1,N+1)d[i]=1;
            d[S]=0;
            rep(i,0,sz(B))d[B[i]]=2;
        }
        VI L;
        rep(i,1,N+1)if(i!=S)L.PB(d[i]);
        printf("%d",L[0]);
        rep(i,1,sz(L))printf(" %d",L[i]);
        printf("\n");
    }
    return 0;
}