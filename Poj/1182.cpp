#include <cstdio>
int A(int x){return 3*x;}
int B(int x){return 3*x+1;}
int C(int x){return 3*x+2;}
int fa[150010];
void inifa (int n) {
	for (int i = 1; i <= n; i++) {
		fa[ 3 * i ] = 3 * i;
		fa[ 3 * i + 1 ] = 3 * i + 1;
		fa[ 3 * i + 2 ] = 3 * i + 2;
	}
}
int findfa (int x) {
	return x == fa[x] ? x : fa[x] = findfa (fa[x]);
}
void mergefa (int x, int y) {
	int p = findfa (x), q = findfa (y);
	fa[p] = q;
}
int main() {
	int n, k;
	scanf ("%d%d", &n, &k);
	inifa (n);
	int ans = 0;
	while (k--) {
		int d, x, y;
		scanf ("%d%d%d", &d, &x, &y);
		if (x > n || y > n) {ans++; continue;}
		if (d == 2 && x == y) {ans++; continue;}
		if (d == 1) {
			int flag = findfa (A (x)) != findfa (B (y)) && findfa (A (x)) != findfa (C (y));
			if (flag) {
				mergefa (A (x), A (y));
				mergefa (B (x), B (y));
				mergefa (C (x), C (y));
			}
			else ans++;
		}
		else {
			int flag = findfa (A (x)) != findfa (A (y)) && findfa (A (x)) != findfa (C (y));
			if (flag) {
				mergefa (A (x), B (y));
				mergefa (B (x), C (y));
				mergefa (C (x), A (y));
			}
			else ans++;
		}
	}
	printf ("%d\n", ans);
	return 0;
}
