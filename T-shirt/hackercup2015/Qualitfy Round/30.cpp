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
#define NAME "30"

int x[20],y[20],z[20];
int p[1<<20],c[1<<20],f[1<<20];
int main(){
    freopen(NAME".txt","r",stdin);
    freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        int gp,gc,gf;
        scanf("%d%d%d",&gp,&gc,&gf);
        int n;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d%d%d",&x[i],&y[i],&z[i]);
        p[0]=c[0]=f[0];
        bool flag=0;
        for(j=1;j<1<<n;j++){
            int id=__builtin_ctz(j);
            p[j]=p[j^(1<<id)]+x[id];
            c[j]=c[j^(1<<id)]+y[id];
            f[j]=f[j^(1<<id)]+z[id];
            if(p[j]==gp&&c[j]==gc&&f[j]==gf)
                flag=1;
        }
        printf("Case #%d: %s\n",CA,flag?"yes":"no");
    }
    return 0;
}

