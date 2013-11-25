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
#define UNIQUE(x) x.erase(unique(x.OP,X.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int G,B,S;
int tot[33];
int c[33][12];
int sum[ (1<<21) +5][12];
int add[ (1<<21) +5];
int f[ (1<<21) +5];
int dp[ (1<<21) +5];
int dfs (int mk) {
//	cout<<mk<<" "<<who<<endl;
	if(dp[mk]!=-300)return dp[mk];
	int i,j;
	for (i=0; i<B; i++) {
		if (mk>>i&1) continue;
		int flag=0;
		for (j=1; j<=G; j++) if (sum[mk][j]+c[i][j]>=S) flag+=(sum[mk][j]+c[i][j])/S;
		if (flag) dp[mk]=max (dp[mk],dfs (mk|(1<<i)) +flag);
		else dp[mk]=max (dp[mk],f[(1<<B)-1]-f[mk|(1<<i)]-dfs (mk| (1<<i)));
	}
	return dp[mk];
}
void solve() {
//	cout<<sizeof (sum)<<endl;
	while (~scanf ("%d%d%d",&G,&B,&S)) {
		if(!G&&!B&&!S)break;
		int i,j,k;
		memset (c,0,sizeof c);
		for (i=0; i<B; i++) {
			scanf ("%d",&tot[i]);
			for (j=1; j<=tot[i]; j++) {
				int x;
				scanf ("%d",&x);
				c[i][x]++;
			}
		}
		for (i=0; i< (1<<B); i++) for (j=1; j<=G; j++) sum[i][j]=0;
		for (i=0; i< (1<<B); i++) f[i]=0;
		for (i=1; i< (1<<B); i++) {
			for (j=0; j<B; j++) if (i>>j&1) break;
			f[i]=f[i-(1<<j)];
			for (k=1; k<=G; k++){
				sum[i][k]= (sum[i- (1<<j)][k]+c[j][k]) %S;
				if(sum[i- (1<<j)][k]+c[j][k]>=S)f[i]+=(sum[i- (1<<j)][k]+c[j][k])/S;
			}
		}
		for(i=0;i<(1<<B);i++)dp[i]=-300;
		dp[(1<<B)-1]=0;
//		cout<<f[(1<<B)-1]<<endl;
		printf("%d\n",2*dfs (0)-f[(1<<B)-1]);
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
