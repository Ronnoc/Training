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
  int i,j;
  int n;
  while (cin>>n&&n) {
    vector<PII>L;
    int x,y;
    for (i=1; i<=n; i++) {
      cin>>x>>y;
      L.PB (MP (x,y));
    }
    SORT (L);
    int ans=2;
    map<int,int>X,Y;
    map<int,int>::iterator iter;
    for (i=0; i<L.SZ; i++) X[L[i].AA]++;
    for (i=0; i<L.SZ; i++) Y[L[i].BB]++;
    for (iter=X.OP; iter!=X.ED; ++iter)
      ans=max (ans, (*iter).BB);
    for (iter=Y.OP; iter!=Y.ED; ++iter)
      ans=max (ans, (*iter).BB);
    vector<pair<PII,int> >line;
    for (i=0; i<L.SZ; i++) for (j=i+1; j<L.SZ; j++) {
        if (L[i].AA==L[j].AA) continue;
        if (L[i].BB==L[j].BB) continue;
        int dx=L[j].AA-L[i].AA;
        int dy=L[j].BB-L[i].BB;
        int gcd=__gcd (dx,dy);
        dx/=gcd;
        dy/=gcd;
        //dx*(y-y0)=dy*(x-x0)
        line.PB (MP (MP (dx,dy),dx*L[i].BB-dy*L[i].AA));
      }
    SORT (line);
    int mc=1,now=1;
    for (i=1; i<line.SZ; i++) {
      if (line[i]==line[i-1]) now++;
      else {
        mc=max (mc,now);
        now=1;
      }
    }
    mc=max (mc,now);
    while (ans* (ans-1) /2<mc) ans++;
    cout<<ans<<endl;
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
