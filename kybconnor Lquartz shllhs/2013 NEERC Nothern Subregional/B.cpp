//kybconnor
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
char WA[]="Invalid";
char s[11][111];
int tot[11];
char piao[111];
void solve() {
	freopen ("bad.in","r",stdin);
	freopen ("bad.out","w",stdout);
	int n,m;
	while (~scanf ("%d%d",&n,&m)) {
		int i,j,k;
		for (i=0; i<n; i++) scanf ("%s",s[i]);
		int wa=0;
		memset (tot,0,sizeof tot);
		for (i=0; i<m; i++) {
			scanf ("%s",piao);
			vector<int>has;
			for (j=0; j<n; j++) if (piao[j]=='X')
					has.PB (j);
			if (has.empty() ||has.SZ>1)
				wa++;
			else tot[has[0]]++;
		}
		vector<int>L;
		for (i=0; i<n; i++) L.PB (-tot[i]);
		SORT (L);
		UNIQUE (L);
		for (j=0; j<L.SZ; j++)
			for (i=0; i<n; i++) if (tot[i]==-L[j])
					printf ("%s %.2lf%%\n",s[i],100.0*tot[i]/m);
		printf ("%s %.2lf%%\n",WA,100.0*wa/m);
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
