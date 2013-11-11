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

typedef long long LL;
typedef pair<int, int> PII;
int L[2222][2222];
int R[2222][2222];
int a[2222], n, k;
map<int, int>S;
map<int, int>::iterator jter;
const int INF = 2000000010;
bool check (int d) {
  int i, j;
  for (i = 1; i <= n; i++) 
    for (j = 0; j <= min(i,k); j++)L[i][j]=INF;
  for (i = 1; i <= n; i++) 
    for (j = 0; j <= min(i,k); j++)R[i][j]=-INF;
  L[1][1]=-INF,R[1][1]=INF;
  L[1][0]=a[1]-d,R[1][0]=a[1]+d;
  for (i = 1; i < n; i++) {
    for (j = 0; j <= min(i,k); j++) {
			if(L[i][j]==INF)continue;
			if(R[i][j]==-INF)continue;	
			if(a[i+1]<=R[i][j]&&a[i+1]>=L[i][j]){
				L[i+1][j]=min(L[i+1][j],a[i+1]-d);
				R[i+1][j]=max(R[i+1][j],a[i+1]+d);
			}
			L[i+1][j+1]=min(L[i+1][j+1],L[i][j]-d);
			R[i+1][j+1]=max(R[i+1][j+1],R[i][j]+d);
    }
  }
//  cout<<d<<":  >>"<<endl;
//  for(i=1;i<=n;i++){
//		for(j=0;j<=min(i,k);j++)printf("(%d,%d) ",L[i][j],R[i][j]);
//		cout<<endl;
//  }
  for(i=0;i<=k;i++)if(L[n][i]<=R[n][i])return 1;
  return 0;
}
void solve() {
  while (~scanf ("%d%d", &n, &k)) {
    S.clear();
    int i;
    for (i = 1; i <= n; i++) scanf ("%d", &a[i]);
    int p = INF, q = -INF;
    for (i = 1; i <= n; i++) if (a[i] > q) q = a[i];
    for (i = 1; i <= n; i++) if (a[i] < p) p = a[i];
    for (i = 1; i <= n; i++) S[a[i]]++;
    int mx = 1;
    for (jter = S.OP; jter != S.ED; ++jter)
      mx = max (mx, (*jter).BB);
    if (n <= k + mx) {printf ("0\n"); continue;}
    int l = 0, r = q - p;
    int ans;
    while (l <= r) {
      if (r - l <= 1) {
        if (check (l)) ans = l;
        else ans = r;
        break;
      }
      int mid = (l + r) / 2;
      if (check (mid)) r = mid;
      else l = mid;
    }
    printf ("%d\n", ans);
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
/*
7 2 1 4 -5 -8 -11 16 19
*/
