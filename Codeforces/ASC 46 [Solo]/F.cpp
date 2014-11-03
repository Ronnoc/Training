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
LL MOD = 998244353;
struct mat{
  LL _[4][4];
  mat(){memset(_,0,sizeof _);}
  LL *operator[](int id){return _[id];}
  friend mat operator *(mat A,mat B){
    mat C;
    int i,j,k;
    for(i=0;i<4;i++)for(j=0;j<4;j++)for(k=0;k<4;k++)
      C[i][j]+=A[i][k]*B[k][j];
    for(i=0;i<4;i++)for(j=0;j<4;j++)C[i][j]%=MOD;
    return C;
  }
  void init(){memset(_,0,sizeof _);}
  void eeee(){
    init();
    for(int i=0;i<4;i++)_[i][i]=1;
  }
};
int main(){
  #define NAME "figure"
  freopen(NAME".in","r",stdin);
  freopen(NAME".out","w",stdout);
  int n;
  while(~scanf("%d",&n)&&n){
    mat A;
    A[0][0]=A[0][1]=A[0][2]=A[1][0]=A[2][2]=A[2][3]=A[3][1]=A[3][3]=1;
    A[1][1]=A[1][2]=A[3][2]=2;
    mat E;
    E.eeee();
    while(n){
      if(n&1)E=E*A;
      A=A*A;
      n>>=1;
    }
    cout<<E[0][0]<<"\n";
  }
  return 0;
}

