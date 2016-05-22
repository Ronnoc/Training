//lquartz kybconnor
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 11000
#define M 110000
struct point {
  int u, v;
};
int n, m, q;

point a, b;
vector < point > epoint, e;
vector < int > ok, ncnt;
int ans;
int used[10];
int go[6][6], come[6][6];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int rcnt[6];

int search (int x, int y, int d) {
  int res = 0;
  for (int i = 1; i < 10; i++) {
    int u = x + i * dx[d], v = y + i * dy[d];
    if (0 <= u && 0 <= v && u < n && v < m) {
      if (come[u][v] == 1) res++;
      else if (go[u][v] == 1) res++;
      if (res == 2) {
        if (come[u][v]) return 0;
        return 1;
      }
    } else break;
  }
  return 1;
}
/*
1 5 2
0 1 0 2
3 5 6
0 1 0 2
1 2 1 3
2 1 2 2
3 5 5
0 1 0 2
1 2
2 1 2 2
*/
bool check() {
  for (int t = 0; t < e.size(); t++) {
    int i = e[t].u, j = e[t].v;
    {
      for (int k = 0; k < 4; k++)
        if (search (i, j, k) == 0) {
          //if(used[0]==19&&used[2]==19&&used[1]==8)printf("%d %d %d\n",i,j,k);
          return false;
        }
    }
  }
  return 1;
}

void dfs (int depth, int now) {
//    if(used[0]==19){for(int i=0;i<depth;i++)printf("%d ",used[i]);printf("~%d\n",now);}
  if (depth == n) {
    //cout << "xx" << endl;
//        if(used[0]==19&&used[2]==19&&used[1]==8){for(int i=0;i<e.size();i++)printf("(%d,%d)",e[i].u,e[i].v);printf("~%d\n",now);}
    if (check())
      ans = max (ans, now);
    //cout << "xx" << ans << endl;
    return;
  }
  //if(now + 3*(n - depth) <= ans) return;
  
  for (int i = 0; i < ok.size(); i++) {
    int flag = 1;
    for (int j = 0; j < m; j++)
      if (ok[i] & (1 << j)) {
        if (go[depth][m - 1 - j]) flag = 0;
        if (rcnt[m - 1 - j]  > 2) flag = 0;
        if (!flag) break;
      }
    if (!flag) continue;
    used[depth] = ok[i];
    e.clear();
    for (int j = 0; j < m; j++)
      if (ok[i] & (1 << j)) {
        rcnt[m - 1 - j]++;
        come[depth][m - 1 - j] = 1;
        a.u = depth, a.v = m - 1 - j;
        e.push_back (a);
      }
    if (check()) dfs (depth + 1, now + ncnt[i]);
    for (int j = 0; j < m; j++)
      if (ok[i] & (1 << j)) {
        rcnt[m - 1 - j]--;
        come[depth][m - 1 - j] = 0;
//                e.pop_back();
      }
  }
}

int main() {
  while (scanf ("%d%d%d", &n, &m, &q) != EOF) {
    epoint.clear();
    memset (go, 0, sizeof (go));
    for (int i = 0; i < q; i++) {
      scanf ("%d%d", &a.u, &a.v);
      epoint.push_back (a);
      go[a.u][a.v] = 1;
    }
    ok.clear();
    ncnt.clear();
    
    for (int i = 0; i < (1 << m); i++) {
      int cnt = 0;
      for (int j = 0; j < m; j++) {
        if (i & (1 << j)) cnt++;
      }
      if (cnt <= 3) {
        ok.push_back (i);
        ncnt.push_back (cnt);
      }
    }
    ans = 0;
    e.clear();
    dfs (0, 0);
    printf ("%d\n", ans);
  }
  return 0;
}
