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
int tx[111111];
int ty[111111];
int tz[111111];
void solve() {
	while (~scanf ("%s",s)) {
		int m;
		scanf ("%d",&m);
		memset (tx,0,sizeof tx);
		memset (ty,0,sizeof ty);
		memset (tz,0,sizeof tz);
		int len=strlen (s);
		int i;
		for (i=0; i<len; i++) {
			tx[i+1]=tx[i];
			ty[i+1]=ty[i];
			tz[i+1]=tz[i];
			if (s[i]=='x') tx[i+1]++;
			else if (s[i]=='y') ty[i+1]++;
			else if (s[i]=='z') tz[i+1]++;
		}
		for (i=1; i<=m; i++) {
			int l,r;
			scanf ("%d%d",&l,&r);
			if (r<=l+1) {printf ("YES\n"); continue;}
			int x=tx[r]-tx[l-1];
			int y=ty[r]-ty[l-1];
			int z=tz[r]-tz[l-1];
			int mx=max (x,y);
			mx=max (mx,z);
			int mn=min (x,y);
			mn=min (mn,z);
			if (mx-mn<=1) printf ("YES\n");
			else printf ("NO\n");
		}
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
