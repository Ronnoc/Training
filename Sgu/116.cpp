#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MXN 10000
int isp[MXN+10];
int p[MXN+10],mp;
int dp[MXN+10],pre[MXN+10];
vector<int>L,Z;
int dfs ( int x ) {
  if ( dp[x]!=-1 ) return dp[x];
  if ( x==0 ) return dp[x]=0;
  for ( int i=0; i<L.size(); i++ ) {
    if ( x<L[i] ) continue;
    if ( dfs ( x-L[i] ) >-1 ) {
      Z.push_back ( L[i] );
      return dp[x]=1+dfs ( x-L[i] );
    }
  }
  return -1;
}
int main() {
  long long i,j; int x; L.clear();
  for ( i=2; i<=MXN; i++ ) isp[i]=1;
  for ( i=2; i<=MXN; i++ ) {
    if ( isp[i] )
      for ( j=i*2; j<=MXN; j+=i )
        isp[j]=0;
  }
  for ( i=2; i<=MXN; i++ ) if ( isp[i] ) p[++mp]=i;
  for ( i=mp; i>=2; i-- ) if ( isp[i] ) L.push_back ( p[i] );
  dp[0]=1; for ( i=1; i<=MXN; i++ ) dp[i]=0;
  for ( i=0; i<=MXN; i++ ) {
    if ( dp[i] )
      for ( j=0; j<L.size(); j++ ) {
        x=i+L[j];
        if ( x>MXN||dp[x] ) continue;
        dp[x]=1; pre[x]=L[j];
      }
  }
  cin>>x;
  Z.clear();
  if ( !dp[x] ) {
    cout<<0<<endl;
    return 0;
  }
  while ( x ) {
    Z.push_back ( pre[x] );
    x-=pre[x];
  }
  sort ( Z.begin(),Z.end() );
  cout<<Z.size() <<endl;
  for ( i=Z.size()-1; i>=0; i-- ) cout<<Z[i]<<" ";
  cout<<endl;
  return 0;
}
