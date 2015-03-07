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

int ocur[100005];
int psum[100005];
vector<int>L[100005];
const LL MOD = 1000000007;
int C[100005];
LL mpow(LL a,LL n){
    LL ret=1;
    while(n){
        if(n&1)ret=ret*a%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return ret%MOD;
}
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n;
    for(i=1;i<=100000;i++)
        for(j=i;j<=100000;j+=i)
            L[j].PB(i);
    int F=0;
    while(~scanf("%d",&n)){
        memset(ocur,0,sizeof ocur);
        for(i=1;i<=n;i++){
            scanf("%d",&k);
            ocur[k]++;
        }
        psum[0]=0;
        for(i=1;i<=100000;i++)
            psum[i]=psum[i-1]+ocur[i];
        LL ans=0;
        for(int x=1;x<=100000;x++){
            int y=L[x].SZ;
            C[y]=psum[100000]-psum[x-1];
            if(C[y]==0)continue;
            for(i=1;i<L[x].SZ;i++)
                C[i]=psum[L[x][i]-1]-psum[L[x][i-1]-1];
            //cout<<x<<": ";
            //for(i=1;i<=y;i++)cout<<C[i]<<" ";
            LL add=1;
            for(i=1;i<y;i++)
                add=add*mpow(i,C[i])%MOD;
            add=add*(mpow(y,C[y])-mpow(y-1,C[y]))%MOD;
            //cout<<add<<"\n";
            ans+=add%MOD;
        }
        ans%=MOD;
        ans+=MOD;
        ans%=MOD;
        cout<<ans<<"\n";
    }
    return 0;
}

