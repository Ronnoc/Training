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
LL modPow(LL a,LL b,LL m=MOD) {
	LL ret=1;
	while(b) {
		if(b&1)ret=ret*a%m;
		a=a*a%m;
		b>>=1;
	}
	return ret;
}
LL extGcd(LL a, LL b, LL &x, LL &y) {
	LL ret = a;
	if(b) {
		ret = extGcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else x = 1, y = 0;
	return ret;
}
LL phi(LL a){
	LL ret=a;
	for(LL i=2;i*i<=a;i++)if(a%i==0){
		ret=ret/i*(i-1);
		while(a%i==0)a/=i;
	}
	if(a>1)ret=ret/a*(a-1);
	return ret;
}
map<LL,LL>dp[12];
LL solve(int p,LL mod) {
	if(mod==1)return 0;
	if(dp[p].find(mod)!=dp[p].end())return dp[p][mod];
	LL m1=mod,m2=1;
	while(m1%p==0)m1/=p,m2*=p;
	LL a1=modPow(p,solve(p,phi(m1)),m1),a2=0;
	LL b1,b2;
	extGcd(m2,m1,b2,b1);
	b2%=mod;
	b2*=a1;
	b2%=mod;
	b2*=m2;
	b2%=mod;
	b2+=mod;
	return dp[p][mod]=b2%mod;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int p,m,CA=0;
	while(~scanf("%d%d",&p,&m)) {
		if(CA++)printf("\n");
		LL sum=1;
		for(i=1;i<=m;i++)sum*=i;
		cout<<solve(p,sum)<<endl;
	}
	return 0;
}
