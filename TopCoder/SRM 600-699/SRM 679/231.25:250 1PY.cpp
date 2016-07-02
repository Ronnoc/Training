#include <bits/stdc++.h> 
using namespace std; 
#define AA first 
#define BB second 
#define OP begin() 
#define ED end() 
#define SZ size() 
#define MP make_pair 
#define PB push_back 
#define cmax(x,y) x=max((x),(y)) 
#define cmin(x,y) x=min((x),(y)) 

typedef long long LL; 
typedef pair<int,int> PII; 

int dp[2505]; 
int w[2505]; 
vector<int>G[2505]; 
int dfs(int u){ 
  int tmp=0; 
  for(int i=0;i<G[u].SZ;i++){ 
    int w=dfs(G[u][i]); 
    tmp+=max(w,0); 
  } 
  int ret=max(tmp+w[u],0); 
  cout<<u<<" "<<ret<<"\n"; 
  return ret; 
} 
class FiringEmployees { 
public: 
  int fire( vector <int> fa, vector <int> s, vector <int> p ) { 
    int i,j,k,n=fa.SZ; 
    for(i=0;i<=n;i++)G[i].clear(),w[i+1]=p[i]-s[i]; 
    for(i=0;i<n;i++)G[fa[i]].PB(i+1); 
    int ret=dfs(0); 
    return ret; 
  } 
}; 

