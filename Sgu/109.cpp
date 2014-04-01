#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int num[111][111];
int main() {
	int i, n, j;
	scanf ("%d", &n);
	int cnt = 0;
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) num[i][j] = ++cnt;
	vector<int>out;
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) if (i + j > n) out.push_back (num[i][j]);
	sort (out.begin(), out.end());
	if (out.size()) {
		printf ("%d", n);
		for (i = 0; i < out.size(); i++) printf (" %d", out[i]);
		printf ("\n");
	}
	int tot = out.size() + 1;
	int x = n - 1, y = 1;
//	system("pause");
	for (i = (n & 1) ? n + 2 : n + 1; tot < n * n; i += 2) {
		out.clear();
		int xx = x, yy = y;
		while (xx >= 0 && xx < n && yy >= 0 && yy < n) {
			out.push_back (num[xx][yy]);
			xx--;
			yy++;
		}
		printf ("%d", i);
		sort (out.begin(), out.end());
		for (int i = 0; i < out.size(); i++) printf (" %d", out[i]);
		printf ("\n");
		tot += out.size();
		if (y) y--;
		else x--;
//		printf("(%d,%d)\n",x,y);system("pause");
	}
	return 0;
}
