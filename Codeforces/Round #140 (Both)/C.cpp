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

LL n,mod;
LL mpow(LL x,LL t){
    LL ret=1%mod;
    while(t){
        if(t&1)ret=ret*x%mod;
        x=x*x%mod;
        t>>=1;
    }
    return ret;
}
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    while(cin>>n>>mod){
        cout<<(mpow(3,n)-1+mod)%mod<<"\n";
    }
    return 0;
}

