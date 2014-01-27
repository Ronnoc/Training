//Lquartz 1Y
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

struct node {
	int x, y, n;
} xn[10100];
int n, m;
char strs[100];
int strin[10100][11];
map< string, int > dmap;
int tot;
int g[10100][11];

bool cmp (const node & a, const node & b) {
	if (a.x > b.x || (a.x == b.x && a.y > b.y)) return true;
	else return false;
}

int main() {
	freopen ("database.in", "r", stdin);
	freopen ("database.out", "w", stdout);
	while (scanf ("%d%d", &n, &m) != EOF) {
		gets (strs);
		dmap.clear();
		tot = 1;
		for (int i = 0; i < n; i++) {
			gets (strs);
			strin[i][0] = -1;
			int k = 1;
			for (int j = 0; strs[j] && k < m; j++)
				if (strs[j] == ',') {
					strin[i][k] = j;
					k++;
				}
			strin[i][m] = strlen (strs);
			for (int k = 0; k < m; k++) {
				string sx = "";
				for (int j = strin[i][k] + 1; j < strin[i][k + 1]; j++)
					sx += strs[j];
				if (dmap[sx] == 0) dmap[sx] = tot++;
				g[i][k] = dmap[sx];
			}
		}
		bool isPNF = true;
		int r1, r2, c1, c2;
		for (int xc = 0; xc < m; xc++) {
			for (int yc = xc + 1; yc < m; yc++) {
				for (int i = 0; i < n; i++) {
					xn[i].x = g[i][xc];
					xn[i].y = g[i][yc];
					xn[i].n = i;
				}
				sort (xn, xn + n, cmp);
				for (int i = 0; i < n - 1; i++) {
					if (xn[i].x == xn[i+1].x && xn[i].y == xn[i + 1].y) {
						isPNF = false;
						r1 = xn[i].n;
						r2 = xn[i + 1].n;
						c1 = xc;
						c2 = yc;
						break;
					}
				}
				if (!isPNF) break;
			}
			if (!isPNF) break;
		}
		if (isPNF) {
			printf ("YES\n");
		} else {
			printf ("NO\n");
			if (r1 > r2) { int t = r1; r1 = r2; r2 = t;}
			printf ("%d %d\n", r1+1, r2+1);
			printf ("%d %d\n", c1+1, c2+1);
			
		}
	}
	return 0;
}
