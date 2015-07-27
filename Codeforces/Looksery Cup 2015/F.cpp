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

int N,K;
int p[1000005];
int q[1000005];
LL solve(vector<int>&L){
    LL ret=0;
    if(L.SZ<=1)return ret;
    int mid=L.SZ/2;
    vector<int>P,Q;
    int i;
    for(i=0;i<L.SZ;i++)if(i<mid)P.PB(L[i]);else Q.PB(L[i]);
    ret+=solve(P)+solve(Q);
    vector<pair<int,int> >Ve;
    for(i=0;i<L.SZ;i++)
        Ve.PB(MP(L[i],i));
    sort(Ve.OP,Ve.ED);
    reverse(Ve.OP,Ve.ED);
    int le=mid,re=mid-1;
    int sl=0,sr=0;
    while(le>0){
        le--;
        sl+=L[le];
        sl%=K;
        p[sl]++;
    }
    while(re+1<L.SZ){
        re++;
        sr+=L[re];
        sr%=K;
        q[sr]++;
    }
    for(i=0;i<Ve.SZ;i++){
        int id=Ve[i].BB;
        if(id<le||id>re)continue;
        if(id>=le&&id<mid){
            while(le<=id){
                int z=sl-L[id];
                z=-z;
                z%=K;z+=K;z%=K;
                ret+=q[z];
                p[sl]--;
                sl-=L[le];
                sl%=K;sl+=K;sl%=K;
                le++;
            }
        }else {
            while(re>=id){
                int z=sr-L[id];
                z=-z;
                z%=K;z+=K;z%=K;
                ret+=p[z];
                q[sr]--;
                sr-=L[re];
                sr%=K;sr+=K;sr%=K;
                re--;
            }
        }
    }
    return ret;
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    while(~scanf("%d%d",&N,&K)){
        memset(p,0,sizeof p);
        memset(q,0,sizeof q);
        vector<int>L;
        for(i=0;i<N;i++){
            int w;
            scanf("%d",&w);
            L.PB(w);
        }
        cout<<solve(L)<<"\n";
    }
    return 0;
}

