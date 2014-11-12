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

int f (int x) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}
int main() {
  int k, d, i;
  cin >> k >> d;
  if (k == 1) {
    cout << d << endl;
    return 0;
  }
  int tot = 9 * k;
  while (f (tot) != d) tot--;
  char s[9999];
  for (i = 0; i < k; i++) s[i] = '9';
  s[i] = '\0';
  i = k-1;
  while (tot < 9 * k) {
    if (s[i] > '0') s[i]--;
    else {
      i--;
      s[i]--;
    }
    tot++;
  }
  int sum = 0;
  for (i = 0; i < k; i++) sum += s[i] - '0';
  sum = f (sum);
  if (sum != d||s[0]=='0') {
    cout << "No solution\n";
    return 0;
  }
  cout << s << endl;
  return 0;
}
