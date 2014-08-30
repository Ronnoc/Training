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

vector<PII>L;
int ans,n;
void dfs(int h,LL now){
	if(now>n)return;
	if(h==L.SZ){
		LL N=1LL*n*n;
		LL x=n+now;
		LL y=n+N/now;
		if(y<x)return;
		ans++;
	}
	else {
		for(int i=0;i<=L[h].BB;i++){
			dfs(h+1,now);
			now*=L[h].AA;
		}
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,m,u,v,T;
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		scanf("%d",&n);
		m=n;
		L.clear();
		for(i=2;i*i<=m;i++)if(m%i==0){
			int cnt=0;
			while(m%i==0)m/=i,cnt+=2;
			L.PB(MP(i,cnt));
		}
		if(m>1)L.PB(MP(m,2));
		ans=0;
		dfs(0,1);
		printf("Scenario #%d:\n",CA);
		printf("%d\n\n",ans);
	}
	return 0;
}

