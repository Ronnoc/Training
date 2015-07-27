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

char s[1005][1005];
int d[1005][1005];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int r,c;
int valid(int x,int y){
    if(x<0||x>=r)return 0;
    if(y<0||y>=c)return 0;
    if(s[x][y]=='T')return 0;
    return 1;
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    while(~scanf("%d%d",&r,&c)){
        memset(d,-1,sizeof d);
        queue<pair<PII,int> >Q;
        for(i=0;i<r;i++)
            scanf("%s",s[i]);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                if(s[i][j]=='E')
                    Q.push(MP(MP(i,j),0));
        while(!Q.empty()){
            PII _=Q.front().AA;
            int z=Q.front().BB;
            Q.pop();
            int x=_.AA,y=_.BB;
            if(~d[x][y]&&d[x][y]<=z)continue;
            d[x][y]=z;
            for(i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(valid(xx,yy))
                    Q.push(MP(MP(xx,yy),z+1));
            }
        }
        int L=-1;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                if(s[i][j]=='S')
                    L=d[i][j];
        int ans=0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)if(isdigit(s[i][j])){
                int t=s[i][j]-'0';
                if(~d[i][j]&&d[i][j]<=L)ans+=t;
            }
        printf("%d\n",ans);
    }
    return 0;
}

