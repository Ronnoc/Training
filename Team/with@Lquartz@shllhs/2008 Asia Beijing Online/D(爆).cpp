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
	int x[10];
	int i,T;
	while (cin>>T) {
		for (i=0; i<T; i++) x[i]=1<<i;
		int tot=0;
		do {
			int j;
			for (j=0; j<1<<T; j++) {
				int now=0,flag=1;
				for (i=0; i<T; i++) {
					if (j>>i&1) now+=x[i];
					else now-=x[i];
					if (now<0) flag=0;
				}
				tot+=flag;
			}
		} while (next_permutation (x,x+T));
		int fm=1;
		for (i=1; i<=T; i++) fm*=i;
		fm*=1<<T;
		cout<<tot<<"/"<<fm<<endl;
//		LL gcd=__gcd(tot,fm);
//		cout<<tot/gcd<<"//"<<fm/gcd<<endl;
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
