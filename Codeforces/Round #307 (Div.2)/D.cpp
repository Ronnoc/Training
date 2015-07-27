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


LL n,k,l,m;
struct mat{
    LL _[5][5];
    mat(){memset(_,0,sizeof _);}
    LL *operator [](int id){return _[id];}
    mat friend operator*(mat A,mat B){
        mat C;
        int i,j,k;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                for(k=0;k<4;k++){
                    C[i][j]+=A[i][k]*B[k][j]%m;
                    C[i][j]%=m;
                }
        return C;
    }
    mat operator ^(LL t){
        mat E;
        int i;
        for(i=0;i<4;i++)
            E[i][i]=1;
        mat A=*this;
        while(t){
            if(t&1)E=A*E;
            A=A*A;
            t>>=1;
        }
        return E;
    }
};
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j;
    while(cin>>n>>k>>l>>m){
        LL ans=1%m;
        int p,q,r;
        mat A;
        for(p=0;p<2;p++)
            for(q=0;q<2;q++)
                for(r=0;r<2;r++){
                    int P=p|(q&r);
                    int Q=r;
                    int from=p<<1|q;
                    int to=P<<1|Q;
                    A[from][to]++;
                }
        mat B=A^(n-2);
        LL C[5];
        for(i=0;i<4;i++)C[i]=0;
        LL E[5];
        E[0]=2,E[1]=1,E[2]=0,E[3]=1;
        for(i=0;i<4;i++)for(j=0;j<4;j++){
            C[i]+=E[j]*B[j][i]%m;
            C[i]%=m;
        }
        LL S,T;
        S=(C[0]+C[1])%m;
        T=(C[2]+C[3])%m;
        for(i=0;i<l;i++){
            if(k&1)ans=ans*T%m;
            else ans=ans*S%m;
            k>>=1;
        }
        if(k)cout<<0<<"\n";
        else cout<<ans%m<<"\n";
    }
    return 0;
}

