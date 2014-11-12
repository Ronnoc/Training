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
const double eps=1e-16;
const double PI=acos(-1.);
const LL MOD = 1000000007;

long double cb[305][305];
long double dp[305][305];
int w[305];
int v[305];
int vis[305][305];
vector<int>L;
int sum[305];
long double solve(int id,int m) {
	if(m>sum[id])return 0;
	if(m==sum[id])return 1;
	if(vis[id][m])return dp[id][m];
	vis[id][m]=1;
	long double &tp=dp[id][m];
	tp=0;
	for(int i=max(1,m-sum[id+1]); i<=L[id]&&i<=m; i++)
		tp+=solve(id+1,m-i)*exp(cb[L[id]][i]+cb[sum[id+1]][m-i]-cb[sum[id]][m]);
	return tp;
}
long double lg[305];
int main() {
#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	for(i=0;i<=300;i++)lg[i]=log(i);
	for(i=0; i<=300; i++)
		for(j=0; j<=300; j++)
			cb[i][j]=0;
	for(i=0; i<=300; i++) {
		cb[i][0]=0;
		for(j=1; j<=i; j++)
			cb[i][j]=cb[i][j-1]+lg[i-j+1]-lg[j];
	}
	scanf("%d",&_T);
	while(_T--) {
		int n,m;
		scanf("%d%d",&n,&m);
		for(i=1; i<=n; i++)scanf("%d",&w[i]);
		memset(v,0,sizeof v);
		L.clear();
		for(i=1; i<=n; i++)if(!v[i]) {
				int z=1;
				v[i]=1;
				for(j=w[i]; j!=i; j=w[j],z++)v[j]=1;
				L.PB(z);
			}
		sort(L.OP,L.ED);
		memset(sum,0,sizeof sum);
		for(i=L.SZ-1; i>=0; i--)
			sum[i]=sum[i+1]+L[i];
		memset(vis,0,sizeof vis);
		printf("%.9f\n",(double)(solve(0,m)+eps));
	}
	return 0;
}
