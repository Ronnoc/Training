#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
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

LL dp[2][50001];
int main(){
    int i,j,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        int n,m;
        scanf("%d%d",&n,&m);
        int ans=0;
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        for(i=1;i*(i+1)<=n+n;i++){
            int x=i&1,y=(i&1)^1;
            for(j=0;j<i;j++)dp[x][j]=0;
            for(j=i;j<=n;j++){
                dp[x][j]=dp[x][j-i]+dp[y][j-i];
                if(dp[x][j]>=m)dp[x][j]%=m;
            }
            ans+=dp[x][n];
            if(ans>=m)ans%=m;
        }
        printf("Case #%d: %d\n",CA,ans);
    }
    return 0;
}
