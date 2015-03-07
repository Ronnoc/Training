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
LL mod;
struct mat{
    LL _[2][2];
    mat(){memset(_,0,sizeof _);}
    LL* operator [](int id){return _[id];}
    mat friend operator *(mat A,mat B){
        mat C;
        int i,j,k;
        for(i=0;i<2;i++)for(j=0;j<2;j++)for(k=0;k<2;k++)
            C[i][j]+=A[i][k]*B[k][j];
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                C[i][j]%=mod;
        return C;
    }
    mat friend operator ^(mat A,LL t){
        mat E;
        E[0][0]=E[1][1]=1%mod;
        while(t){
            if(t&1)E=E*A;
            A=A*A;
            t>>=1;
        }
        return E;
    }
};
bool ok(LL l,LL r,LL g,LL k){
    r-=r%g;
    r-=(k-1)*g;
    return r>=l;
}
int main(){
    //freopen("F.in","r",stdin);
    //freopen("Fwa.out","w",stdout);
    LL l,r,k;
    while(cin>>mod>>l>>r>>k){
        LL ge;
        if(k==1)ge=r;
        else {
            vector<LL>F;
            for(LL u=1;u*u<=r;u++)
                F.PB(u),F.PB(r/u);
            sort(F.OP,F.ED);
            F.erase(unique(F.OP,F.ED),F.ED);
            ge=(r-l)/(k-1);
            while(ge>1&&!ok(l,r,ge,k)){
                int id=lower_bound(F.OP,F.ED,ge)-F.OP;
                ge=F[id-1];
            }
        }
        mat A;
        A[0][0]=A[0][1]=A[1][0]=1%mod;
        A=A^ge;
        cout<<A[1][0]%mod<<"\n";
    }
    return 0;
}
/*
1000000007
1
1000000000000
3
*/
