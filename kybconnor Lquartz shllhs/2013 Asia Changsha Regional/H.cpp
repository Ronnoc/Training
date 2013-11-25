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
int _R,_r,_H,_F,_S;
double R,r,H,F,S;
const long double PI = acos (-1);
const long double eps= 1e-8;
void solve() {
	while (scanf ("%d%d%d%d%d",&_R,&_r,&_H,&_F,&_S) !=EOF) {
		R=_R,r=_r,H=_H,F=_F,S=_S;
		long double d= (R-r) / (_F);
		long double res=0;
		for (int i=0; i<_F; i++) {
			long double rr=r+d*i;
			int n=PI/ (atan2 (S*F,2*rr*H)) +eps;
			cout << n << endl;
			res+=2*rr*n*tan (PI/n);
		}
		res*=H/F;
		printf ("%.3lf\n",double (res));
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
