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

int f[1010][1010]; 
int dfs(int N,int K){ 
  if(~f[K][N])return f[K][N]; 
  if(K==0)return 0; 
  f[K][N]=0; 
  for(int i=1;i<=N/2;i++) 
    f[K][N]|=dfs(i,K-1); 
  return f[K][N]; 
} 
int G[1010][1010]; 
int t[1010]; 
class BearSpans { 
public: 
  vector <int> findAnyGraph( int n, int m, int k ) { 
    int i,j; 
    int N=n; 
    vector <int> ret; 
    memset(f,-1,sizeof f); 
    f[0][1]=1; 
    if(dfs(n,k)){ 
      memset(G,-1,sizeof G); 
      for(i=1;i<=n;i++)t[i]=i; 
      int w=1; 
      while(k){ 
        cout<<n<<" "<<k<<" ?\t"; 
        vector<int>L; 
        for(i=1;i<=n/2;i++)if(dfs(i,k-1))break; 
        for(j=1;i>1;){ 
          ret.PB(t[j]); 
          ret.PB(t[j+1]); 
          G[t[j]][t[j+1]]=w++; 
          cout<<"("<<t[j]<<","<<t[j+1]<<")"; 
          L.PB(t[j]); 
          i--;j+=2; 
        } 
        L.PB(t[j]); 
        for(;j<n;j++){ 
          ret.PB(t[j]); 
          ret.PB(t[j+1]); 
          G[t[j]][t[j+1]]=w++; 
          cout<<"("<<t[j]<<","<<t[j+1]<<")"; 
        } 
        cout<<"\n"; 
        for(i=0;i<L.SZ;i++)t[i+1]=L[i]; 
        for(i=0;i<L.SZ;i++)cout<<L[i]<<" ";cout<<"\n"; 
        n=L.SZ; 
        k--; 
      } 
      for(i=1;i<=N;i++)for(j=i+1;j<=N;j++)if(G[i][j]==-1&&w<=m){ 
        ret.PB(i); 
        ret.PB(j); 
        w++; 
      } 

    }else { 
      ret.PB(-1); 
    } 
    return ret; 
  } 
}; 
