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

int ok[55]; 
class MultiplicationTable2 { 
public: 
  int minimalGoodSet( vector <int> L ) { 
    int i,j,k; 
    int G[55][55]; 
    int n=1; 
    while(n*n<L.SZ)n++; 
    for(i=0;i<n;i++)if(L[i*n+i]==i)return 1; 
    int ret=n; 
    for(i=0;i<n;i++) 
      for(j=i+1;j<n;j++){ 
        vector<int>R; 
        memset(ok,0,sizeof ok); 
        queue<int>Q; 
        R.PB(i),R.PB(j); 
        ok[i]=ok[j]=1; 
        Q.push(i); 
        Q.push(j); 
        while(!Q.empty()){ 
          int u=Q.front(); 
          Q.pop(); 
          for(k=0;k<R.SZ;k++){ 
            int v=R[k]; 
            int p=L[v*n+u]; 
            int q=L[u*n+v]; 
            if(!ok[p]){ 
              Q.push(p); 
              R.PB(p); 
              ok[p]=1; 
            } 
            if(!ok[q]){ 
              Q.push(q); 
              R.PB(q); 
              ok[q]=1; 
            } 
          } 
        } 
        if(R.SZ<ret)ret=R.SZ; 
      } 
    return ret; 
  } 
}; 
