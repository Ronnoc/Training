#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
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
LL extGcd(LL a,LL b,LL &x,LL &y){
    LL ret=a;
    if(b){
        ret = extGcd(b,a%b,y,x);
        y-=(a/b)*x;
    }else x=1,y=0;
    return ret;
}
LL modInv(LL a,LL m){
    LL x,y;
    extGcd(a,m,x,y);
    return (m+x%m)%m;
}
pair<LL,LL>linearMod(vector<LL>&A,vector<LL>&B,vector<LL>&M){
    LL x=0,m=1;
    for(int i=0;i<A.SZ;i++){
        LL a=A[i]*m,b=B[i]-A[i]*x,d=__gcd(M[i],a);
        if(b%d)return MP(0,-1);
        LL t=b/d*modInv(a/d,M[i]/d)%(M[i]/d);
        x+=m*t;
        m*=M[i]/d;
        x%=m;
    }
    return MP((x%m+m)%m,m);
}
LL fib[44];
LL modPow(LL a,LL b,LL mod){
    LL ret=1;
    while(b){
        if(b&1){
            ret=ret*a;
            if(ret>=mod)ret%=mod;
        }
        a=a*a;
        if(a>=mod)a%=mod;
        b>>=1;
    }
    return ret;
}
LL MOD=1;
struct mat{
    LL _[2][2];
    mat(){init();}
    void init(){memset(_,0,sizeof _);}
    LL *operator [](int id){return _[id];}
    mat friend operator *(mat A,mat B){
        mat ret;
        int i,j,k;
        for(i=0;i<2;i++)for(j=0;j<2;j++)for(k=0;k<2;k++)
            ret[i][j]+=A[i][k]*B[k][j];
        for(i=0;i<2;i++)for(j=0;j<2;j++)
            if(ret[i][j]>=MOD)ret[i][j]%=MOD;
        return ret;
    }
};
LL fff(LL n,LL mod){
    MOD=mod;
    mat E;
    E[0][0]=E[1][1]=1;
    mat A;
    A[0][0]=A[0][1]=A[1][0]=1;
    while(n){
        if(n&1)E=E*A;
        A=A*A;
        n>>=1;
    }
    return E[1][0];
}
LL play(LL a,LL n,LL p,LL q){
    int cnt=0;
    LL mod=1;
    for(int i=1;i<=q;i++)mod*=p;
    a%=mod;
    if(a==0)return 0;
    while(a%p==0)a/=p,cnt++;
    LL st=1;
    if(cnt){
        if(n>20)return 0;
        LL temp=fib[n]*cnt;
        if(temp>=q)return 0;
        st=modPow(p,temp,mod);
    }
    LL z=fff(n,mod/p*(p-1));
    return st*modPow(a,z,mod)%mod;
}
int main(){
    int i,j,k,_T;
    fib[1]=fib[2]=1;
    for(i=3;i<=20;i++)fib[i]=fib[i-1]+fib[i-2];
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        int n,p,a,b;
        scanf("%d%d%d%d",&a,&b,&p,&n);
        printf("Case #%d: ",CA);
        if(n==1)printf("%d\n",a%p);
        else if(n==2)printf("%d\n",b%p);
        else {
            n-=2;
            vector<PII>L;
            vector<LL>A,B,M;
            for(i=2;i*i<=p;i++)if(p%i==0){
                int cnt=0;
                while(p%i==0)cnt++,p/=i;
                L.PB(MP(i,cnt));
            }
            if(p>1)L.PB(MP(p,1));
            for(i=0;i<L.SZ;i++){
                int tmp=1;
                for(j=0;j<L[i].BB;j++)
                    tmp*=L[i].AA;
                A.PB(1);
                M.PB(tmp);
                B.PB(play(a,n,L[i].AA,L[i].BB)*play(b,n+1,L[i].AA,L[i].BB)%tmp);
            }
            pair<LL,LL> ret=linearMod(A,B,M);
            printf("%lld\n",ret.AA);
        }
    }
    return 0;
}

