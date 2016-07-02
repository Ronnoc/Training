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

class MoveStones { 
public: 
  long long get( vector <int> a, vector <int> b ) { 
    int i,j,k; 
    long long ret=-1; 
    for(i=0;i<a.SZ;i++){ 
      LL tmp=0; 
      LL sum=0; 
      for(j=0;j<a.SZ;j++){ 
        int id=(i+j)%a.SZ; 
        sum+=a[id]-b[id]; 
        tmp+=fabs(sum); 
      } 
      if(sum!=0)return -1; 
      if(~ret)cmin(ret,tmp); 
      else ret=tmp; 
    } 
    return ret; 
  } 
}; 