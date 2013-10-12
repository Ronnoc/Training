#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
const int MXN=10000000;
int f[333333];
int self ( int x ) {
  int ret=x;
  while ( x ) {
    ret+=x%10;
    x/=10;
  }
  return ret;
}
int main() {
  int i,j;
  for ( i=0; i<=MXN/31+4; i++ ) f[i]= INT_MAX;
  for ( i=1; i<=MXN; i++ ) {
    int a=self ( i );
    int x=a/31,y=a%31;
    if ( f[x]& ( 1<<y ) ) f[x]-=1<<y;
  }
  int n,k;
  while ( cin>>n>>k ) {
    int tot=0;
    int s[5010],ans[5010],ps=0;
    vector<pair<int,int> >L;
    for ( i=1; i<=k; i++ ) {
      cin>>s[i];
      L.push_back(make_pair(s[i],i));
    }
    sort(L.begin(),L.end());
    for ( i=1; i<=n; i++ ) {
      int x=i/31,y=i%31;
      if ( f[x] & ( 1<<y ) ) {
        tot++;
        while ( ps<k&&tot==L[ps].first )
					{ans[L[ps].second]=i;ps++;}
      }
    }
    cout<<tot<<endl;
    for ( i=1; i<k; i++ ) cout<<ans[i]<<" "; cout<<ans[k]<<endl;
  }
  return 0;
}

