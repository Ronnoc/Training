#include <cstdio>
#include <vector>
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

const LL mod = 1000000007;
LL dp[55][8];
int main(){
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        int n,m;
        scanf("%d%d",&n,&m);
        vector<LL>F;
        for(i=0;i<m;i++){
            int z;
            scanf("%d",&z);
            LL f=0;
            while(z--){
                scanf("%d",&j);
                f|=1LL<<(j-1);
            }
            F.PB(f);
        }
        LL ans=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                    for(k=0;k<n;k++){
                        int p,q;
                        for(p=0;p<=F.SZ;p++)
                            for(q=0;q<8;q++)
                                dp[p][q]=0;
                        dp[0][0]=1;
                        for(p=0;p<F.SZ;p++)
                            for(q=0;q<8;q++)if(dp[p][q]){
                                if(dp[p][q]>=mod)dp[p][q]%=mod;
                                int next=q;
                                if(F[p]>>i&1)next^=1;
                                if(F[p]>>j&1)next^=2;
                                if(F[p]>>k&1)next^=4;
                                dp[p+1][q]+=dp[p][q];
                                dp[p+1][next]+=dp[p][q];
                            }
                        ans+=dp[F.SZ][7];
                    }
        ans%=mod;
        printf("Case #%d: %lld\n",CA,ans);
    }
    return 0;
}

