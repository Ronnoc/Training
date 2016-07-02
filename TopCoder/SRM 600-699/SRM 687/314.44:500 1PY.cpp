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

int fa[55]; 
int getfa(int u){ 
  return fa[u]==u?u:fa[u]=getfa(fa[u]); 
} 
class AllGraphCuts { 
public: 
  vector <int> findGraph( vector <int> x ) { 
    int i,j,k; 
    vector <int> ret,fail; 
    fail.PB(-1); 
    int n=0; 
    while(n*n<x.SZ)n++; 
    map<int,vector<PII> >E; 
    map<int,vector<PII> >::iterator it; 
    for(i=0;i<n;i++) 
      for(j=0;j<n;j++){ 
        if(i<j){ 
          //cout<<i<<"~"<<j<<"?"<<x[i*n+j]<<"\n"; 
          E[-x[i*n+j]].PB(MP(i,j)); 
        } 
        if(i==j&&x[i*n+j]!=0){ 
          cout<<"wtf\n"; 
          return fail; 
        } 
        if(i>j&&x[i*n+j]!=x[j*n+i]){ 
          cout<<"wtf\n"; 
          return fail; 
        } 
      } 
    for(i=0;i<n;i++)fa[i]=i; 
    for(it=E.OP;it!=E.ED;++it){ 
      vector<PII>&L=(*it).BB; 
      int w=-(*it).AA; 
      for(i=0;i<L.SZ;i++){ 
        int u=L[i].AA,v=L[i].BB; 
        int fu=getfa(u),fv=getfa(v); 
        if(fu==fv)return fail; 
      } 
      for(i=0;i<L.SZ;i++){ 
        int u=L[i].AA,v=L[i].BB; 
        int fu=getfa(u),fv=getfa(v); 
        if(fu!=fv){ 
          fa[fu]=fv; 
          ret.PB(w*n*n+fu*n+fv); 
          //cout<<w<<"@"<<fu<<"~"<<fv<<"\n"; 
        } 
      } 
    } 
    return ret; 
  } 
};