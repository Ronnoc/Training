// Paste me into the FileEdit configuration dialog
 
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
 
int G[22][22];
class MultiplicationTable3 {
public:
  vector <int> construct( int x ) {
    int i,j,k;
    vector<int>Q;
    cout<<x<<"\n";
    while(x){
      if(x&1)Q.PB(1);
      else Q.PB(0);
      x/=2;
    }
    reverse(Q.OP,Q.ED);
    vector<int>L;
    for(i=1;i<Q.SZ;i++){
      L.PB(0);
      if(Q[i])L.PB(1);
    }
    G[0][0]=0;
    int n=1;
    for(k=0;k<L.SZ;k++){
      if(L[k]){
        for(i=0;i<n;i++)
          G[i][n]=G[n][i]=i+1;
        G[n][n]=0;
        n++;
      }else {
        for(i=0;i<n;i++)
          G[i][n]=G[n][i]=i;
        G[n][n]=0;
        n++;
      }
    }
    vector <int> ret;
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        ret.PB(G[i][j]);
/*
    for(i=0;i<n;i++,cout<<"\n")
      for(j=0;j<n;j++)cout<<G[i][j]<<" ";*/
    return ret;
  }
};
 
 
 
// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor

