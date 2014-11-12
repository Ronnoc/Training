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
LL n,m;
LL q[111111];
LL w[111111];
LL sum[111111];
void solve() {
	while (~scanf ("%I64d%I64d",&n,&m)) {
		memset (w,0,sizeof w);
		LL i;
		for (i=1; i<=m; i++)
			scanf ("%I64d%I64d",&q[i],&w[i]);
		for (i=1; i<=m; i++) w[i]=-w[i];
		sort (w+1,w+1+m);
		for (i=1; i<=m; i++) w[i]=-w[i];
		sum[0]=0;
		for (i=1; i<=m; i++) sum[i]=sum[i-1]+w[i];
		if (n==1) {printf ("%I64d\n",w[1]); continue;}
		if (n==2) {printf ("%I64d\n",w[1]+w[2]); continue;}
		LL res=0;
		for (i=1; i<=m; i+=2) {
			LL has=i* (i-1) /2;
			if (has<=n-1) res=max (res,sum[i]);
			else break;
		}
		for (i=2; i<=m; i+=2) {
			LL need= i*i/2;
			if (need<=n) res=max (res,sum[i]);
		}
		printf ("%I64d\n\n",res);
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
