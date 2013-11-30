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

void solve() {
	freopen ("garage.in","r",stdin);
	freopen ("garage.out","w",stdout);
	long long W,H,w,h;
	while (scanf ("%I64d%I64d%I64d%I64d",&W,&H,&w,&h) !=EOF) {
		long long tp=2*max (W,H) +1;
		W*=tp; H*=tp; w*=tp; h*=tp;
		long long lie=0,hang=0;
		while (W>=w) {
			if (W<=2* (w-1) +w) {hang++,W=0; continue;}
			hang++,W-=w+w-1;
		}
		while (H>=h) {
			if (H<=2* (h-1) +h) {lie++,H=0; continue;}
			lie++,H-=h+h-1;
		}
		printf ("%I64d\n",lie*hang);
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
