//Lquartz
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define N 50100
#define M 100100
#define LEN 1001000
struct node {
	int u, v;
} edge[M];
char name[N][13];
char str[LEN];
int Test;
int n, m;

void addedge (int u, int v) {
	edge[m].u = u; edge[m].v = v; m++;
}

void doit (int L, int R, int F) {
	//printf("%d %d %d\n", L, R, F);
	int j = L, k = 0;
	for (int i = L; i < R;) {
		if (str[i] == '(') {
			int t = ++n;
			for (j = L, k = 0; j < i; j++, k++) {
				name[t][k] = str[j];
			}
			name[t][k] = '\0';
			addedge (F, t);
			int cnt = 0;
			for (j = i; j < R; j++) {
				if (str[j] == '(') cnt++;
				if (str[j] == ')') {
					cnt--;
					if (cnt == 0) break;
				}
			}
			doit (i + 1, j, t);
			i = j + 1;
			addedge (t, F);
			if (j + 2 < R)
				doit (j + 2, R, F);
			return;
		} else if (str[i] == ',') {
			int t = ++n;
			for (j = L, k = 0; j < i; j++, k++) {
				name[t][k] = str[j];
			}
			name[t][k] = '\0';
			addedge (F, t);
			addedge (t, F);
			doit (i + 1, R, F);
			return;
		} else {
			i++;
		}
	}
	int t = ++ n;
	for (j = L, k = 0; j < R; j++, k++) {
		name[t][k] = str[j];
	}
	name[t][k] = '\0';
	addedge (F, t);
	addedge (t, F);
}

int main() {
	scanf ("%d", &Test);
	while (Test--) {
		scanf ("%s", str);
		n = 0;
		m = 0;
		doit (0, strlen (str), 0);
		printf ("%d\n", n);
		for (int i = 1; i <= n; i++) {
			printf ("%s\n", name[i]);
		}
		for (int i = 1; i < m - 1; i++) {
			printf ("%d %d\n", edge[i].u, edge[i].v);
		}
		printf ("\n");
	}
	return 0;
}
