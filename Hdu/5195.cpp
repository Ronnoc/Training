#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define NAME ""
#define UsingFile 0

const int MXN = 100005;
set<int>G[MXN];
set<int>S[MXN];
set<int>F[MXN];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,_T;
    int n,m,k,u,v;
    while(~scanf("%d%d%d",&n,&m,&k)){
        for(i=0;i<=n;i++)G[i].clear(),S[i].clear(),F[i].clear();
        set<int>P;
        for(i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            G[u].insert(v);
            F[v].insert(u);
        }
        for(i=1;i<=n;i++)if(F[i].SZ<=k)P.insert(i);
        for(i=1;i<=n;i++)S[F[i].SZ].insert(i);
        vector<int>Ans;
        int R=k;
        while(!P.empty()){
            int u=*(--P.ED);
            P.erase(--P.ED);
            Ans.PB(u);
            int D=F[u].SZ;
            for(set<int>::iterator it=F[u].OP;it!=F[u].ED;++it){
                int v=*it;
                G[v].erase(G[v].find(u));
            }
            S[F[u].SZ].erase(S[F[u].SZ].find(u));
            F[u].clear();
            for(set<int>::iterator it=G[u].OP;it!=G[u].ED;++it){
                int v=*it;
                F[v].erase(F[v].find(u));
                int d=F[v].SZ;
                S[d+1].erase(S[d+1].find(v));
                S[d].insert(v);
                if(d<=R-D)P.insert(v);
            }
            for(i=R-D+1;i<=R;i++){
                for(set<int>::iterator it=S[i].OP;it!=S[i].ED;++it){
                    int v=*it;
                    if(P.find(v)==P.ED){
                    }else P.erase(P.find(v));
                }
            }
            R-=D;
        }
        if(!Ans.empty())printf("%d",Ans[0]);
        for(i=1;i<Ans.SZ;i++)printf(" %d",Ans[i]);
        printf("\n");
    }
    return 0;
}

