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
const double PI=acos( -1. );
const LL MOD = 1000000007;

LL dp[105][105];
LL call(int p,int q){
	LL &tp=dp[p][q];
	if(~tp)return tp;
	tp=0;
	if(q)tp+=call(p,q-1);
	for(int i=1;i<=p;i++)
		tp+=call(p-i,q+i-1);
	return tp%=MOD;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	scanf("%d",&_T);
	memset(dp,-1,sizeof dp);
	dp[0][0]=1;
	for(int CA=1;CA<=_T;CA++){
		int n,m;
		scanf("%d%d",&n,&m);
		int vis[111],a[111];
		memset(vis,0,sizeof vis);
		for(i=1;i<=m;i++)scanf("%d",&a[i]);
		vector<int>L;
		for(i=1;i<=m;i++){
			int id=lower_bound(L.OP,L.ED,-a[i])-L.OP;
			if(id==L.SZ)L.PB(-a[i]);
			else L[id]=-a[i];
			vis[a[i]]=1;
		}
		int fail=L.SZ>2;
		if(L.SZ==2)for(i=1;i<=-L[1];i++)if(!vis[i])fail=1;
		if(fail){
			printf("Case #%d: ",CA);
			printf("0\n");
			continue;
		}
		int tot=n-m;
		int p=0,q;
		if(!L.empty()){for(i=-L[0];i<=n;i++)if(!vis[i])p++;}
		else p=tot;
		q=tot-p;
		printf("Case #%d: ",CA);
		printf("%I64d\n",call(p,q));
	}
	return 0;
}
