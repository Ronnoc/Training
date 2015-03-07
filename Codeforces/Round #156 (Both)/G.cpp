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
const int MXN = 177777 + 10;
const LL MOD = 777777777;
int g[3][3];
struct SEG {
    int l,r;
    LL V[3][3];
    SEG( int _l=0,int _r=0 ) {l=_l,r=_r;memset(V,0,sizeof V);}
    void fresh(){for(int i=0;i<3;i++)for(int j=0;j<3;j++)V[i][j]%=MOD;}
} SGT[MXN<<2|1];
void create( SEG &T,int t ) {
    memset(T.V,0,sizeof T.V);
    for(int i=0;i<3;i++)T.V[i][i]=1;
}
void fresh( SEG &T,SEG &L,SEG &R ) {
    int i,j,x,y;
    memset(T.V,0,sizeof T.V);
    for(j=0;j<3;j++)
        for(x=0;x<3;x++)if(g[j][x])
            for(i=0;i<3;i++)
                for(y=0;y<3;y++)
                    T.V[i][y]+=L.V[i][j]*R.V[x][y]%MOD;
    T.fresh();
}
void build( int id,int l,int r ) {
    SGT[id]=SEG( l,r );
    int mid=( l+r )/2;
    if ( l!=r ) {
        build( id<<1,l,mid );
        build( id<<1|1,mid+1,r );
        fresh( SGT[id],SGT[id<<1],SGT[id<<1|1] );
    } else create( SGT[id],r );
}
void update( int id,int x,int w ) {
    SEG &T=SGT[id];
    int mid=( T.l+T.r )/2;
    if(T.l==T.r){
        memset(T.V,0,sizeof T.V);
        if(w)T.V[w-1][w-1]=1;
        else for(int i=0;i<3;i++)T.V[i][i]=1;
        return;
    }
    if(x<=mid)update(id<<1,x,w);
    else update(id<<1|1,x,w);
    fresh( T,SGT[id<<1],SGT[id<<1|1] );
}
int main(){
    int i,j,k,_T;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)scanf("%d",&g[i][j]);
        build(1,1,n);
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            update(1,a,b);
            LL ans=0;
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    ans+=SGT[1].V[i][j];
            ans%=MOD;
            ans+=MOD;
            cout<<ans%MOD<<"\n";
        }
    }
    return 0;
}

