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

int b[4005],n;
int dp[4005][4005];
map<int,vector<int> >F;
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    while(~scanf("%d",&n)){
        F.clear();
        memset(dp,0,sizeof dp);
        for(i=1;i<=n;i++)scanf("%d",&b[i]);
        map<int,int>Z;
        for(i=1;i<=n;i++)Z[b[i]]++;
        for(i=1;i<=n;i++){
            for(j=1;j<i;j++){
                int id=lower_bound(F[b[i]].OP,F[b[i]].ED,j)-F[b[i]].OP;
                if(id)dp[i][j]=1+dp[j][F[b[i]][id-1]];
                else dp[i][j]=2;
                //cerr<<i<<" "<<j<<" "<<id<<" "<<dp[i][j]<<"\n";
            }
            F[b[i]].PB(i);
        }
        int ans=0;
        for(i=1;i<=n;i++)cmax(ans,Z[b[i]]);
        for(i=1;i<=n;i++)
            for(j=1;j<i;j++)
                cmax(ans,dp[i][j]);
        cout<<ans<<"\n";
    }
    return 0;
}

