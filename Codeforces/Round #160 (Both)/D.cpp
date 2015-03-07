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

double dp[53][53][53];
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,a,b,_T;
    int n,p;
    int A[55];
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++)scanf("%d",&A[i]);
        scanf("%d",&p);
        double ans=0;
        for(i=0;i<n;i++){
            vector<int>L;
            for(j=0;j<n;j++)if(j!=i)L.PB(A[j]);
            for(j=0;j<=n-1;j++){
                for(k=0;k<=L.SZ;k++)for(a=0;a<=j;a++)for(b=0;b<=p-A[i];b++)
                    dp[k][a][b]=0;
                dp[0][0][0]=1;
                for(k=0;k<L.SZ;k++){
                    double mul=1./(n-1-k);
                    for(a=0;a<=j;a++)
                        for(b=0;b<=p-A[i];b++)if(dp[k][a][b]>1e-100){
                            if(a<j&&b+L[k]<=p-A[i])
                                dp[k+1][a+1][b+L[k]]+=dp[k][a][b]*(j-a)*mul;
                            if(j-a<n-1-k)
                                dp[k+1][a][b]+=dp[k][a][b]*(n-1-k-j+a)*mul;
                        }
                }
                double sum=0;
                for(b=0;b<=p-A[i];b++)
                    sum+=dp[L.SZ][j][b];
                ans+=sum;
            }
        }
        ans/=n;
        cout<<ans<<"\n";
    }
    return 0;
}

