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
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;
vector<LL>L;
LL eulerPhi(LL n) {
	LL res = n;
	for(int i = 1; i < L.SZ&&L[i]*L[i]<=n; i++)
		if(n % L[i] == 0) {
			res = res / L[i] * (L[i] - 1);
			for(; n % L[i] == 0; n /= L[i]);
		}
	if(n != 1) res = res / n * (n - 1);
	return res;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	LL i,j,k,m,n,u,v,T;
	while(~scanf("%I64d",&n)) {
		L.clear();
		for(i=1;i*i<=n;i++)if(n%i==0)L.PB(i),L.PB(n/i);
		sort(L.OP,L.ED);
		L.erase(unique(L.OP,L.ED),L.ED);
		LL ans=0;
		for(i=0;i<L.SZ;i++)
			ans+=1LL*eulerPhi(n/L[i])*L[i];
		printf("%I64d\n",ans);
	}
	return 0;
}
