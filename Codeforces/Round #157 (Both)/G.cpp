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
int n,m;//n nodes m operations
vector<int>G[100005];//edge i
vector<int>has[100005];//what color does node i has
vector<int>in[100005];//who has color i
int ID[100005],nextDFS;//DFS order
int le[100005],re[100005];//left right of its subtree in DFS ordered
int tot[100005];//how many times does color i used in SGT
int ans[100005];//answer of node i
void dfsID(int u,int fa){
    //cout<<"dfsID"<<u<<" "<<fa<<"\n";
    ID[u]=++nextDFS;
    le[u]=nextDFS;
    for(int i=0;i<G[u].SZ;i++){
        int v=G[u][i];
        if(v==fa)continue;
        dfsID(v,u);
    }
    re[u]=nextDFS;
    //cerr<<u<<" "<<le[u]<<"~"<<re[u]<<"\n";
}
const int MXN = 100005+10;
struct SEG{
    int l,r,m,lazy,tot;
    SEG(int _l=0,int _r=0){l=_l,r=_r,m=0,lazy=0,tot=0;}
    void show(){
        printf("%d~%d m=%d lazy=%d tot=%d\n",l,r,m,lazy,tot);
    }
}SGT[MXN<<2|1];
void create(SEG &T,int t){
    T.m=0,T.lazy=0,T.tot=0;
}
void fresh(SEG &T,SEG &L,SEG &R){
    T.m=min(L.m,R.m);
    T.tot=L.tot+R.tot;
}
void build(int id,int l,int r){
    SGT[id]=SEG(l,r);
    int mid=(l+r)>>1;
    if(l!=r){
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        fresh(SGT[id],SGT[id<<1],SGT[id<<1|1]);
    }else create(SGT[id],r);
}
void update(int id,int l,int r,int w){
    //cout<<"update @"<<SGT[id].l<<"~"<<SGT[id].r<<" "<<l<<"~"<<r<<" "<<w<<"\n";
    SEG &T=SGT[id];
    int mid=(T.l+T.r)>>1;
    if(T.l==l&&T.r==r){
        if(l==r){
            T.m+=w;
            T.tot=T.m!=0;
        }else {
            bool flag=(T.m==0&&w>0)||(T.m>0&&T.m+w==0);
            T.lazy+=w;
            T.m+=w;
            if(flag){
                update(id<<1,T.l,mid,T.lazy);
                update(id<<1|1,mid+1,T.r,T.lazy);
                T.lazy=0;
                fresh(T,SGT[id<<1],SGT[id<<1|1]);
            }
        }
        //cout<<"~";
        //T.show();
        return;
    }
    if(T.lazy){
        update(id<<1,T.l,mid,T.lazy);
        update(id<<1|1,mid+1,T.r,T.lazy);
        T.lazy=0;
    }
    //cout<<l<<"!"<<r<<"!"<<mid<<"!\n";
    if(r<=mid)update(id<<1,l,r,w);
    else if(l>mid)update(id<<1|1,l,r,w);
    else {
        update(id<<1,l,mid,w);
        update(id<<1|1,mid+1,r,w);
    }
    fresh(T,SGT[id<<1],SGT[id<<1|1]);
    //T.show();
}
void dfs(int u,int fa){
    int i,j;
    for(i=0;i<has[u].SZ;i++){
        int c=has[u][i];
        tot[c]++;
        if(tot[c]==1)for(j=0;j<in[c].SZ;j++){
                int v=in[c][j];
                //cout<<"in "<<u<<"\t"<<le[v]<<"~"<<re[v]<<"\n";
                update(1,le[v],re[v],1);
            }
    }
    ans[u]=SGT[1].tot;
    if(ans[u]>0)ans[u]--;
    //cout<<"ans["<<u<<"]="<<ans[u]<<"\n";
    for(i=0;i<G[u].SZ;i++){
        int v=G[u][i];
        if(v==fa)continue;
        dfs(v,u);
    }
    for(i=0;i<has[u].SZ;i++){
        int c=has[u][i];
        tot[c]--;
        if(tot[c]==0)for(j=0;j<in[c].SZ;j++){
            int v=in[c][j];
            //cout<<"out "<<u<<"\t"<<le[v]<<"~"<<re[v]<<"\n";
            update(1,le[v],re[v],-1);
        }
    }
}
int main(){
    int i,j,k,_T,u,v;
    while(~scanf("%d%d",&n,&m)){
        for(i=1;i<=n;i++)G[i].clear(),has[i].clear(),ans[i]=0;
        for(i=1;i<=m;i++)in[i].clear(),tot[i]=0;
        for(i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            G[u].PB(v);
            G[v].PB(u);
        }
        for(i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            has[u].PB(i),has[v].PB(i);
            in[i].PB(u),in[i].PB(v);
        }
        nextDFS=0;
        dfsID(1,-1);
        //for(i=1;i<=n;i++)cout<<ID[i]<<" ";cout<<"\n";
        build(1,1,n);
        dfs(1,-1);
        for(i=1;i<=n;i++)printf("%d ",ans[i]);
    }
    return 0;
}

