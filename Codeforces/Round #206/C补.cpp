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
vector<int>L;
vector<int>::iterator iter;
int n, K;
vector<int>X;
bool check (int m) {
  int i,x;
  for(x=m;x<L.back();x+=m){
		iter=lower_bound(L.begin(),L.end(),x);
		if(iter!=L.begin())--iter;
		else continue;
		int li=*iter;
		if(li<m)return 0;
		int z=li%m;
		if(z>K)return 0;
  }
  for (i = L.size() - 1; i >= 0; i --) {
    if (L[i] < m) return 0;
    int x = L[i] % m;
    if (x > K) return 0;
  }
  return 1;
}
int main() {
  while (~scanf ("%d", &n)) {
    scanf ("%d", &K);
    int i, j, x;
    L.clear();
    X.clear();
    for (i = 1; i <= n; i++) {
      scanf ("%d", &x);
      L.PB (x);
    }
    sort (L.begin(), L.end());
    int ans = 1;
    if (check (K)) ans = K;
    for (i = L[0]; i > ans && (L[0] - i) <= K; i--)
      if (check (i)) ans = i;
    if (L[0] - ans <= K) {
      printf ("%d\n", ans);
      continue;
    }
    for (i = L[0]; (L[0] - i) <= K && i > ans; i--) {
      for (j = 2; j * j <= i; j++) {
        if (i % j) continue;
        if (j > ans && (L[0] - j) > K) X.PB (j);
        if ( (L[0] - i / j) > K && i / j > ans) X.PB (i / j);
      }
    }
    sort (X.begin(), X.end());
    X.erase (unique (X.begin(), X.end()), X.end());
    for (i = X.size() - 1; i >= 0 && X[i] > ans; i--)
      if (check (X[i])) ans = X[i];
    printf ("%d\n", ans);
  }
  return 0;
}
