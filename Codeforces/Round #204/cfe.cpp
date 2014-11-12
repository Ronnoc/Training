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

typedef long long LL;
typedef pair<int, int> PII;

int ldp[2222], rdp[2222];
int used[2222], fuhao[2222];
int p[2222], n;
vector<PII>ask;
vector<PII>ksa;
vector<int>Z;
vector<int>::iterator iter;
void play() {
  int i;
  Z.clear();
  for (i = ask.size() - 1; i >= 0; i--) {
    iter = upper_bound (Z.begin(), Z.end(), -ask[i].AA);
    if (iter == Z.end()) {Z.PB (-ask[i].AA); rdp[i] = Z.size();}
    else {*iter = -ask[i].AA; rdp[i] = (int) (iter - Z.begin()) + 1;}
  }
  Z.clear();
  for (i = 0; i < ask.size(); i++) {
    iter = upper_bound (Z.begin(), Z.end(), -ask[i].AA);
    if (iter == Z.end()) {Z.PB (-ask[i].AA); ldp[i] = Z.size();}
    else {*iter = -ask[i].AA; ldp[i] = (int) (iter - Z.begin()) + 1;}
  }
//	for(i=0;i<ask.size();i++)cout<<ask[i].AA<<" ";cout<<endl;
//	for(i=0;i<ask.size();i++)cout<<rdp[i]<<" ";cout<<endl;
//	for(i=0;i<ask.size();i++)cout<<ldp[i]<<" ";cout<<endl;
  int mx = -1, Pmx;
  for (i = 0; i < ask.size(); i++) if (ldp[i] + rdp[i] > mx) mx = ldp[i] + rdp[i], Pmx = i;
  used[ask[Pmx].BB] = 1;
//	fuhao[ask[Pmx].BB]=1;
  int pmx = Pmx;
  for (i = pmx + 1; i < ask.size(); i++) if ( (rdp[i] == rdp[pmx] - 1) && (ask[i].AA >= ask[pmx].AA))
      used[ask[i].BB] = 1, pmx = i;
  pmx = Pmx;
  for (i = pmx - 1; i >= 0; i--) if ( (ldp[i] == ldp[pmx] - 1) && (ask[i].AA >= ask[pmx].AA))
      used[ask[i].BB] = 1, pmx = i, fuhao[ask[i].BB] = 1;
  ask.clear();
  for (i = 1; i <= n; i++) if (!used[i]) ask.PB (MP (p[i], i));
}
int main() {
	freopen("ran.txt","r",stdin);
//	freopen("try.txt","w",stdout);
  while (~scanf ("%d", &n)) {
    int i, j;
    memset (used, 0, sizeof used);
    memset (fuhao, 0, sizeof fuhao);
    for (i = 1; i <= n; i++) scanf ("%d", &p[i]);
    for (i = 1; i <= n; i++) if (p[i] < 0) p[i] = -p[i];
    for (i = 1; i <= n; i++) ask.PB (MP (p[i], i));
    while (!ask.empty()) play();
    for (i = 1; i <= n; i++) if (fuhao[i]) p[i] = -p[i];
//		for(i=1;i<=n;i++)cout<<p[i]<<" ";cout<<endl;
    for (int pp = 1; pp <=5; pp++) {
      for (i = 1; i <= n; i++) {
        int notchange = 0;
        for (j = 1; j < i; j++) if (p[j] > p[i]) notchange++;
        for (j = i + 1; j <= n; j++) if (p[j] < p[i]) notchange++;
        int change = 0;
        for (j = 1; j < i; j++) if (p[j] > -p[i]) change++;
        for (j = i + 1; j <= n; j++) if (p[j] < -p[i]) change++;
        if (change < notchange) p[i] = -p[i];
      }
      for (i = n; i >= 1; i--) {
        int notchange = 0;
        for (j = 1; j < i; j++) if (p[j] > p[i]) notchange++;
        for (j = i + 1; j <= n; j++) if (p[j] < p[i]) notchange++;
        int change = 0;
        for (j = 1; j < i; j++) if (p[j] > -p[i]) change++;
        for (j = i + 1; j <= n; j++) if (p[j] < -p[i]) change++;
        if (change < notchange) p[i] = -p[i];
      }
    }
    int tot = 0;
    for (i = 1; i <= n; i++) for (j = i + 1; j <= n; j++) if (p[i] > p[j]) tot++;
    printf ("%d\n", tot);
  }
  return 0;
}
