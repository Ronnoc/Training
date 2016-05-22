//Lquartz kybconnor
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
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int a[11111];
int vis[11111];
vector<PII>q[11111];
priority_queue<PII>pQ;
void solve() {
	freopen ("dwarf.in","r",stdin);
	freopen ("dwarf.out","w",stdout);
	int n,m;
	while (~scanf ("%d%d",&n,&m)) {
		int i;
		for (i=1; i<=n; i++) scanf ("%d",&a[i]);
		for (i=1; i<=n; i++) q[i].clear();
		for (i=1; i<=n; i++) vis[i]=0;
		for (i=1; i<=m; i++) {
			int w,x,y;
			scanf ("%d%d%d",&w,&x,&y);
			q[x].PB (MP (y,w));
			q[y].PB (MP (x,w));
		}
		for (i=1; i<=n; i++) pQ.push (MP (-a[i],i));
		PII tp;
		while (!pQ.empty()) {
			tp=pQ.top(); pQ.pop();
			int x=tp.BB;
			if (vis[x]) continue;
			vis[x]=1;
			for (i=0; i<q[x].SZ; i++) {
				int y=q[x][i].AA;
				int w=q[x][i].BB;
				if (a[w]>a[y]+a[x]) {
					a[w]=a[y]+a[x];
					pQ.push (MP (-a[w],w));
				}
			}
		}
		printf ("%d\n",a[1]);
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
