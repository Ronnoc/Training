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
char s[111111];
void solve() {
	freopen ("energy.in","r",stdin);
	freopen ("energy.out","w",stdout);
	int n;
	while (~scanf ("%d",&n)) {
		scanf ("%s",s);
		int i,j,len=strlen (s);
		int l[5];
		l[0]=0;
		l[1]=0;
		l[2]=0;
		long long res=0;
		for (i=0; i<len; i++) {
			int now=s[i]-'0';
			if (l[0]+now<=n) l[0]+=now,l[now]++;
			else if (now==1) {
				if (l[2]>0)
				{l[2]--; l[1]++; l[0]--;}
			}
			res+=l[1]+l[2];
		}
		printf ("%I64d\n",res);
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
