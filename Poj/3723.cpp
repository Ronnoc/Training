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
int fa[22222];
int getfa (int x) {return x==fa[x]?x:fa[x]=getfa (fa[x]);}
void solve() {
  int i,j,T;
  scanf("%d",&T);
  while (T--) {
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    vector<pair<int,PII> >L;
    for (i=0; i<=n+m; i++) fa[i]=i;
    for (i=1; i<=r; i++) {
      int u,v,w;
      scanf("%d%d%d",&u,&v,&w);
      v+=n;
      L.PB (MP (-w,MP (u,v)));
    }
    sort (L.begin(),L.ED);
    int tot= (n+m) *10000;
    for (i=0; i<L.SZ; i++) {
      int u=getfa (L[i].BB.AA);
      int v=getfa (L[i].BB.BB);
      if (u!=v) fa[u]=fa[v],tot+=L[i].AA;
    }
    printf("%d\n",tot);
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
