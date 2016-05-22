//Lquartz
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 210
#define M 210
#define INF (1 << 10)
int n, m, t;
char g[N][M];
int f[N][M];
struct node {
	int x, y, n;
	node() {};
	node (int x, int , int n) :x (x), y (y), n (n) {}
} now;
vector <node> pvec;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int used[20];

int check (int t, int j) {
	int cover[20];
	memset (cover, 0, sizeof (cover));
	int res = 0;
	for (int i = 0; i < t; i++) {
		if (used[i] == 1) {
			cover[f[pvec[i].x][pvec[i].y]] = 1;
			int x1 = pvec[i].x + dx[0], y1 = pvec[i].y + dy[0];
			int x2 = pvec[i].x + dx[1], y2 = pvec[i].y + dy[1];
			if (g[x1][y1] == '#' || g[x2][y2] == '#') return INF;
			cover[f[x1][y1]] = cover[f[x2][y2]] = 1;
			res++;
		} else if (used[i] == 2) {
			cover[f[pvec[i].x][pvec[i].y]] = 1;
			int x1 = pvec[i].x + dx[j], y1 = pvec[i].y + dy[j];
			int x2 = pvec[i].x + dx[ (j + 1) % 4], y2 = pvec[i].y + dy[ (j + 1) % 4];
			if (g[x1][y1] == '#' || g[x2][y2] == '#') return INF;
			cover[f[x1][y1]] = cover[f[x2][y2]] = 1;
			res++;
		}
	}
	for (int i = 0; i < t; i++)
		if (!cover[i]) return INF;
	return res;
}

int main() {
	while (scanf ("%d%d", &n, &m) != EOF && n && m) {
		pvec.clear();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				g[i][j] = '*', f[i][j] = 18;
		for (int i = 1; i <= n; i++) {
			scanf ("%s", &g[i][1]);
			for (int j = 1; j <= m; j++) {
				if (g[i][j] == '.') {
					now.x = i;
					now.y = j;
					now.n = 0;
					pvec.push_back (now);
					f[i][j] = pvec.size()-1;
				}
			}
		}
		t = pvec.size();
		if (t == 0) {
			printf ("0\n");
		} else {
			int ans = INF;
			for (int i = 0; i < t; i++)
				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < (1 << t); k++) {
						memset (used, 0, sizeof (used));
						for (int l = 0; l < t; l++)
							if (k & (1 << l)) used[l] = 1;
							else used[l] = 0;
						used[i] = 2;
						int temp = check (t, j);
						ans = min (ans, temp);
					}
				}
			if (ans == INF)
				printf ("-1\n");
			else printf ("%d\n", ans);
		}
//        for(int i = 1; i <= n; i++)
//            printf("%s\n", &g[i][1]);

	}
	return 0;
}
