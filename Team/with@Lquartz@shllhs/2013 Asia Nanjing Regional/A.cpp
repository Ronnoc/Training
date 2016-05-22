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
	int n;
	while (~scanf ("%d",&n)) {
		int i;
		char s[11];
		int x;
		int totx=0;
		int cs=0;
		for (i=1; i<=n; i++) {
			scanf ("%d %s",&x,s);
			if (s[0]=='P'||s[0]=='N')
				continue;
			totx+=x*10;
			int ss=0;
			if (strcmp (s,"F") ==0) ss=0;
			if (strcmp (s,"D-") ==0) ss=10;
			if (strcmp (s,"D") ==0) ss=13;
			if (strcmp (s,"C-") ==0) ss=17;
			if (strcmp (s,"C") ==0) ss=20;
			if (strcmp (s,"C+") ==0) ss=23;
			if (strcmp (s,"B-") ==0) ss=27;
			if (strcmp (s,"B") ==0) ss=30;
			if (strcmp (s,"B+") ==0) ss=33;
			if (strcmp (s,"A-") ==0) ss=37;
			if (strcmp (s,"A") ==0) ss=40;
			cs+=x*ss;
		}
		if (totx) printf ("%.2lf\n",1.0*cs/totx);
		else printf ("0.00\n");
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
