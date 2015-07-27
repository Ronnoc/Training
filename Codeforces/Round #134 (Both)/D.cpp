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
#define UsingFile 0

map<int,vector<int> >Z;
const int MXN = 100005+15;
int a[MXN];
inline int LB(int x){return x&(-x);}
struct BIT{
    LL _[MXN];
    int n;
    void init(int m){
        n=m+5;
        for(int i=0;i<=n;i++)_[i]=0;
    }
    LL query(int w){
        LL ret=0;
        for(w+=3;w>0;w-=LB(w))ret+=_[w];
        return ret;
    }
    void update(int w,LL d){
        for(w+=3;w<n;w+=LB(w))_[w]+=d;
    }
}Y;
int ans[MXN];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        Z.clear();
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            Z[a[i]].PB(i);
        }
        vector<pair<PII,int> >TL;
        TL.clear();
        for(i=1;i<=m;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            TL.PB(MP(MP(r,l),i));
        }
        sort(TL.OP,TL.ED);
        int last=0;
        Y.init(n+5);
        for(i=0;i<TL.SZ;i++){
            int r=TL[i].AA.AA,l=TL[i].AA.BB;
            int id=TL[i].BB;
            while(last<r){
                last++;
                int v=a[last];
                k=lower_bound(Z[v].OP,Z[v].ED,last)-Z[v].OP;
                if(k>=v){
                    Y.update(k>v?Z[v][k-v-1]+1:0,-1);
                    Y.update(Z[v][k-v]+1,1);
                }
            }
            ans[id]=Y.query(l);
        }
        last=0;
        Y.init(n+5);
        for(i=0;i<TL.SZ;i++){
            int r=TL[i].AA.AA,l=TL[i].AA.BB;
            int id=TL[i].BB;
            while(last<r){
                last++;
                int v=a[last];
                k=lower_bound(Z[v].OP,Z[v].ED,last)-Z[v].OP;
                if(k>=v-1){ 
                    Y.update(k>=v?Z[v][k-v]+1:0,-1);
                    Y.update(Z[v][k-v+1]+1,1);
                }
            }
            ans[id]-=Y.query(l);
        }
        for(i=1;i<=m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}

