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
#define NAME "AL"
#define UsingFile 1

char s[105][105];
PII w[105][105][4];
int R,C;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char ds[]="><v^";
bool inner(int x,int y){
    if(x<0||x>=R)return 0;
    if(y<0||y>=C)return 0;
    return 1;
}
bool inner(PII A){
    return inner(A.AA,A.BB);
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        scanf("%d%d",&R,&C);
        for(i=0;i<R;i++)
            scanf("%s",s[i]);
        int fail=0;
        int ans=0;
        for(i=0;i<R;i++)for(j=0;j<C;j++){
            int ok=0;
            if(s[i][j]!='.')for(k=0;k<4;k++){
                int x=i,y=j;
                while(1){
                    x+=dx[k];
                    y+=dy[k];
                    if(!inner(x,y)||s[x][y]!='.'){
                        break;
                    }
                }
                w[i][j][k]=MP(x,y);
                if(inner(w[i][j][k]))ok=1;
            }
            for(k=0;k<4;k++)if(s[i][j]==ds[k])break;
            if(k<4&&!inner(w[i][j][k])){
                if(ok)ans++;
                else fail=1;
            }
        }
        printf("Case #%d: ",CA);
        if(!fail)printf("%d\n",ans);
        else puts("IMPOSSIBLE");
    }
    return 0;
}

