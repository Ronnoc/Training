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

typedef long long LL;
typedef pair<int, int> PII;

int N, Q;
int inSET[11111][55];
int main() {
  while (~scanf ("%d", &N)) {
    int i, j;
    for (i = 1; i <= 10000; i++) for (j = 1; j * 30 <= N + 30; j++) inSET[i][j] = 0;
    for (i = 1; i <= N; i++) {
      int cap;
      scanf ("%d", &cap);
      for (j = 1; j <= cap; j++) {
        int x;
        scanf ("%d", &x);
        int l = i / 30, r = i % 30;
        inSET[x][l] |= 1 << r;
      }
    }
    scanf ("%d", &Q);
    while (Q--) {
      int i;
      int p, q;
      scanf ("%d%d", &p, &q);
      int flag = 0;
      for (i = 0; !flag && i * 30 <= N + 30; i++)
        if (inSET[p][i]&inSET[q][i]) flag = 1;
      if (flag) printf ("Yes\n");
      else printf ("No\n");
    }
  }
  
  return 0;
}
