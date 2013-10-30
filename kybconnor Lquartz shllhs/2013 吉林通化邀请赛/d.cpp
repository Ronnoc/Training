//lquartz
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 11000
#define M 110000
struct node {
  int u, v;
} edge[M];
int father[N];
int ans[M];
int n, m;

int getfa (int x) {
  if (father[x] == x) return x;
  else return (father[x] = getfa (father[x]));
}

int main() {
  while (scanf ("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < m; i++) {
      scanf ("%d%d", &edge[i].u, &edge[i].v);
    }
    for (int i = 0; i < n; i++)
      father[i] = i;
    ans[m - 1] = n;
    for (int i = m - 1; i > 0; i--) {
      int x = getfa (edge[i].u), y = getfa (edge[i].v);
      if (x != y) {
        father[x] = y;
        ans[i - 1] = ans[i] - 1;
      } else {
        ans[i - 1] = ans[i];
      }
    }
    for (int i = 0; i < m; i++)
      printf ("%d\n", ans[i]);
  }
  return 0;
}
