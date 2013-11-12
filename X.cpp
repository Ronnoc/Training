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
LL dp[10][(1<<9)+1];
LL mp[10][(1<<9)+1][(1<<9)+1];
int dfs(int h,int p,int q){
	LL &tp=mp[h][p][q];
	if(tp!=-1)return tp;
	if(h==0)return tp=0;
	tp=0;
	if(!(p&1)&&(q&1))tp+=dfs(h-1,p>>1,q>>1);
	if(h>=2&&(p%4==0)&&(q&1))tp+=dfs(h-1,(p|3)>>1,q>>1);
	if(h>=2&&(p%4==0))tp+=dfs(h,p|3,q);
	if(h>=2&&)
}
void solve() {
//	cout<<sizeof mp+sizeof dp+sizeof G<<endl;
	int i,j,k;
	int n,m;
	memset(G,-1,sizeof G);
	while (~scanf ("%d%d",&n,&m)) {
		memset (dp,0,sizeof dp);
		dp[0][0]=1;
		for (i=0; i<n; i++) for (j=0; j< (1<<m); j++) 
			for(k=0;k<(1<<m);k++)dp[i+1][k]+=dp[i][j]*dfs(m,j,k);
		cout<<dp[n][ (1<<m)-1]<<endl;     
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
