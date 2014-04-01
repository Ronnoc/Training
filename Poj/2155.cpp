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
#define LB(x) (x&(-x))

typedef long long LL;
typedef pair<int, int> PII;

int p[1111][1111];
void change (int x, int y) {
	for (int i = x; i && i <= 1005; i += LB (i))
		for (int j = y; j && j <= 1005; j += LB (j))
			p[i][j]++;
}
int get (int x, int y) {
	int tot = 0;
	for (int i = x; i; i -= LB (i))
		for (int j = y; j; j -= LB (j))
			tot += p[i][j];
	return tot % 2;
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		memset (p, 0, sizeof p);
		int n, m;
		scanf ("%d%d%*c", &n, &m);
		for (int M = 0; M < m; M++) {
			char c = getchar();
			if (c == 'C') {
				int x1, y1, x2, y2;
				scanf ("%d%d%d%d%*c", &x1, &y1, &x2, &y2);
				change (x1 - 1, y1 - 1);
				change (x2, y1 - 1);
				change (x1 - 1, y2);
				change (x2, y2);
			}	else {
				int x, y;
				scanf ("%d%d%*c", &x, &y);
				int tp = 0;
				tp += get (n + 1, n + 1);
				tp += get (x - 1, n + 1);
				tp += get (n + 1, y - 1);
				tp += get (x - 1, y - 1);
				printf ("%d\n", tp % 2);
			}
		}
		if (T) printf ("\n");
	}
	return 0;
}
