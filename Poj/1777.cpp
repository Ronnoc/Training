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

const int N = 1<<17|1;
LL p[N], pn;
bool flag[N];	//trueÎªºÏÊý
void init() {
	pn = 0;
	for(int i = 2; i < N; i++) {
		if(!flag[i])
			p[pn ++ ] = i;
		for(int j = 0; j < pn && i * p[j] < N; j++) {
			flag[i * p [j]] = true;
			if(i % p[j] == 0)
				break;
		}
	}
}
bool isprime(LL t){
	if(t<N)return !flag[t];
	for(int i=0;p[i]*p[i]<=t;i++)if(t%p[i]==0)return 0;
	return 1;
}
int ans[1<<10|1];
char dp[105][1<<10|1];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
	init();
	vector<LL>Q,R;
	for(LL t=4,c=2;t<=1LL<<31;t<<=1,c++)
		if(isprime(t-1))Q.PB(t-1),R.PB(c);
	for(i=0;i<1<<Q.SZ;i++){
		ans[i]=0;
		for(j=0;j<Q.SZ;j++)if(i>>j&1)ans[i]+=R[j];
	}
	while(~scanf("%d",&n)) {
		LL P[111];
		for(i=0; i<n; i++)scanf("%I64d",&P[i]);
		vector<int>L;
		for(i=0;i<n;i++){
			int mask=0;
			for(j=0;j<Q.SZ;j++)if(P[i]%Q[j]==0)P[i]/=Q[j],mask|=1<<j;
			if(P[i]==1)L.PB(mask);
		}
		for(i=0;i<=L.SZ;i++)for(j=0;j<1<<Q.SZ;j++)dp[i][j]=0;
		dp[0][0]=1;
		for(i=0;i<L.SZ;i++)for(j=0;j<1<<Q.SZ;j++)if(dp[i][j]){
			dp[i+1][j]=1;
			if(j&L[i])continue;
			dp[i+1][j|L[i]]=1;
		}
		int ret=0;
		for(i=0;i<1<<Q.SZ;i++)if(dp[L.SZ][i])cmax(ret,ans[i]);
		if(ret)printf("%d\n",ret);
		else printf("NO\n");
	}
	return 0;
}
