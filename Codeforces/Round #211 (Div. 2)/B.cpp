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
#define UNIQUE(x) x.erase(unique(x.OP,X.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;

int a[2222222],n,k;
LL sum[2222222];
void solve(){
	while(~scanf("%d%d",&n,&k)){
		int i;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		sum[0]=0;
		for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		LL ans=sum[k],id=1;
		for(i=k+1;i<=n;i++)if(sum[i]-sum[i-k]<ans)
			ans=sum[i]-sum[i-k],id=i-k+1;
		printf("%d\n",id);
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
