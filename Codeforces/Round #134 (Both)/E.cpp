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
const int MXN = 100000 + 10;
struct SEG {
    int l,r,k,b;
    SEG( int _l=0,int _r=0 ) {l=_l,r=_r;}
} SGT[MXN<<2|1];
void create( SEG &T,int t ) {
    T.k=0,T.b=0;
}
void build( int id,int l,int r ) {
    SGT[id]=SEG( l,r );
    int mid=( l+r )/2;
    if ( l!=r ) {
        build( id*2,l,mid );
        build( id*2+1,mid+1,r );
        create(SGT[id],mid);
    } else create( SGT[id],l );
}
void update( int id,int l,int r,int k,int b ) {
    if(l>r)return;
    //cerr<<id<<" "<<l<<"~"<<r<<" "<<k<<"x+"<<b<<"\n";
    SEG &T=SGT[id];
    int mid=( T.l+T.r )/2;
    if ( T.l==l&&T.r==r ) {
        if(T.k==0)T.k=k,T.b=b;
        else {
            if(T.k==k){
                cmin(T.b,b);
            }else {
                int p=T.k>0?T.b:b;
                int q=T.k<0?T.b:b;
                int l=T.l,r=T.r;
                int pl=l+p,ql=-l+q;
                int pr=r+p,qr=-r+q;
                if(pl>=ql)T.k=-1,T.b=q;
                else if(pr<=qr)T.k=1,T.b=p;
                else {
                    T.k=0;
                    int c=(q-p)/2;
                    update(id,l,c,1,p);
                    update(id,c+1,r,-1,q);
                }
            }
        }
        return;
    }
    if ( r<=mid )update( id<<1,l,r,k,b );
    else if ( l>mid )update( id<<1|1,l,r,k,b );
    else {
        update( id<<1,l,mid,k,b );
        update( id<<1|1,mid+1,r,k,b );
    }
}
int query(int id,int x){
    int ret=-1;
    SEG &T=SGT[id];
    if(T.k)ret=T.k*x+T.b;
    if(T.l!=T.r){
        int mid=(T.l+T.r)>>1;
        int tmp;
        if(x<=mid)tmp=query(id<<1,x);
        else tmp=query(id<<1|1,x);
        if(ret==-1)ret=tmp;
        else if(~tmp)cmin(ret,tmp);
    }
    //cerr<<id<<" "<<x<<" "<<ret<<" ? "<<T.k<<" "<<T.b<<" @ "<<T.l<<"~"<<T.r<<"\n";
    return ret;
}
int a[MXN],b[MXN];
int A[MXN],B[MXN];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n;
    while(~scanf("%d",&n)){
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)scanf("%d",&b[i]);
        for(i=1;i<=n;i++)A[a[i]]=i,B[b[i]]=i;
        build(1,1,n);
        for(i=1;i<=n;i++){
            int p=A[i],q=B[i];
            if(p<=q){
                update(1,1,1+q-p,-1,q-p+1);
                update(1,1+q-p+1,q,1,-1-q+p);
                update(1,q+1,n,-1,n-p+q+1);
            }else {
                update(1,1,q,1,p-q-1);
                update(1,q+1,q+1+n-p,-1,q+1+n-p);
                update(1,q+1+n-p+1,n,1,p-q-1-n);
            }
        }
        for(i=1;i<=n;i++)
            printf("%d\n",query(1,i));
    }
    return 0;
}

