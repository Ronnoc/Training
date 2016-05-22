//Lquartz
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2100
#define M 2001000
struct node {
	int v, next;
} edge[M];
int last[N], tot;
int n, match = 0;
int matchx[N], matchy[N];
int visit[N];
int a[N], h[N];

int main() {
	int Test = 0, Case = 1;
	scanf ("%d", &Test);
	while (Test--) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
		for (int i = 1; i<= n; i++) scanf ("%d", &h[i]);
		sort (a + 1, a + 1 + n);
		sort (h + 1, h + 1 + n);
		//printf("%d %d\n", a[1], a[n]);
		int ans = 0;
		for (int i = n, j = n; i > 0; i--) {
			if (a[j] >= h[i]) {
				ans++;
				j--;
			}
		}
		printf ("Case %d: %d\n", Case++, ans);
	}
	return 0;
}
