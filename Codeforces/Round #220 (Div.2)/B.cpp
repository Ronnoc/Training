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

typedef long long LL;
typedef pair<int, int> PII;
char s[111111];
int a[111111];
void solve() {
	while (~scanf ("%s",s)) {
		int len=strlen (s),i;
		for (i=0; i<len; i++) a[i]=s[i]-'0';
		LL res=1LL;
		for (i=0; i<len;) {
			int j=i+1;
			while (j<len&&a[j-1]+a[j]==9) j++;
			if ( (j-i) %2!=0) res*=1LL* (j-i+1) /2;
			i=j;
		}
		cout<<res<<endl;
	}
}
int main() {
	solve();
	return 0;
}
