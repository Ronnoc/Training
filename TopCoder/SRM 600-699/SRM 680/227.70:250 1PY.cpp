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

int dp[1005][55][55]; 
int lim[1005]; 
class BearFair { 
public: 
  string isFair( int n, int b, vector <int> u, vector <int> q ) { 
    int i,j,k; 
    string ret; 
    string yes="fair"; 
    string no="unfair"; 
    vector<PII>L; 
    for(i=0;i<u.SZ;i++)L.PB(MP(u[i],q[i])); 
    L.PB(MP(b,n)); 
    sort(L.OP,L.ED); 
    L.erase(unique(L.OP,L.ED),L.ED); 
    for(i=1;i<L.SZ;i++)if(L[i].AA==L[i-1].AA){ 
      return no; 
    } 
    memset(lim,-1,sizeof lim); 
    for(i=0;i<L.SZ;i++)lim[L[i].AA]=L[i].BB; 
    memset(dp,0,sizeof dp); 
    dp[0][0][0]=1; 
    for(i=0;i<b;i++)for(j=0;j<=n/2;j++)for(k=0;k<=n/2;k++)if(dp[i][j][k]){ 
      if(~lim[i]&&(j+k)!=lim[i])continue; 
      dp[i+1][j][k]=1; 
      if(i&1)dp[i+1][j+1][k]=1; 
      else dp[i+1][j][k+1]=1; 
    } 
    return dp[b][n/2][n/2]?yes:no; 
  } 
}; 