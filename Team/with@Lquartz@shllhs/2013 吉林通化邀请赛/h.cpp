//shllhs
#include<cstdio>
#include<cstring>
#include<iostream>
#define inf 1000000007
using namespace std;
int a[30], b[30], dp[30][30][30][30];
int dfs (int l, int r, int L, int R) {
  if (dp[l][r][L][R] != -1) return dp[l][r][L][R];
  int ret;
  if ( (r - l + 1 + R - L + 1) % 2 == 0) {
    ret = 0;
    if (l <= r) ret = max (ret, dfs (l + 1, r, L, R) + a[l]);
    if (l <= r) ret = max (ret, dfs (l, r - 1, L, R) + a[r]);
    
    if (L <= R) ret = max (ret, dfs (l, r, L + 1, R) + b[L]);
    if (L <= R) ret = max (ret, dfs (l, r, L, R - 1) + b[R]);
  } else {
    ret = inf;
    if (l <= r) ret = min (ret, dfs (l + 1, r, L, R));
    if (l <= r) ret = min (ret, dfs (l, r - 1, L, R));
    
    if (L <= R) ret = min (ret, dfs (l, r, L + 1, R));
    if (L <= R) ret = min (ret, dfs (l, r, L, R - 1));
  }
  return dp[l][r][L][R] = ret;
}
int main() {
  int t, n, i, j;
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d", &n);
    for (i = 1; i <= n; i++) scanf ("%d", &a[i]);
    for (i = 1; i <= n; i++) scanf ("%d", &b[i]);
    memset (dp, -1, sizeof (dp));
    printf ("%d\n", dfs (1, n, 1, n));
  }
  return 0;
}
