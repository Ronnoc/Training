//Lquartz
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, a, b;
int main() {
	while (scanf ("%d%d%d", &n, &a, &b) != EOF) {
		int m = min (n*a, n*b);
		for (int i = 1; i <= m; i++) {
			int t = i / a + i / b;
			if (t >= n) {
				int ans = i;
				if (i % a != 0) {
					ans = i / a * a + a;
					t = i / b + ans / a;
				} else if (i % b != 0) {
					ans = i / b * b + b;
					t = i / a + ans / b;
				}
				printf ("%d %d\n", t, ans);
				break;
			}
		}
		
	}
	return 0;
}
