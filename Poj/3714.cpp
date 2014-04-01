#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
#define sqr(x) ((x) * (x))

const int MAXN = int (2e5 + 10);
double closed;

struct Point {
	double x, y;
	int id;
	};

Point pts[MAXN];
Point lP[MAXN];
Point rP[MAXN];

struct cmpY {
	bool operator() (const Point &lhs, const Point &rhs) {
		return lhs.y < rhs.y;
		}
	};

struct cmpX {
	bool operator() (const Point &lhs, const Point &rhs) {
		return lhs.x < rhs.x;
		}
	};

double dist (const Point &pt1, const Point &pt2) {
	return sqrt (sqr (pt1.x - pt2.x) + sqr (pt1.y - pt2.y));
	}

void findNearest (int l, int r) {
	if (r <= l) return;
	int mid = l + r >> 1;
	findNearest (l, mid);
	findNearest (mid + 1, r);
	int lm = mid, rm = mid + 1;
	while (lm - 1 >= l && pts[mid].x - pts[lm - 1].x < closed) --lm;
	while (rm + 1 <= r && pts[rm + 1].x - pts[mid].x < closed) ++rm;
	int nlP = 0, nrP = 0;
	for (int i = lm; i <= mid; ++i) lP[nlP++] = pts[i];
	for (int i = mid + 1; i <= rm; ++i) rP[nrP++] = pts[i];
	sort (lP, lP + nlP, cmpY());
	sort (rP, rP + nrP, cmpY());
	int j = 0;
	for (int i = 0; i < nlP; ++i) {
		while (j < nrP && rP[j].y < lP[i].y) ++j;
		for (int k = j - 3; k <= j + 3; ++k) {
			if (k < 0 || k >= nrP) continue;
			if (lP[i].id != rP[k].id) closed = min (dist (lP[i], rP[k]), closed);
			}
		}
	}

int main() {
	int i, n, T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf ("%lf%lf", &pts[i].x, &pts[i].y);
			pts[i].id = 0;
			}
		for (i = n + 1; i <= 2 * n; i++) {
			scanf ("%lf%lf", &pts[i].x, &pts[i].y);
			pts[i].id = 1;
			}
		sort (pts + 1, pts + 2 * n + 1, cmpX());
		int flag = 0;
		for (i = 1; i < 2 * n; i++) {
			if (dist (pts[i], pts[i + 1]) < 1e-5) {
				if(pts[i].id==pts[i+1].id)continue; 
				printf ("0.000\n");
				flag = 1;
				break;
				}
			}
		if (flag) continue;
		closed = 1e300;
		findNearest (1, 2 * n);
		printf ("%.3f\n", closed);
		}
	return 0;
	}
