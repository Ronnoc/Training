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
vector<int>L;
bool check (int t) {
	vector<int>l,r;
	int i;
	for (i=0; i<t; i++) l.PB (L[i]);
	for (i=L.SZ-t; i<L.SZ; i++) r.PB (L[i]);
	for (i=0; i<l.SZ; i++) if (r[i]<l[i]*2) return 0;
	return 1;
}
void solve() {
	int n;
	while (~scanf ("%d",&n)) {
		L.clear();
		int i;
		for (i=1; i<=n; i++) {
			int x;
			scanf ("%d",&x);
			L.PB (x);
		}
		sort (L.begin(),L.end());
		int ans,l=0,r=n/2;
		while (l<=r) {
			if (r-l<=1) {
				if (check (r)) ans=r;
				else ans=l;
				break;
			}
			int mid= (l+r) >>1;
			if (check (mid)) l=mid;
			else r=mid;
		}
		printf ("%d\n",n-ans);
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
/*
4
1 1 2 4
*/
