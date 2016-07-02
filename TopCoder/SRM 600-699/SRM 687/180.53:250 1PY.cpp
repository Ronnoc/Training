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

LL A[99],S[99]; 
vector<int>solve(int id,LL x){ 
  //cerr<<id<<" "<<x<<"\t["<<A[id]<<"\n"; 
  vector<int>ret; 
  if(id==0)return ret; 
  if(x>S[id])return ret; 
  if(x<A[id]){ 
    return solve(id-1,x); 
  }else if(x==A[id]){ 
    ret.PB(id); 
    return ret; 
  }else { 
    vector<int>tmp=solve(id-1,x-A[id]); 
    if(!tmp.empty()){ 
      tmp.PB(id); 
      return tmp; 
    } 
    else return solve(id-1,x); 
  } 
} 
class AlmostFibonacciKnapsack { 
public: 
  vector <int> getIndices( long long x ) { 
    cout<<"aim:"<<x<<"\n"; 
    int i,j,k; 
    vector <int> ret; 
    A[1]=2; 
    A[2]=3; 
    for(i=3;i<=87;i++)A[i]=A[i-1]+A[i-2]-1; 
    S[0]=0; 
    for(i=1;i<=87;i++)S[i]=S[i-1]+A[i]; 
    ret=solve(87,x); 
    if(ret.empty())ret.PB(-1); 
    else { 
      cout<<"get?"; 
      LL tmp=0; 
      for(i=0;i<ret.SZ;i++)tmp+=A[ret[i]]; 
      cout<<tmp<<"\n"; 
    } 
    return ret; 
  } 
}; 