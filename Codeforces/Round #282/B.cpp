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

char s[100005],t[100005];
LL hs[100005],aim;
LL pw[100005];
LL MOD=1000000007;
LL Z=4423;
LL dp[100005];
LL S[100005];
LL SS[100005];
int ok[100005];
int main(){
    int i,j,k,_T;
    for(pw[0]=i=1;i<=100000;i++)
        pw[i]=pw[i-1]*Z;
    while(~scanf("%s%s",s+1,t+1)){
        int ls=strlen(s+1),lt=strlen(t+1);
        if(lt>ls){
            printf("0\n");
            continue;
        }
        aim=0;
        for(i=1;i<=lt;i++)
            aim=aim*Z+t[i]-'a'+1;
        hs[0]=0;
        for(i=1;i<=ls;i++)
            hs[i]=hs[i-1]*Z+s[i]-'a'+1;
        for(i=0;i<=ls;i++)ok[i]=0;
        for(i=lt;i<=ls;i++)
            ok[i]=(hs[i]-hs[i-lt]*pw[lt])==aim;
        dp[0]=0;
        SS[0]=S[0]=0;
        int last=-1;
        for(i=1;i<=ls;i++){
            if(ok[i]){
                if(~last){
                    dp[i]=dp[i-1]+SS[i-lt]-SS[last-1]+i-lt-last+1;
                    //cerr<<i<<"~"<<SS[i-lt]-SS[last-1]<<"~"<<i-lt-last+1<<"\n";
                }else {
                    dp[i]=dp[i-1]+i-lt+1;
                }
                last=i-lt+1;
            }else {
                dp[i]=dp[i-1];
            }
            dp[i]%=MOD;
            S[i]=(S[i-1]+dp[i])%MOD;
            SS[i]=(SS[i-1]+S[i])%MOD;
            //cerr<<dp[i]<<" "<<S[i]<<" "<<SS[i]<<"\n";
        }
        //cerr<<"\nans=";
        LL ans=((S[ls])%MOD+MOD)%MOD;
        cout<<ans<<"\n";
    }
    return 0;
}

