#include<bits/stdc++.h>
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
int d[100005];
vector<PII>G[100005];
int f[100005];
int pre[100005];
vector<int>C[100005];
int U[100005];
int V[100005];
int W[100005];
int S[100005];
int main(){
    int i,j,k,_T;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(i=1;i<=n;i++)G[i].clear();
        memset(S,0,sizeof S);
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&U[i],&V[i],&W[i]);
            G[U[i]].PB(MP(V[i],i));
            G[V[i]].PB(MP(U[i],i));
        }
        memset(pre,-1,sizeof pre);
        for(i=1;i<=n;i++)d[i]=n<<1;
        for(i=0;i<=n;i++)C[i].clear();
        memset(f,-1,sizeof f);
        queue<PII>Q;
        Q.push(MP(1,0));
        while(!Q.empty()){
            int f=Q.front().AA;
            int l=Q.front().BB;
            Q.pop();
            if(l>=d[f])continue;
            d[f]=l;
            for(i=0;i<G[f].SZ;i++){
                int v=G[f][i].AA;
                if(d[v]>d[f]+1)
                    Q.push(MP(v,d[f]+1));
            }
        }
        for(i=1;i<=n;i++)C[d[i]].PB(i);
        f[1]=0;
        for(i=0;i<=n;i++)for(j=0;j<C[i].SZ;j++){
            int u=C[i][j];
            for(k=0;k<G[u].SZ;k++){
                int v=G[u][k].AA;
                if(d[v]==d[u]+1){
                    if(f[u]+W[G[u][k].BB]>f[v])
                        pre[v]=G[u][k].BB,f[v]=f[u]+W[G[u][k].BB];
                }
            }
        }
        int at=n;
        while(at!=1){
            S[pre[at]]=1;
            at=U[pre[at]]+V[pre[at]]-at;
        }
        int cnt=0;
        for(i=1;i<=m;i++)
            if(S[i]!=W[i])cnt++;
        printf("%d\n",cnt);
        for(i=1;i<=m;i++)if(S[i]!=W[i])
            printf("%d %d %d\n",U[i],V[i],S[i]);
        
    }
    return 0;
}

