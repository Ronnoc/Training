//Lquartz kybconnor
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define INF (1<<25)
#define N 100000
int a, b, c, d;
int n, m;
int gtob[N], btog[N];
int dg[N];
vector < pair < int, int > > dvec;

int main() {
	freopen ("kids.in", "r", stdin);
	freopen ("kids.out", "w", stdout);
	while (scanf ("%d%d%d%d", &a, &b, &c, &d) != EOF) {
		memset (gtob, 0, sizeof (gtob));
		memset (btog, 0, sizeof (btog));
		int x = INF, y = INF;
		for (int i = a + 1; i < 25000; i++) {
			if (i * b % c == 0) {
				if (i * a % 2 != 0) continue;
				if (i < c) continue;
				int j = i * b / c;
				if (j <= d) continue;
				if (j * d % 2 != 0) continue;
				if (j < b) continue;
				if (i + j < x + y) {
					x = i;
					y = j;
				}
			}
		}
		//printf("x = %d y = %d\n", x, y);
		m = x; n = y;
		printf ("%d %d\n", m, n);
		dvec.clear();
		for (int i = 1; i <= m; i++) {
			dvec.push_back (make_pair (-a, i));
		}
		//for(int i = 0; i < m; i++) printf("xx %d %d\n", dvec[i].first, dvec[i].second);
		x = 0;
		while (true) {
			sort (dvec.begin() + x, dvec.end());
			if (dvec[x].first == 0) break;
			for (int i = 0; i < -dvec[x].first; i++) {
				dvec[x + i + 1].first++;
				printf ("%d %d\n", dvec[x].second, dvec[x + i + 1].second);
			}
			x++;
		}
		vector<int>L,R;
		int i,j;
		for (i=1; i<=b; i++) for (j=1; j<=m; j++) L.push_back (j);
		for (j=m+1; j<=m+n; j++) for (i=1; i<=c; i++) R.push_back (j);
		for (i=0; i<L.size(); i++)
			printf ("%d %d\n",L[i],R[i]);
		dvec.clear();
		for (int i = 1; i <= n; i++) {
			dvec.push_back (make_pair (-d, m + i));
		}
		x = 0;
		while (true) {
			sort (dvec.begin() + x, dvec.end());
			if (dvec[x].first == 0) break;
			for (int i = 0; i < -dvec[x].first; i++) {
				dvec[x + i + 1].first++;
				printf ("%d %d\n", dvec[x].second, dvec[x + i + 1].second);
			}
			x++;
		}
	}
	return 0;
}
