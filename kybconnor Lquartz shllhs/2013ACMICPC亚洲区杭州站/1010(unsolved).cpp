#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const LL mod = 1000000007LL;
LL A[222];
LL comb[222][222];
LL dp[2][222][222];
LL res[222][222][222];
int broken[222];
void play (int n, int m) {
  broken[m] = 1;
  int i, j, k;
  memset (dp[1], 0, sizeof dp[1]);
  dp[1][0][m] = 1;
  dp[1][1][m - 1] = m;
  int p = 200;
  if (m >= 2) dp[1][2][m - 2] = comb[m][2];
  for (i = 1; i <= n; i++) {
    int to = (i + 1) % 2;
    memset (dp[to], 0, sizeof (dp[to]));
    for (j = 0; j <= m; j++)
      for (k = m - j; k >= 0; k--) {
        int now = j + (m - j - k) * 2;
        if (now > p) break;
        res[i][m][now] += dp[i % 2][j][k];
        int tp = dp[i % 2][j][k];
//        cout << i << " " << j << " " << k << " " << (m - j - k) << " " << tp << endl;
        dp[to][j][k] = (dp[to][j][k] + tp) % mod;
        if (j)
          dp[to][j - 1][k]		= (dp[to][j - 1][k] + j * tp) % mod;
        if (k && j + 1 <= m)
          dp[to][j + 1][k - 1]	= (dp[to][j + 1][k - 1] + k * tp) % mod;
        if (j >= 2)
          dp[to][j - 2][k]		= (dp[to][j - 2][k] + comb[j][2] * tp) % mod;
        if (k >= 2)
          dp[to][j + 2][k - 2]	= (dp[to][j + 2][k - 2] + comb[k][2] * tp) % mod;
        if (j && k)
          dp[to][j][k - 1]		= (dp[to][j][k - 1] + j * k * tp) % mod;
      }
  }
}
int main() {
  int i, j, k;
  memset (A, 0, sizeof A);
  A[0] = 1;
  for (i = 1; i <= 200; i++) A[i] = A[i - 1] * i % mod;
  memset (comb, 0, sizeof comb);
  comb[0][0] = 1, comb[1][0] = 1, comb[1][1] = 1;
  for (i = 2; i <= 200; i++) {
    comb[i][0] = 1;
    for (j = 1; j <= i; j++) comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
  }
  int T;
  scanf ("%d", &T);
  memset (broken, 0, sizeof broken);
  while (T--) {
    memset (dp, 0, sizeof dp);
    int n, m, p, q;
    scanf ("%d%d%d%d", &n, &m, &p, &q);
    if (n > m) swap (n, m); //n<=m;
    LL ans = 0;
    for (i = 0; i <= q; i++) for (j = 0; j <= p; j++) {
        if (!i && !j) continue;
        if (m - i > 0 && !broken[m - i]) play (m - i, m - i);
        if (n >= i)
          ans += comb[m][i] * comb[n][i] % mod * A[i] % mod * res[n - i][m - i][j] % mod;
      }
    ans %= mod;
    printf ("%d\n", ans);
  }
  return 0;
}
