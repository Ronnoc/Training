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
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define NAME ""
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;

LL a[1005];
int main() {
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--) {
		int n;
		scanf("%d",&n);
		for(i=0; i<n; i++)scanf("%I64d",&a[i]);
		int s=0;
		for(i=0; i<64; i++) {
			for(j=s; j<n; j++)if(a[j]>>i&1LL)break;
			if(j<n) {
				swap(a[j],a[s]);
				for(k=s+1; k<n; k++)if(a[k]>>i&1LL)a[k]^=a[s];
				s++;
			}
		}
		int got=0;
		for(i=0; i<n; i++)if(a[i]==0LL)got=1;
		if(got)puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
100
3
3 1 2
*/
