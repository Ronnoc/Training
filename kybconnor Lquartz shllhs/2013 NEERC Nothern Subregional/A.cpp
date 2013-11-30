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
	freopen ("arrange.in","r",stdin);
	freopen ("arrange.out","w",stdout);
	int n;
	while (scanf ("%d%*c",&n) !=EOF) {
		char s[111];
		int ocur[33];
		memset (ocur,0,sizeof ocur);
		int i;
		for (i=1; i<=n; i++) {
			gets (s);
			ocur[s[0]-'A']++;
		}
		int tot=0;
			for (i=0; i<26; i++) if (ocur[i]) tot++; else break;
		printf ("%d\n",tot);
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
/*
12
Arrangement of Contest
Ballot Analyzing Device
Correcting Curiosity
Dwarf Tower
Energy Tycoon
Flight Boarding Optimization
Garage
Heavy Chain Clusterization
Intellectual Property
J
Kids in a Friendly Class
Lonely Mountain
*/
