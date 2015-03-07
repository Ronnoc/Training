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

int n,m;
int a[1005];
double p[1005][1005];
int main(){
    //freopen("F.in","r",stdin);
    //freopen("Fwa.out","w",stdout);
    int i,j,k,_T;
    while(~scanf("%d%d",&n,&m)){
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++){
                if(a[i]>a[j])p[i][j]=1,p[j][i]=0;
                else p[i][j]=0,p[j][i]=1;
            }
        for(i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            for(j=1;j<=n;j++)if(j!=a&&j!=b){
                double paj=p[a][j];
                double pbj=p[b][j];
                p[a][j]=p[b][j]=(paj+pbj)*.5;
                double pja=p[j][a];
                double pjb=p[j][b];
                p[j][a]=p[j][b]=(pja+pjb)*.5;
            }
            p[a][b]=p[b][a]=0.5;
        }
        double ans=0;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                ans+=p[i][j];
        //cout<<ans<<"\n";
        printf("%.16f\n",(double)ans);
    }
    return 0;
}

