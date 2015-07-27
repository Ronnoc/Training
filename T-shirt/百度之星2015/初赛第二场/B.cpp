#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
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

int fa[1000005];
int getfa(int u){return fa[u]==u?u:fa[u]=getfa(fa[u]);}
int id[1005][1005];
int h[1005][1005];
vector<PII>E[105];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        int n,m;
        for(i=0;i<=100;i++)E[i].clear();
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",&h[i][j]);
        int next=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                id[i][j]=++next;
        for(i=1;i<=next;i++)fa[i]=i;
        for(i=1;i<=n;i++)for(j=1;j<m;j++){
            int u=id[i][j];
            int v=id[i][j+1];
            int d=h[i][j]-h[i][j+1];
            if(d<0)d=-d;
            E[d].PB(MP(u,v));
        }
        for(i=1;i<n;i++)for(j=1;j<=m;j++){
            int u=id[i][j];
            int v=id[i+1][j];
            int d=h[i+1][j]-h[i][j];
            if(d<0)d=-d;
            E[d].PB(MP(u,v));
        }
        int ans=0;
        for(i=0;i<=100;i++){
            for(j=0;j<E[i].SZ;j++){
                int u=E[i][j].AA,v=E[i][j].BB;
                int fu=getfa(u),fv=getfa(v);
                if(fu!=fv)fa[fu]=fv,ans+=i;
            }
        }
        printf("Case #%d:\n",CA);
        printf("%d\n",ans);
    }
    return 0;
}

