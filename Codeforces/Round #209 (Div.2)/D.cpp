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
int n, a[333333];
int ldp[333333];
int rdp[333333];
void solve() {
	while (~scanf ("%d", &n)) {
		int i;
		for (i = 1; i <= n; i++) scanf ("%d", &a[i]);
		for (ldp[1] = 1, i = 2; i <= n; i++) {
			if (a[i - 1] % a[i]) ldp[i] = i;
			else {
				int tp = ldp[i - 1];
//              cout<<tp<<" ";
				while (tp >= 1 && (a[tp] % a[i] == 0)) {
					tp = ldp[tp] - 1;
//                  cout<<tp<<" ";
				}
				ldp[i] = tp + 1;
//              printf("ldp[%d]=%d\n",i,tp+1);
			}
		}
		for (rdp[n] = n, i = n - 1; i >= 1; i--) {
			if (a[i + 1] % a[i]) rdp[i] = i;
			else {
				int tp = rdp[i + 1];
				while (tp <= n && (a[tp] % a[i] == 0))
					tp = rdp[tp] + 1;
				rdp[i] = tp - 1;
			}
		}
//      for(i=1;i<=n;i++)cout<<ldp[i]<<" ";cout<<endl;
//      for(i=1;i<=n;i++)cout<<rdp[i]<<" ";cout<<endl;
		int ans = 0;
		for (i = 1; i <= n; i++) ans = max (ans, rdp[i] - ldp[i]);
		set<int>out;
		set<int>::iterator iter;
		for (i = 1; i <= n; i++) if (rdp[i] - ldp[i] == ans) out.insert (ldp[i]);
		printf ("%d %d\n", out.size(), ans);
		for (iter=out.OP; iter!=out.ED; ++iter) printf ("%d ", *iter);
		printf ("\n");
	}
}
int main() {
//  while (1)
	solve();
	return 0;
}
