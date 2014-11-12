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

typedef long long LL;
typedef pair<int, int> PII;

int p[4444],q[4444],n;
LL x[4444];
LL up[4444],down[4444];
LL dp[4444][2222];
LL w[4444];
int main(){
	while(scanf("%d",&n)!=EOF){
		int i,j;
		n*=2;
		int nn=n/2;
		for(i=1;i<=n;i++)scanf("%d.%d",&p[i],&q[i]);
		for(i=1;i<=n;i++)x[i]=p[i]*1000+q[i];
		for(i=1;i<=n;i++)down[i]=-q[i];
		for(i=1;i<=n;i++)up[i]=q[i]?1000-q[i]:0;
		for(i=1;i<=n;i++)w[i]=up[i]-down[i];
		LL tot=0,has1000=0;
		for(i=1;i<=n;i++)tot+=down[i];
		for(i=1;i<=n;i++)if(w[i]==1000)has1000++;
		LL ans=1e17+7;
		for(i=0;i<=n/2;i++){
			if(has1000<i)continue;
			if(n/2-i>n-has1000)continue;
			ans=min(ans,(LL)fabs(tot+i*1000));
		}
		printf("%I64d.%03I64d\n",ans/1000,ans%1000);
	}
	return 0;
}
