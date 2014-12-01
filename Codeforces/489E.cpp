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

int x[1005],b[1005];
double dp[1005];
int pre[1005];
int main(){
    int i,j,k,_T;
    int n,l;
    while(~scanf("%d%d",&n,&l)){
        for(i=1;i<=n;i++)scanf("%d%d",&x[i],&b[i]);
        x[0]=0;
        double R=n*sqrt(l+x[n]);
        double le=0,re=R;
        for(int rt=1;rt<=200&&re-le>1e-20;rt++){
            double mi=(le+re)/2;
            for(i=0;i<=n;i++)
                dp[i]=-1e100;
            dp[0]=0;
            for(i=0;i<=n;i++)for(j=i+1;j<=n;j++){
                    double foo=mi*b[j]-sqrt(fabs(x[j]-x[i]-l));
                    if(dp[j]<dp[i]+foo)
                        dp[j]=dp[i]+foo,pre[j]=i;
                }
//            printf("%d %lf %lf\n",rt,mi,dp[n]);
            if(dp[n]>-1e-8)re=mi;
            else le=mi;
        }
        vector<int>ans;
        int last=n;
        while(last){
            ans.PB(last);
            last=pre[last];
        }
        reverse(ans.OP,ans.ED);
        for(i=0;i<ans.SZ;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}

