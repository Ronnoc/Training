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

const LL MOD = 1000000007;
int gg[4001][4001];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int W,H;
    for(i=0;i<=4000;i++)gg[i][0]=gg[0][i]=i;
    for(i=1;i<=4000;i++)
        for(j=1;j<=4000;j++){
            if(j<i)gg[i][j]=gg[j][i];
            else gg[i][j]=gg[i][j-i];
        }
    while(~scanf("%d%d",&W,&H)){
        LL ans=0;
        for(LL w=1;w<=W;w++)
            for(LL h=1;h<=H;h++){
                LL mul=(W+1-w)*(H+1-h);
                LL now=0;
                int ox=w/2,ex=(w-1)/2;
                int oy=h/2,ey=(h-1)/2;
                if(((w+0)*(h+0)+w*h)%2==0)now+=4*ex*ey;
                if(((w+1)*(h+0)+w*h)%2==0)now+=4*ox*ey;
                if(((w+0)*(h+1)+w*h)%2==0)now+=4*ex*oy;
                if(((w+1)*(h+1)+w*h)%2==0)now+=4*ox*oy;
                if((h*w)%2==0)
                    now+=2*(h-1+w-1);
                ox=(w+1)/2,ex=(w/2+1);
                oy=(h+1)/2,ey=(h/2+1);
                if((h*0+w*0+h*w)%2==0)now+=2*ex*ey;
                if((h*1+w*0+h*w)%2==0)now+=2*ox*ey;
                if((h*0+w*1+h*w)%2==0)now+=2*ex*oy;
                if((h*1+w*1+h*w)%2==0)now+=2*ox*oy;
                int g=gg[h][w];
                now-=2*(g+1);
                //cout<<w<<" "<<h<<" "<<now<<"\n";
                ans+=now%MOD*mul%MOD;
            }
        ans%=MOD;
        ans+=MOD;
        ans%=MOD;
        cout<<ans*6%MOD<<"\n";
    }
    return 0;
}
