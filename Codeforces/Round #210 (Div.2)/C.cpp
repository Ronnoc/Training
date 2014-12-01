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

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()

typedef long long LL;
typedef pair<int, int> PII;
int ub[5555];
int add[5555];
int n, m;
int t[5555], l[5555], r[5555], x[5555];
int is[5555];
void solve() {
  memset (add, 0, sizeof add);
  scanf ("%d%d", &n, &m);
  int i, j;
  for (j = 1; j <= n; j++) ub[j] = 100000000;
  for (i = 1; i <= m; i++) {
    scanf ("%d%d%d%d", &t[i], &l[i], &r[i], &x[i]);
    if (t[i] == 1) {
      for (j = l[i]; j <= r[i]; j++)
        add[j] += x[i];
    } else {
      for (j = l[i]; j <= r[i]; j++)
        ub[j] = min (ub[j], x[i] - add[j]);
    }
  }
//  for (i = 1; i <= n; i++) printf ("%d%c", ub[i], i == n ? '\n' : ' ');
//  for (j = 1; j <= n; j++) is[j] = ub[j];
//  for (i = 1; i <= m; i++) {
//    if (t[i] == 1) {
//      for (j = l[i]; j <= r[i]; j++)
//        is[j] += x[i];
//    } else {
//      for (j = l[i]; j <= r[i]; j++)
//        if (is[j] > x[i]) {
//          ub[j] -= is[j] - x[i];
//          is[j] = x[i];
//        }
//    }
//  }
  for (j = 1; j <= n; j++) is[j] = ub[j];
  int wa = 0;
  for (i = 1; i <= m; i++) {
//		for (j = 1; j <= n; j++) printf ("%d%c", is[j], j == n ? '\n' : ' ');
    if (t[i] == 1) {
      for (j = l[i]; j <= r[i]; j++)
        is[j] += x[i];
    } else {
      int mx = is[l[i]];
      for (j = l[i]; j <= r[i]; j++)
        mx = max (mx, is[j]);
      if (mx != x[i]) wa = 1;
    }
  }
//	for (j = 1; j <= n; j++) printf ("%d%c", is[j], j == n ? '\n' : ' ');
	if(wa)cout<<"NO\n";else cout<<"YES\n";	
  if(!wa)for (i = 1; i <= n; i++) printf ("%d%c", ub[i], i == n ? '\n' : ' ');
}
int main() {
//	while(1)
  solve();
  return 0;
}
