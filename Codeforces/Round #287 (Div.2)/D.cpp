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
int n,p,mod;
LL f[1005][105][2];
LL t[1005];
int main(){
    int i,j,k,_T;
    while(~scanf("%d%d%d",&n,&p,&mod)){
        memset(f,0,sizeof f);
        t[1]=1;
        for(i=2;i<=n;i++)
            t[i]=t[i-1]*10%p;
        for(i=1;i<=9;i++)
            if(i%p)f[1][i%p][1]++;
        f[1][0][0]++;
        for(i=2;i<=n;i++){
            f[i][0][0]=1;
            f[i][0][1]=0;
            for(j=1;j<p;j++){
                f[i][j][0]=f[i-1][j][0]+f[i-1][j][1];
                for(k=1;k<=9;k++){
                    int rem=(j+p-k*t[i]%p)%p;
                    f[i][j][1]+=f[i-1][rem][0]+f[i-1][rem][1];
                }
                f[i][j][1]%=mod;
            }
        }
        LL ans=9;
        for(i=1;i<n;i++)ans=ans*10%mod;
        for(i=1;i<p;i++)
            ans-=f[n][i][1];
        ans%=mod;
        ans+=mod;
        cout<<ans%mod<<"\n";
    }
    return 0;
}

