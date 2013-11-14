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
#define UNIQUE(x) x.erase(unique(x.OP,X.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int a[5010];
int w[5010];
int sl[5010][5010];
int sr[5010][5010];
int n;
void solve() {
	while (~scanf ("%d",&n)) {
		int i,j;
		for (i=0; i<n; i++) scanf ("%d",&a[i]);
		for (i=0; i<n; i++) w[a[i]]=i;
		for (i=0; i<n; i++) {
			for (j=1; j<=n; j++) sl[i][j]=sl[i][j-1]+(w[j-1]<i?1:0);
			for (j=1; j<=n; j++) sr[i][j]=sr[i][j-1]+(w[j-1]>i?1:0);
		}
		int tot=0;
		for (i=0; i<n; i++) tot+=sr[i][a[i]+1];
		int ans=tot,cnt=0;
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) {
				int now=tot+1;
				int lbi=i-sl[i][a[i]+1];
				int rsi=sr[i][a[i]+1];
				int lbj=j-sl[j][a[j]+1];
				int rsj=sr[j][a[j]+1];
				now=now-lbi-rsi-lbj-rsj;
				now=now+ (i-sl[i][a[j]+1]) +sr[i][a[j]]+ (j-sl[j][a[i]+1]) +sr[j][a[i]];
				if(now<ans)ans=now,cnt=1;
				else if(now==ans)cnt++;
			}
		printf ("%d %d\n",ans,cnt);
	}
}
int main() {
	solve();
	return 0;
}
