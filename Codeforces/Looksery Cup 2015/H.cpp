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

const long double eps= 1e-20;
int sign(long double x){return x<-eps?-1:x>eps;}
long double f(long double x){return x<0?-x:x;}
pair<long double,long double>f(long double a,long double b,long double c,long double d){
    vector<long double>L;
    L.PB(a*c);
    L.PB(a*d);
    L.PB(b*c);
    L.PB(b*d);
    sort(L.OP,L.ED);
    return MP(L[0],L[3]);
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    LL a,b,c,d;
    while(cin>>a>>b>>c>>d){
        long double mx=max(max(f(a),f(b)),max(f(c),f(d)));
        long double le=0,re=mx;
        while(re-le>1e-10&&(re-le)>(re+le)/4*1e-10){
            long double x=(le+re)/2;
            long double lp=a-x,rp=a+x;
            long double lq=b-x,rq=b+x;
            long double lr=c-x,rr=c+x;
            long double ls=d-x,rs=d+x;
            pair<long double,long double>fl=f(lp,rp,ls,rs);
            pair<long double,long double>fr=f(lr,rr,lq,rq);
            if(sign(fl.BB-fr.AA)>=0&&sign(fr.BB-fl.AA)>=0)re=x;
            else le=x;
        }
        double ans=(le+re)/2;
        printf("%.16f\n",ans);
    }
    return 0;
}

