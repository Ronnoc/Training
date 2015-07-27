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

char s[257][257];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int n,m,k;
bool inner(int x,int y){
    if(x<0||x>=n)return 0;
    if(y<0||y>=m)return 0;
    return 1;
}
bool isb[257][257];
int w[257][257];
bitset<257>c[257][257],e[257][257];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        printf("Case #%d:\n",CA);
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<n;i++)scanf("%s",s[i]);
        for(i=0;i<n;i++)for(j=0;j<m;j++)w[i][j]=s[i][j]=='B';
        memset(isb,0,sizeof isb);
        for(i=0;i<k;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            x--,y--;
            isb[x][y]=1;
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                c[i][j].reset(),e[i][j].reset();
        for(i=0;i<n;i++)for(j=0;j<m;j++)if(w[i][j])c[i][j].flip(m);
        for(j=0;j<m;j++){
            int x=0,y=j;
            c[x][y].flip(j);
            e[x][y].flip(j);
            for(k=0;k<4;k++){
                int xx=x+dx[k],yy=y+dy[k];
                if(inner(xx,yy))
                    c[xx][yy].flip(j);
            }
        }
        vector<bitset<257> >L;
        for(i=1;i<n;i++){
            for(j=0;j<m;j++){
                e[i][j]=c[i-1][j];
                c[i][j]^=e[i][j];
                for(k=0;k<4;k++){
                    int xx=i+dx[k],yy=j+dy[k];
                    if(inner(xx,yy))
                        c[xx][yy]^=e[i][j];
                }
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(isb[i][j])
                    L.PB(e[i][j]);
        for(j=0;j<m;j++)L.PB(c[n-1][j]);
        int fail=0;
        for(i=0;i<L.SZ;i++)if(L[i].any()){
            for(j=0;j<m;j++)if(L[i][j])break;
            if(j==m){
                fail=1;break;
            }
            for(k=i+1;k<L.SZ;k++)if(L[k][j])
                L[k]^=L[i];
        }
        if(fail)puts("NO");
        else puts("YES");
    }
    return 0;
}

