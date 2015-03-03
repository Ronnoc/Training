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
#define VER 1
int k,n,m;
vector<PII>L[100005];
int li[100005];
int sr[100005];
set<pair<double,int> >S;
int T[100005];
int I[100005];
int B[100005];
int pk[100005];
LL a[100005];
LL A[100005];
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j;
    while(~scanf("%d%d%d",&k,&n,&m)){
        for(i=1;i<=k;i++)L[i].clear();
        S.clear();
        for(i=1;i<=k;i++)scanf("%I64d",&a[i]),A[i]=-1;
        for(i=1;i<=n;i++)scanf("%d%d%d",&T[i],&I[i],&B[i]);
        for(i=1;i<=n;i++){
            pk[i]=0;
            if(T[i]==1){
                if(B[i]>a[I[i]]&&(A[I[i]]==-1||B[i]>B[A[I[i]]]))A[I[i]]=i;
            }else if(T[i]==2)L[I[i]].PB(MP(B[i],i));
            else S.insert(MP(B[i],i));
        }
        for(i=1;i<=k;i++)if(~A[i])
            L[i].PB(MP(B[A[i]]-a[i],A[i]));
        for(i=1;i<=k;i++){
            sr[i]=0;
            sort(L[i].OP,L[i].ED);
            li[i]=0;
            reverse(L[i].OP,L[i].ED);
            if(!L[i].empty()){
                double x=L[i][0].AA;
                S.insert(MP((a[i]+x)/a[i],L[i][0].BB));
                li[i]++;
            }
        }
        while(!S.empty()&&m){
            pair<double,int>tp=*(--S.ED);
            S.erase(--S.ED);
            int id=tp.BB;
            m--;
            pk[id]=1;
            if(T[id]!=3&&li[I[id]]<L[I[id]].SZ){
                int u=I[id];
                int v=L[u][li[u]].BB;
                a[u]+=L[u][li[u]-1].AA;
                double x=L[u][li[u]].AA;
                S.insert(MP((a[u]+x)/a[u],L[u][li[u]++].BB));
            }
        }
        int cnt=0;
        for(i=1;i<=n;i++)cnt+=pk[i];
        printf("%d\n",cnt);
        for(j=1;j<=3;j++)
            for(i=1;i<=n;i++)
                if(pk[i]&&T[i]==j)
                    printf("%d ",i);
        printf("\n");
    }
    return 0;
}

