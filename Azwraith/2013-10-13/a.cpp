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

vector<int>G[11];
int x[33333], y[33333];
int main() {
	int n;
	while (~scanf ("%d", &n)) {
		int i;
		for (i = 0; i < 4; i++) G[i].clear();
		for (i = 1; i <= 5 * n; i++) {
			scanf ("%d%d", &x[i], &y[i]);
			x[i] += 200000; y[i] += 200000;
			int p = x[i] % 2, q = y[i] % 2;
			int id = (p << 1) + q;
			G[id].PB (i);
		}
		printf ("OK\n");
		for (i = 0; i < 4; i++)
			if (G[i].size() >= n) {
				for (int j = 0; j < n; j++) printf ("%d%c", G[i][j], ( (j + 1) == n) ? '\n' : ' ');
				break;
			}
	}
	return 0;
}
