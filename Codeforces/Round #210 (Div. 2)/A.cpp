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
void solve() {
  int n, k;
  while (scanf ("%d%d", &n, &k) != EOF) {
    int i, j;
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) if (i == j) printf ("%d ", k);
        else printf ("0 ");
  }
}
int main() {
//  while (1)
    solve();
  return 0;
}
