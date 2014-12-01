#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;
void solve() {
  LL i,j;
  int n;
  while (cin>>n) {
    vector<LL>L;
    for (i=0; i<n; i++) {
      cin>>j;
      L.PB (j);
    }
    SORT (L);
    set<LL>D;
    for (i=1; i<L.SZ; i++) D.insert (L[i]-L[i-1]);
    if (D.empty()) cout<<-1<<endl;
    else if (D.size() >2) cout<<0<<endl;
    else if (D.SZ==1) {
      LL d=* (D.OP);
      if (d&&d%2==0) {
        if (L.SZ==2) {
          cout<<3<<endl;
          cout<<L[0]-d<<" ";
          cout<<L[0]+d/2<<" ";
          cout<<L[L.SZ-1]+d<<endl;
        } else {
          cout<<2<<endl;
          cout<<L[0]-d<<" ";
          cout<<L[L.SZ-1]+d<<endl;
        }
      } else if (d&1) {
        cout<<2<<endl;
        cout<<L[0]-d<<" ";
        cout<<L[L.SZ-1]+d<<endl;
      } else {
        cout<<1<<endl;
        cout<<L[0]<<endl;
      }
    } else {
      set<LL>::iterator it;
      it=D.OP;
      LL d1=*it;
      LL d2=* (++it);
      if (d1==2*d2||d2==2*d1) {
//				cout<<1<<endl;
        int cnt=0,ans=-1;
        for (i=1; i<L.SZ; i++) {
          LL mid=L[i]+L[i-1];
          if (mid&1);
          else {
            mid/=2;
            if (mid-L[i-1]==d1||mid-L[i-1]==d2) {
              cnt++;
              ans=mid;
            }
          }
        }
        if (cnt==1) cout<<1<<endl<<ans<<endl;
        else cout<<0<<endl;
      } else cout<<0<<endl;
    }
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
/*
8
-3 -2 -1 0 1 2 4 6
*/
