//Lquartz
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define eps 1e-8
#define INF 1e20
#define N 100100
using namespace std;
struct point {
	int x, y;
};
int n, m, q;
point L[N], R[N], C[N];

double getx (double x1, double y1, double x2, double y2, double y) {
	return (y - y1) * (x2 - x1) / (y2 - y1) + x1;
}

bool cmp (const point & a, const point & b) {
	if (a.y < b.y || (a.y == b.y && a.x < b.x)) return true;
	return false;
}

int main() {
	int x, y;
	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf ("%d%d", &x, &y);
			L[i].x = x, L[i].y = y;
		}
		scanf ("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf ("%d%d", &x, &y);
			R[i].x = x; R[i].y = y;
		}
		scanf ("%d", &q);
		for (int i = 0; i < q; i++) {
			scanf ("%d%d", &x, &y);
			C[i].x = x; C[i].y = y;
		}
		L[n] = L[n-1];
		L[n].y++;
		R[m] = R[m-1];
		R[m].y++;
		double ans = INF;
		for (int l = 0, r = 0; l < n; l++) {
			y = L[l].y;
			while (r < m) {
				if (y >= R[r].y && y < R[r+1].y) break;
				r++;
			}
			if (r >= m) break;
			double xl = getx (L[l].x, L[l].y, L[l+1].x, L[l+1].y, y),
						 xr = getx (R[r].x, R[r].y, R[r+1].x, R[r+1].y, y);
			if (ans - (xr - xl) > eps) {
				ans = xr - xl;
			}
		}
		for (int r = 0, l = 0; r < m; r++) {
			y = R[r].y;
			while (l < n) {
				if (y >= L[l].y && y < L[l + 1].y) break;
				l++;
			}
			if (l >= n) break;
			double xl = getx (L[l].x, L[l].y, L[l+1].x, L[l+1].y, y),
						 xr = getx (R[r].x, R[r].y, R[r+1].x, R[r+1].y, y);
			if (ans - (xr - xl) > eps) {
				ans = xr - xl;
			}
		}
		int l = 0, r = 0, c = 0;
		sort (C, C + q, cmp);
		while (C[c].y < L[l].y || C[c].y < R[r].y) c++;
		//for(int i = 0; i < q; i++) printf("c %d %d\n", C[i].x, C[i].y);
		while (c < q) {
			y = C[c].y;
			while (l < n) {
				if (y >= L[l].y && y < L[l+1].y) break;
				l++;
			}
			while (r < m) {
				if (y >= R[r].y && y < R[r + 1].y) break;
				r++;
			}
			if (l >= n || r >= m) break;
			double xl = getx (L[l].x, L[l].y, L[l+1].x, L[l+1].y, y),
						 xr = getx (R[r].x, R[r].y, R[r+1].x, R[r+1].y, y);
			int tc = c;
			vector <double> X;
			X.push_back (xl);
			while (c < q) {
				if (C[c].y == C[tc].y) {
					double dx = C[c].x;
					if (dx - xl > eps && xr - dx > eps) {
						X.push_back (dx);
					}
					c++;
				} else break;
			}
			X.push_back (xr);
			double dmax = -INF;
			for (int i = 1; i < X.size(); i++) {
				if (X[i] - X[i-1] - dmax > eps) {
					dmax = X[i] - X[i-1];
				}
			}
			if (ans - dmax > eps) {
				ans = dmax;
			}
		}
		printf ("%.8lf\n", ans + eps);
	}
	return 0;
}
