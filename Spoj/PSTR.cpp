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

const int N = 1000005;
const LL mod = 1000000007;
int mu[N],pre[N],p[N],pn;
bool flag[N];
void init(int n=N-5){
    pn=0,mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!flag[i])
            p[pn++]=i,mu[i]=-1,pre[i]=i;
        for(int j=0;j<pn&&i*p[j]<=n;j++){
            flag[i*p[j]]=1,pre[i*p[j]]=p[j];
            if(i%p[j]==0){
                mu[i*p[j]]=0;
                break;
            }else mu[i*p[j]]=-mu[i];
        }
    }
}
LL modPow(LL a,LL b,LL mod){
    LL ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
int main(){
    int i,j,k,_T;
    init();
    scanf("%d",&_T);
    while(_T--){
        int k,n;
        scanf("%d%d",&k,&n);
        vector<int>Z;
        int m=n;
        while(n>1){
            Z.PB(pre[n]);
            n/=pre[n];
        }
        sort(Z.OP,Z.ED);
        Z.erase(unique(Z.OP,Z.ED),Z.ED);
        LL ans=0;
        for(i=0;i<1<<Z.SZ;i++){
            int tmp=1;
            for(j=0;j<Z.SZ;j++)if(i>>j&1)
                tmp*=Z[j];
            ans+=modPow(k,m/tmp,mod)*mu[tmp];
//            cerr<<k<<"^"<<m/tmp<<" * mu|"<<tmp<<"\n";
        }
        ans=ans%mod+mod;
        printf("%lld\n",ans%mod);
    }
    return 0;
}

