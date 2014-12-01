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
  string s;
  while (cin>>s) {
    string l,r;
    for (i=0; i<s.SZ; i++) if (s[i]=='|') break;
      else l+=s[i];
    for (; i<s.SZ; i++) if (s[i]=='|');
      else r+=s[i];
    cin>>s;
    int tot=l.SZ+r.SZ+s.SZ;
    int flag=1;
    if (l.SZ+s.SZ<r.SZ) flag=0;
    if (r.SZ+s.SZ<l.SZ) flag=0;
    if (tot&1) flag=0;
    if (flag) {
      int ll=tot/2-l.SZ;
      int rr=tot/2-r.SZ;
      int id=0;
      for (i=0; i<l.SZ; i++) cout<<l[i];
      while (ll--) cout<<s[id++];
      cout<<"|";
      for (i=0; i<r.SZ; i++) cout<<r[i];
      while (rr--) cout<<s[id++];
      cout<<endl;
    } else {
      cout<<"Impossible\n";
    }
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
