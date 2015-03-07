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

struct val{
    int t,i;
    val(int a=1<<25,int b=1<<25){t=a,i=b;}
    void init(){t=i=1<<25;}
    bool operator <(const val &v){
        if(t!=v.t)return t<v.t;
        return i<v.i;
    }
};
const int MAXB = 100005;
val dp[2][MAXB];//dp[i][j] explain end with j len is i
int b[100005];
int Z[100005];
vector<int>ID[100005];
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T,n,maxb,t;
    while(~scanf("%d%d%d%d",&_T,&n,&maxb,&t))while(_T--){
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
            Z[i-1]=b[i];
        }
        sort(Z,Z+n);
        int nz=unique(Z,Z+n)-Z;
        for(i=1;i<=n;i++)
            b[i]=lower_bound(Z,Z+nz,b[i])-Z;
        for(i=0;i<nz;i++)ID[i].clear();
        for(i=1;i<=n;i++)ID[b[i]].PB(i);
        for(i=1;i<=n;i++)if(val(1,i)<dp[1][b[i]])
            dp[1][b[i]]=val(1,i);
        int ans=1;
        for(j=2;j<=nz;j++){
            int x=(j-1)&1,y=j&1;
            for(i=0;i<nz;i++)dp[y][i].init();
            val b;
            for(i=0;i<nz;i++){
                for(k=0;k<ID[i].SZ;k++){
                    int id=ID[i][k];
                    val next=b;
                    if(next.i<id)next.i=id;
                    else next=val(next.t+1,id);
                    if(next<dp[y][i])dp[y][i]=next;
                }
                if(dp[x][i]<b)b=dp[x][i];
            }
            for(i=0;i<nz;i++)if(dp[y][i].t<=t)cmax(ans,j);
            if(ans<j)break;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

