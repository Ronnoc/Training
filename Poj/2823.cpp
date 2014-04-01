#include <cstdio>
#include <algorithm>
using namespace std;
#define MXN 1000000
#define INF 2147483647
#define MP make_pair
#define R(x) (x*2+1)
#define L(x) (x*2)
#define AA first
#define BB second
struct node {
	int l, r, mn, mx;
} seg[4 * MXN + 10];
void build (int l, int r, int t) {
	seg[t].l = l;
	seg[t].r = r;
	seg[t].mn = INF, seg[t].mx = -INF;
	if (l == r) return;
	int mid = (l + r) / 2;
	build (l, mid, L (t));
	build (mid + 1, r, R (t));
}
void update (int l, int r, int t, int val) {
	node &z = seg[t];
	z.mn = min (z.mn, val), z.mx = max (z.mx, val);
	if (z.l == z.r) return;
	int mid = (z.l + z.r) / 2;
	if (mid >= r) update (l, r, L (t), val);
	else update (l, r, R (t), val);
}
pair<int, int> query (int l, int r, int t) {
	node &z = seg[t];
	if (z.l == l && z.r == r) return MP (z.mn, z.mx);
	int mid = (z.l + z.r) / 2;
	if (mid >= r) return query (l, r, L (t));
	else if (l >= mid + 1) return query (l, r, R (t));
	else {
		pair<int, int> ll, rr;
		ll = query (l, mid, L (t));
		rr = query (mid + 1, r, R (t));
		return MP (min (ll.AA, rr.AA), max (ll.BB, rr.BB));
	}
}
int x[MXN + 10], n, k;
int r1[MXN + 10], r2[MXN + 10];
int main() {
	while (~scanf ("%d%d", &n, &k)) {
		int i;
		for (i = 1; i <= n; i++) scanf ("%d", &x[i]);
		
		build (1, n, 1);
		for (i = 1; i <= n; i++) update (i, i, 1, x[i]);
		for (i = 1; i + k - 1 <= n; i++) {
			pair<int, int> X = query (i, i + k - 1, 1);
			r1[i] = X.AA, r2[i] = X.BB;
		}
		for (i = 1; i + k - 1 < n; i++) printf ("%d ", r1[i]);
		printf ("%d\n", r1[i]);
		for (i = 1; i + k - 1 < n; i++) printf ("%d ", r2[i]);
		printf ("%d\n", r2[i]);
	}
	return 0;
}
