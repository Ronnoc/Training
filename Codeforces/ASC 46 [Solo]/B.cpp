#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define OP begin()
#define ED end()
#define SZ size()
#define AA first
#define BB second
#define SQ(x) ((x)*(x))
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int,int> PII;
LL comb[105][105];
const LL MOD = 175781251;
LL g[105][105];
LL two[10005];
LL three[10005];
LL dp[105];
int main() {
  #define NAME "bipartite"
  freopen(NAME".in","r",stdin);
  freopen(NAME".out","w",stdout);
  int i,j;
  two[0]=1;
  for(i=1;i<=10000;i++)
    two[i]=two[i-1]*2%MOD;
  for(three[0]=i=1;i<=10000;i++)
    three[i]=three[i-1]*3%MOD;
  for(i=0; i<=100; i++) {
    comb[i][0]=comb[i][i]=1;
    for(j=1; j<i; j++)
      comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%MOD;
  }
  int p,q;
  memset(g,-1,sizeof g);
  for(i=1;i<=100;i++)g[1][i]=g[i][1]=two[i];
  for(p=1; p<=100; p++){
    for(q=1; p+q<=100; q++){
      g[p][q]=three[p*q];
      g[p][q]-=three[(p-1)*q];
      for(i=1;i<=p;i++)
        for(j=1;j<=q;j++)if(i<p||j<q)
          g[p][q]-=g[i][j]*comb[p-1][i-1]%MOD*comb[q][j]%MOD*three[(p-i)*(q-j)]%MOD;
      g[p][q]%=MOD;
      g[p][q]+=MOD;
      g[p][q]%=MOD;
    }
  }
  dp[0]=1;
  for(i=1;i<=100;i++){
    dp[i]=dp[i-1];
    for(p=1;p<=i;p++)
      for(q=1;p+q<=i;q++)
        dp[i]+=dp[i-p-q]*g[p][q]%MOD*comb[i-1][p-1]%MOD*comb[i-p][q]%MOD;
    dp[i]%=MOD;
  }
  while(~scanf("%d",&p)&&p)
    cout<<dp[p]<<"\n";
  return 0;
}

