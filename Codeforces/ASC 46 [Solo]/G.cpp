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
int sg[105][3][3];//0=same 1=unique 2=empty
inline int f(int x){return x<2?1-x:x;}
int call(int l,int p,int q){
  if(l==0)return 0;
  if(l==1){
    if(p==0||q==0)return 0;
    return 1;
  }
  if(p>q)swap(p,q);
  int &tp=sg[l][p][q];
  if(~tp)return tp;
  vector<int>L;
  int i;
  if(p!=0){
    L.PB(call(l-1,1,f(q)));
  }
  if(q!=0){
    L.PB(call(l-1,f(p),1));
  }
  for(i=2;i<l;i++)
    L.PB(call(i-1,f(p),1)&call(l-i,1,f(q)));
  for(i=0;i<L.SZ;i++)if(!L[i])return tp=1;
  return tp=0;
}
LL comb[105][105];
const LL MOD = 242121643;
int main(){
  #define NAME "game"
  freopen(NAME".in","r",stdin);
  freopen(NAME".out","w",stdout);
  int n,k,m,i,j;
  for(i=0;i<=100;i++){
    comb[i][0]=comb[i][i]=1;
    for(j=1;j<i;j++)
      comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%MOD;
  }
  while(~scanf("%d%d",&n,&m)){
    if(!n&&!m)break;
    int s=0;
    for(i=0;i<n;i++){
      scanf("%d",&j);
      if(j==1)s++;
    }
    LL ans=0;
    for(i=1;i<=s&&i<=m;i+=2)
      ans+=comb[s][i]*comb[n-s][m-i];
    cout<<ans%MOD<<"\n";
  }
  return 0;
}

