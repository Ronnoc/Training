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

const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;
int a[4010],b[4010],c[4010],d[4010],n;
int l[16000010],nl;
void solve(){
	int i,j;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		nl=0;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)l[nl++]=a[i]+b[j];
		sort(l,l+nl);
		long long ans=0;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++){
			int tp=c[i]+d[j];
			tp*=-1;
			ans+=upper_bound(l,l+nl,tp)-lower_bound(l,l+nl,tp);
		}
		printf("%I64d\n",ans);
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
