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

void get(vector<int>L,int d,int &ans){ 
  int dp[55],i,j; 
  memset(dp,0,sizeof dp); 
  for(i=0;i<L.SZ;i++)dp[i]=1; 
  for(i=1;i<L.SZ;i++){ 
    for(j=0;j<i;j++)if(L[i]-L[j]>=d){ 
      cmax(dp[i],dp[j]+1); 
    } 
    cmax(ans,dp[i]); 
  } 
} 
class CliqueParty { 
public: 
  int maxsize( vector <int> a, int K ) { 
    int i,j,k; 
    int ret=0; 
    sort(a.OP,a.ED); 
    for(i=0;i<a.SZ;i++){ 
      for(j=i+1;j<a.SZ;j++){ 
        vector<int>L; 
        for(k=i;k<=j;k++)L.PB(a[k]); 
        get(L,(a[j]-a[i]+K-1)/K,ret); 
      } 
    } 
    return ret; 
  } 
}; 