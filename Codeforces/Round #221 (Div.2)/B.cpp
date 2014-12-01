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
int in[111],ou[111];
void solve() {
	int n,m;
	while (~scanf ("%d%d",&n,&m)) {
		memset (in,0,sizeof in);
		memset (ou,0,sizeof ou);
		int i;
		int x,y,d;
		for (i=0; i<m; i++) {
			scanf ("%d%d%d",&x,&y,&d);
			in[x]+=d;
			ou[y]+=d;
		}
		int res=0;
		for (i=1; i<=n; i++) res+=fabs (in[i]-ou[i]);
		printf ("%d\n",res/2);
	}
}
int main() {
//  while(1)
	solve();
	return 0;
}
