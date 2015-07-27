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
#define UsingFile 0

int f[1005];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(f,0,sizeof f);
        for(i=0;i<m;i++){
            scanf("%d%d",&j,&k);
            f[j]=1;
            f[k]=1;
        }
        for(i=1;i<=n;i++)if(!f[i])break;
        printf("%d\n",n-1);
        for(j=1;j<=n;j++)if(i!=j)printf("%d %d\n",i,j);
    }
    return 0;
}

