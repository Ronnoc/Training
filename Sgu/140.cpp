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
LL extGcd(LL a, LL b, LL &x, LL &y) {
	LL ret = a;
	if(b) {
		ret = extGcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else x = 1, y = 0;
	return ret;
}
LL n,p,b;
LL x[111],g[111],t[111],a[111];
void solve(int n,LL Y){
	if(!n){
		x[0]=(Y/g[0])%p;
		return;
	}
	extGcd(g[n-1],a[n],t[n-1],x[n]);
	solve(n-1,t[n-1]*g[n-1]);
	for(int i=0;i<=n;i++)x[i]=x[i]*(Y/g[n])%p;
	for(int i=0;i<=n;i++)x[i]=(x[i]%p+p)%p;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	while(cin>>n>>p>>b){
		for(i=0;i<n;i++)cin>>a[i];
		for(i=0;i<n;i++)a[i]=(a[i]%p)?a[i]%p:p;
		b%=p;
		a[n]=p;
		g[0]=a[0];
		for(i=1;i<=n;i++)g[i]=__gcd(g[i-1],a[i]);
		if(b%g[n]){cout<<"NO\n";continue;}
		else cout<<"YES\n";
		solve(n,b);
		cout<<x[0];
		for(i=1;i<n;i++)cout<<" "<<x[i];
		cout<<endl;
	}
	return 0;
}
