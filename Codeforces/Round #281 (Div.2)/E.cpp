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

LL MOD = 1000000007;
LL extGcd (LL a, LL b, LL &x, LL &y) {
    LL ret = a;
    if (b) {
        ret = extGcd (b, a % b, y, x);
        y -= (a / b) * x;
    } else x = 1, y = 0;
    return ret;
}
LL t,a,b;
map<pair<LL,LL>,LL>Ans;
LL solve(LL A,LL B){
    if(A==0&&B==0)return 1;
    if(A==0||B==0)return 0;
    map<pair<LL,LL>,LL>::iterator it;
    if(Ans.find(MP(A,B))!=Ans.ED)return (*it).BB;
    LL ret=0;
    LL u,v,g;
    g=extGcd(t,a,v,u);
    if((B-A)%g)return Ans[MP(A,B)]=0;
    u=-u;
    v*=(B-A)/g,u*=(B-A)/g;
    LL dv=a/g,du=t/g;
    if(u<0){
        LL k=(-u)/du;
        u+=k*du,v+=k*dv;
        while(u<0)u+=du,v+=dv;
    }
    if(v<0){
        LL k=(-v)/dv;
        u+=k*du,v+=k*dv;
        while(v<0)u+=du,v+=dv;
    }
    while(u*a<=A&&v*t<=B){
        ret+=solve(u,v);
        u+=du,v+=dv;
    }
    return Ans[MP(A,B)]=ret%MOD;
}
map<pair<LL,pair<LL,LL> >,LL >P;
LL play(LL A,LL t,LL B,LL z){
    if(z==1){
        return A==B;
    }
    if(B<A)return 0;
    if(A<B/z)return 0;
    if(P.find(MP(z,MP(A,B)))!=P.ED)
        return P[MP(z,MP(A,B))];
    LL ret=0,i=0;
    while(i<=A&&i*z<=B){
        ret+=play(A-i,t,B-i*z,z/t);
        i++;
    }
    return P[MP(z,MP(A,B))]=ret%MOD;
}
int main(){
    int i,j,k,_T;
    while(cin>>a>>t>>b){
        Ans.clear();
        if(t==a&&a!=b){
            printf("0\n");
            continue;
        }
        if(t==a&&a==b){
            if(a==1)printf("inf\n");
            else printf("2\n");
            continue;
        }
        if(t==1){
            if(b==1)printf("1\n");
            else printf("0\n");
            continue;
        }
        if(a==1){
            P.clear();
            LL z=1,c=0;
            while(z<=b/t)z*=t,c++;
            cout<<play(t,t,b,z)<<"\n";
            continue;
        }
        cout<<solve(t,b)<<"\n";
    }
    return 0;
}

