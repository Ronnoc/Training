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
char s[1111111];
void solve() {
	while (~scanf ("%s",s)) {
		int len=strlen (s);
		int id=0;
		while (id<len&&s[id]!='^') id++;
		LL left=0;
		LL i;
		for (i=1; id-i>=0; i++) if (s[id-i]!='=') left+=i* (s[id-i]-'0');
		LL right=0;
		for (i=1; id+i<len; i++) if (s[id+i]!='=') right+=i* (s[id+i]-'0');
//		cout<<left<<" "<<right<<endl;
		if (left>right) cout<<"left\n";
		else if (right>left) cout<<"right\n";
		else cout<<"balance\n";
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
