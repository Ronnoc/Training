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
const LL MOD = 1000000007;
char s[100005];
LL inv[100005];
LL comb(int n,int m){
    if(m<0||m>n)return 0;
    if(n==m||m==0)return 1;
    return comb(n,m-1)*(n-m+1)%MOD*inv[m]%MOD;
}
LL ten[100005];
LL sum[100005];
int n,k;
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,_T;
    for(inv[1]=1,i=2;i<=100000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
    for(ten[0]=i=1;i<=100000;i++)ten[i]=ten[i-1]*10%MOD;
    while(~scanf("%d%d",&n,&k)){
        scanf("%s",s);
        sum[0]=s[0]-'0';
        for(i=1;i<n;i++)
            sum[i]=sum[i-1]+s[i]-'0';
        if(k==0){
            LL ans=0;
            for(i=0;i<n;i++)
                ans=(ans*10+(s[i]-'0'))%MOD;
            cout<<ans<<"\n";
            continue;
        }
        LL ans=0;
        LL now=comb(n-1,k);
        for(j=n-1;j>=0;j--){
            ans+=now*ten[n-1-j]%MOD*(s[j]-'0')%MOD;
            int p=j,q=k;
            now=now*(p-q)%MOD*inv[p]%MOD;
        }
        LL temp=comb(n-2,k-1);
        for(j=0;j<=n-k-1;j++){
            int I=n-2-j;
            ans+=temp*ten[j]%MOD*sum[I]%MOD;
            //temp from C(n-2-j,k-1) => C(n-3-j,k-1)
            int p=n-2-j,q=k-1;
            //cerr<<j<<" C("<<p<<","<<q<<")="<<temp<<" "<<ten[j]<<" "<<I<<" "<<sum[I]<<"\n";
            temp=temp*(p-q)%MOD*inv[p]%MOD;
        }
        cout<<ans%MOD<<"\n";
    }
    return 0;
}

