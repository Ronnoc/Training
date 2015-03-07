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

LL f(LL x){return x<0?-x:x;}
LL f(LL x,LL y,LL p,LL q){
    return f(x-p)+f(y-q);
}
LL cal(LL p,LL x,LL y){
    if(x>y)return cal(p,y,x);//x<y;
    if(p>=x+y)return x*y;
    if(p<=x)return (1+p)*p/2;
    LL q=p-x;
    if(p<=y)return (1+p)*p/2-(1+q)*q/2;
    LL r=p-y;
    return (1+p)*p/2-(1+q)*q/2-(1+r)*r/2;
}
LL g(LL x,LL y,LL n,LL t){
    LL ret=1,tmp;
    tmp=max(x-t,1LL);ret+=x-tmp;
    tmp=min(x+t,n);ret+=tmp-x;
    tmp=max(y-t,1LL);ret+=y-tmp;
    tmp=min(y+t,n);ret+=tmp-y;
    ret+=cal(t-1,x-1,y-1);
    ret+=cal(t-1,x-1,n-y);
    ret+=cal(t-1,n-x,y-1);
    ret+=cal(t-1,n-x,n-y);
    return ret;
}
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    LL n=10,x=1,y=1,c;
    while(cin>>n>>x>>y>>c){
        LL le=0,re=0,ge=-1;
        cmax(re,f(x,y,1,1));
        cmax(re,f(x,y,1,n));
        cmax(re,f(x,y,n,1));
        cmax(re,f(x,y,n,n));
        while(re>=le){
            if(re-le<=1){
                if(g(x,y,n,le)>=c)ge=le;
                else ge=re;
                break;
            }
            LL mid=(le+re)>>1;
            LL fm=g(x,y,n,mid);
            if(fm>=c)re=mid;
            else le=mid;
        }
        cout<<ge<<"\n";
    }
    return 0;
}

