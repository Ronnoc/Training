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
#define NAME "bl"
#define UsingFile 1
const double eps = 1e-8;
int sign(double x){return x<-eps?-1:x>eps;}
int n;
double v,x;
double r[105];
double c[105];
double t[105];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        scanf("%d%lf%lf",&n,&v,&x);
        for(i=1;i<=n;i++){
            scanf("%lf%lf",&r[i],&c[i]);
        }
        printf("Case #%d: ",CA);
        if(n==1){
            double p=v/r[1];
            if(sign(x-c[1])==0)printf("%.9f\n",p);
            else puts("IMPOSSIBLE");
            continue;
        }
        if(n==2){
            if(sign(x-c[1])==0&&sign(x-c[2])==0){
                double ans=v/(r[1]+r[2]);
                printf("%.9f\n",ans);
            }else if(sign(x-c[1])==0){
                double ans=v/r[1];
                printf("%.9f\n",ans);
            }else if(sign(x-c[2])==0){
                double ans=v/r[2];
                printf("%.9f\n",ans);
            }else {
                if(sign(c[1]-c[2])==0){
                    puts("IMPOSSIBLE");
                }else {
                    t[1]=v*(x-c[2])/(r[1]*(c[1]-c[2]));
                    t[2]=(v-r[1]*t[1])/r[2];
                    if(sign(t[1])<0||sign(t[2])<0)puts("IMPOSSIBLE");
                    else printf("%.9f\n",max(t[1],t[2]));
                }
            }
        }
    }
    return 0;
}

