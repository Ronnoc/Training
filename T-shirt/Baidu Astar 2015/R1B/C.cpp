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

int c[505][505];
int dx[]={-1,0,1,0,-1};
int dy[]={0,1,0,-1,0};
int n,m;
bool inner(int x,int y){
    if(x<1||x>n)return 0;
    if(y<1||y>m)return 0;
    return 1;
}
bool check(int x,int y){
    if(!inner(x,y))return 0;
    if(c[x][y])return 0;
    int i;
    for(i=0;i<4;i++){
        int ax=x+dx[i],ay=y+dy[i];
        int bx=x+dx[i+1],by=y+dy[i+1];
        if(inner(ax,ay)&&c[ax][ay])
            if(inner(bx,by)&&c[bx][by])
                return 1;
    }
    return 0;
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                c[i][j]=0;
        int g;
        scanf("%d",&g);
        queue<PII>Q;
        while(g--){
            int x,y;
            scanf("%d%d",&x,&y);
            Q.push(MP(x,y));
            c[x][y]=1;
        }
        while(!Q.empty()){
            PII tp=Q.front();
            Q.pop();
            int x=tp.AA,y=tp.BB;
            for(i=0;i<4;i++){
                int ax=x+dx[i],ay=y+dy[i];
                if(check(ax,ay)){
                    c[ax][ay]=1;
                    Q.push(MP(ax,ay));
                }
            }
        }
        int ans=0;
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)ans+=c[i][j];
        printf("Case #%d:\n",CA);
        printf("%d\n",ans);
    }
    return 0;
}

