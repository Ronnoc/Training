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
char s[5005][5005];
int n,m;
int nxt[5005][5005];
void solve() {
	while (scanf ("%d%d",&n,&m) !=EOF) {
		int i,j,k;
		for (i=0; i<n; i++) scanf ("%s",s[i]);
		int res=0;
		for (i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				if (s[i][j]=='0') {
					nxt[j][i]=j;
					k=j;
					while (--k>=0&&s[i][k]=='1') nxt[k][i]=j;
				} else nxt[j][i]=m;
			}
		}
		for (j=0; j<m; j++) {
			sort (nxt[j],nxt[j]+n);
			for (i=0; i<n; i++) res=max (res, (nxt[j][i]-j) * (n-i));
		}
		cout<<res<<endl;
	}
}
int main() {
//  while(1)
	solve();
	return 0;
}
