#include<stdio.h>
int map[30][30];
int cho[30];
int m, n;
int flag = 0;
int res;
int t[30][30];
int min (int a, int b) {
  if (a > b) return b;
  return a;
}
int f (int x, int y) {
  t[x][y]  = 1 - t[x][y];
  t[x + 1][y] = 1 - t[x + 1][y];
  t[x - 1][y] = 1 - t[x - 1][y];
  t[x][y + 1] = 1 - t[x][y + 1];
  t[x][y - 1] = 1 - t[x][y - 1];
}
void o() {
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) printf ("%d", t[i][j]);
    printf ("\n");
  }
}
int check (int x) {		//!!!!
//	if(x<=18)return 1;
  int i, j;
  for (i = 1; i <= x; i++) for (j = 1; j <= m; j++) t[i][j] = map[i][j];
  for (i = 1; i <= x; i++) if (cho[i]) f (i, 1);
  for (j = 2; j < m; j++) for (i = 1; i <= x; i++) if (t[i][j - 1]) f (i, j);
  for (i = 1; m > 1 && i <= x; i++) {
    if (i == 1) {
      if (t[1][m - 1]) f (1, m);
    } else {
      if (t[i][m - 1] != t[i - 1][m]) {
        if (i < x) return 0;
        else return 1;
      } else {
        if (t[i - 1][m]) f (i, m);
      }
    }
  }
  return 1;
}
int dfs (int x) {
  if (x > n) {
    int i, j;
//		for(i=1;i<=n;i++)printf("%d ",cho[i]);printf("---cho\n");
    int ans = 0;
    int ths = 0;
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) t[i][j] = map[i][j];
    for (i = 1; i <= n; i++) if (cho[i]) f (i, 1), ans++;
    for (j = 2; j < m; j++) for (i = 1; i <= n; i++) if (t[i][j - 1]) f (i, j), ans++;
    for (i = 1; m > 1 && i <= n; i++) {
      if (i == 1) {
        if (t[1][m - 1]) f (1, m), ans++;
      } else {
        if (t[i][m - 1] != t[i - 1][m]) {ths = 1; break;}
        else {
          if (t[i - 1][m]) f (i, m), ans++;
        }
      }
    }
    if (!ths && !t[n][m]) {flag = 1; res = min (ans, res);}
  } else {
    int i;
    for (i = 0; i <= 1; i++) {
      cho[x] = i;
      if (1) dfs (x + 1);
    }
  }
}
int main() {
  int T;
  scanf ("%d", &T);
  while (T--) {
    flag = 0;
    scanf ("%d%*c", &n);
    m = n;
    res = m * n;
    int t;
    int i, j;
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) {
        char c;
        while ( (c = getchar()) == '\n');
        map[i][j] = (c == 'y') ? 0 : 1;
      }
    dfs (1);
    if (flag) printf ("%d\n", res);
    else printf ("inf\n");
  }
  return 0;
}
