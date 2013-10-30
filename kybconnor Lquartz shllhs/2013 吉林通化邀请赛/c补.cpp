//kybconnor
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char ini[555][555];
char mp[555][555];
int dp[555][555];
int fp[555][555];
int n, m;
/*
2
5 5
abbaa
batqs
btwed
artyf
ghjkl
*/
int solve (char map[555][555]) {
  memset (dp, 0, sizeof dp);
  memset (fp, 0, sizeof fp);
  int i, j;
  for (i = 0; i < m; i++) dp[0][i] = 1;
  for (i = 0; i < n; i++) dp[i][0] = 1;
  for (i = 0; i < m; i++) fp[0][i] = 1;
  for (i = 0; i < n; i++) fp[i][0] = 1;
  for (i = 1; i < n; i++) for (j = 1; j < m; j++) {
      if (map[i - 1][j] != map[i][j - 1]) dp[i][j] = 1;
      else {
        int s = min (min (dp[i][j - 1] - 1, dp[i - 1][j] - 1), dp[i][j]);
        for (; i >= s && j >= s && map[i - s][j] == map[i][j - s]; s++);
        dp[i][j] = s;
      }
    }
  int mx = 1;
  for (i = 1; i < n; i++) for (j = 1; j < m; j++)
      fp[i][j] = min (dp[i][j], fp[i - 1][j - 1] + 2);
  for (i = 1; i < n; i++) for (j = 1; j < m; j++)
      mx = max (mx, fp[i][j]);
//  for (i = 0; i < n; i++) printf ("\n%s", map[i]);
//  for (i = 0; i < n; i++) {
//    printf ("\n");
//    for (j = 0; j < m; j++) printf ("%2d", dp[i][j]);
//  }
//  printf ("\n");
//  for (i = 0; i < n; i++) {
//    printf ("\n");
//    for (j = 0; j < m; j++) printf ("%2d", fp[i][j]);
//  }
//  printf ("\n");
//    printf("%d\n",mx);
  return mx;
}
int main() {
  int T;
  scanf ("%d", &T);
  while (T--) {
    int i, j;
    scanf ("%d%d", &n, &m);
    for (i = 0; i < n; i++) scanf ("%s", ini[i]);
    int ans = solve (ini);
    for (i = 0; i < n; i++) for (j = 0; j < m; j++)
        mp[i][j] = ini[n - 1 - i][j];
    ans = max (ans, solve (mp));
    for (i = 0; i < n; i++) for (j = 0; j < m; j++)
        mp[i][j] = ini[i][m - 1 - j];
    ans = max (ans, solve (mp));
    for (i = 0; i < n; i++) for (j = 0; j < m; j++)
        mp[i][j] = ini[n - 1 - i][m - 1 - j];
    ans = max (ans, solve (mp));
    printf ("%d\n", (ans + 1) *ans / 2);
  }
  return 0;
}
