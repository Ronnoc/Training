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
vector<PII>L;
const int mod = 1234567;
int dp[2][115][115];
bool cmp(const PII A,const PII B){
    return 1LL*A.BB*B.AA<1LL*B.BB*A.AA;
}
int main(){
    int i,j,k,p,q,_T;
    scanf("%d",&_T);
    while(_T--){
        int n;
        scanf("%d",&n);
        L.clear();
        for(i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            L.PB(MP(x,y));
        }
        sort(L.OP,L.ED);
        LL ans=0;
        for(i=0;i<L.SZ;i++){
            vector<PII>G;
            for(j=i+1;j<L.SZ;j++){
                int tx=L[j].AA-L[i].AA;
                int ty=L[j].BB-L[i].BB;
                G.PB(MP(tx,ty));
            }
            sort(G.OP,G.ED,cmp);
            int x=0,y=1,m=G.SZ;
            memset(dp,0,sizeof dp);
            dp[x][0][0]=1;
            for(j=0;j<m;j++){
                for(p=0;p<=j+1;p++)
                    for(q=p;q<=j+1;q++)
                        dp[y][p][q]=dp[x][p][q];
                for(p=0;p<=j;p++)
                    dp[y][p][j+1]+=dp[x][0][p];
                for(p=1;p<=j;p++)
                    for(q=p+1;q<=j;q++)if(dp[x][p][q]){
                        int ax=G[q-1].AA-G[p-1].AA;
                        int ay=G[q-1].BB-G[p-1].BB;
                        int bx=G[j].AA-G[q-1].AA;
                        int by=G[j].BB-G[q-1].BB;
                        if(cmp(MP(ax,ay),MP(bx,by)))
                            dp[y][q][j+1]+=dp[x][p][q];
                    }
                swap(x,y);
            }
            for(p=1;p<=m;p++)
                for(q=p+1;q<=m;q++)
                    ans+=dp[x][p][q];
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}
