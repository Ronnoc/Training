//kybconnor
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
int isp[1 << 17];
int plist[1 << 16], pP;
int h[1 << 16];
LL dp[40];
LL solve (LL x) {
  memset (h, 0, sizeof h);
  int i, j;
  for (i = 1; i <= pP; i++) {
    if (x == 1) break;
    if (x % plist[i] == 0)
      while (x % plist[i] == 0) x /= plist[i], h[i]++;
  }
  LL res = 1;
  if (x > 1) res = dp[1];
  for (i = 1; i <= pP; i++) if (h[i]) res *= dp[h[i]];
  return res;
}
int main() {
  pP = 0;
  LL i, j;
  for (i = 3; i <= (1 << 16); i += 2) isp[i] = 1;
  for (plist[++pP] = 2, i = 3; i <= (1 << 16); i += 2)
    if (isp[i]) {
      plist[++pP] = i;
      for (j = i * i; j <= (1 << 16); j += 2 * i)
        isp[j] = 0;
    }
  for (i = 1; i <= 33; i++) {
    dp[i] = 3 * 2 * (i - 1);
    dp[i] += 6;
  }
  LL gcd, lcm;
  int T;
  cin >> T;
  while (T--) {
    cin >> gcd >> lcm;
    if (lcm % gcd != 0) {cout << 0 << endl; continue;}
    cout << solve (lcm / gcd) << endl;
  }
  return 0;
}
