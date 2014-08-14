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
#include <cassert>
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
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const LL MOD = 1000000007;
int main() {
	int i,j;
	int n0,CA=0;
	while ( ~scanf( "%d",&n0 )&&n0 ) {
		LL n1=3LL*n0;
		LL n2=( n1+1 )/2;
		LL n3=3*n2;
		int n4=n3/9;
		CA++;
		printf("%d. ",CA);
		if(n0&1)printf("odd");
		else printf("even");
		printf(" %d\n",n4);
	}
	return 0;
}
