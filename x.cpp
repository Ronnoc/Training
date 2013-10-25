#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;

int x[222], y[222];
int g[222][222];
int G[222][222];
int oil[222];
int n, m;
int fa[222];
int getfa (int x) {
	return fa[x] == x ? x : fa[x] = getfa (fa[x]);
}
bool connect (vector<int>L) {
	int i, j;
	for (i = 0; i < L.size(); i++) fa[i] = i;
	vector<PII >T;
	for (i = 0; i < L.size(); i++) 
		for (j = i + 1; j < L.size(); j++) {
			int p = L[i], q = L[j];
			if (g[p][q] <= m) T.PB (MP (p, q));
		}
	int tot = 1;
	for (i = 0; i < T.size(); i++) {
		int p = getfa (T[i].AA);
		int q = getfa (T[i].BB);
		if (p != q) tot++, fa[p] = q;
	}
	if (tot == L.size()) return 1;
	cout<<"connect fail\n";
	
	return 0;
}
bool check() {
	vector<int>P, Q;
	int i, j;
		for (i = 1; i <= n; i++) 
			if (oil[i]) P.PB (i); else Q.PB (i);
	if (!connect (P)) return 0;
	for (i = 0; i < Q.size(); i++) {
		int can = 0;
		for (j = 0; j < P.size(); j++) 
			if (g[Q[i]][P[j]] * 2 <= m) can = 1;
		if (!can) return 0;
	}
	return 1;
}
int main() {
	while (~scanf ("%d%d", &n, &m)) {
		int i, j ,k;
		for (i = 1; i <= n; i++) scanf ("%d%d", &x[i], &y[i]);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				g[i][j] = sqrt ( SQ (x[i] - x[j]) + SQ (y[i] - y[j]))+1-1e-8;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				G[i][j]=g[i][j];
		for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)
			G[i][j]=min(G[i][j],G[i][k]+G[k][j])
		for (i = n; i >= 1; i--) oil[i] = 1;
		if (!check()) {
			printf ("-1\n");
			continue;
		}
		for (i = n; i >= 2; i--) {
			oil[i] = 0;
			if (!check()) oil[i] = 1;
		}
		for (i = 1; i <= n; i++){
			for (j = 1; j <= n; j++)printf("%3d",g[i][j]);
			printf("\n");
			}
		for(i=1;i<=n;i++)printf("%d",oil[i]);printf("\n");
		for (j = n; j && !oil[j]; j--);
		for (i = j; i >= 1; i--) printf ("%d", oil[i]);
		printf ("\n");
	}
	return 0;
}
