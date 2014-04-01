#include <cstdio>
#include <vector>
using namespace std;
#define PB push_back
int d[ (1 << 20) + 5];
int bl[ (1 << 20) + 5];
const int UP = 1 << 20;
vector<int>L[2];
int main() {
	int t, i;
	scanf ("%d", &t);
	while (t--) {
		int n, x;
		scanf ("%d", &n);
		for (i = 0; i < UP; i++) d[i] = -1;
		for (i = 0; i < UP; i++) bl[i] = -1;
		L[0].clear(), L[1].clear();
		int jump = 0;
		for (i = 0; i < n; i++) {
			scanf ("%x", &x);
			L[0].PB (x);
			if (d[x] == -1) {d[x] = 0, bl[x] = x;}
			else jump = 1;
		}
		if (jump) {printf ("%d\n", 0); continue;}
		int  flag = 0, ans = 21;
		for (int z = 1; !flag ; z++) {
			int fm = (z - 1) % 2, to = z % 2;
			while (!L[fm].empty()) {
				int tp = L[fm].back(), dst;
				L[fm].pop_back();
				for (i = 0; i < 20; i++) {
					if (tp & (1 << i))
						dst = tp & (~ (1 << i));
					else
						dst = tp | (1 << i);
					if (d[dst] == -1)
						d[dst] = z, bl[dst] = bl[tp], L[to].PB (dst);
					else if (bl[tp] != bl[dst])
						flag = 1, ans = min (ans, z + d[dst]);
				}
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
