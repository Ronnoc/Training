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
#define NAME ""
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 20101009;
const int N = 10000005;
LL mu[N], p[N], pn;
bool flag[N];	//trueÎªºÏÊý
void init(int n) {
	pn = 0;
	mu[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!flag[i]) {
			p[pn ++ ] = i;
			mu[i] = 1-i;
		}
		for(int j = 0; j < pn && i * p[j] <= n; j++) {
			flag[i * p [j]] = true;
			if(i % p[j] == 0) {
				mu[i * p[j]] = mu[i];
				break;
			} else  mu[i * p[j]] = (1-p[j])*mu[i];
		}
	}
}
LL A[N],Z[N];
int main() {
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		if(n>m)swap(n,m);
		init(n);
		LL ans=0;
		Z[0]=0;
		for(int i=1;i<=m;i++){
			Z[i]=Z[i-1]+i;
			if(Z[i]>=MOD)Z[i]-=MOD;
		}
		for(LL x=1; x<=n; x++) {
			A[x]=Z[n/x]*Z[m/x];
			if(A[x]>=MOD)A[x]%=MOD;
			A[x]*=x;
			if(A[x]>=MOD)A[x]%=MOD;
			ans+=mu[x]*A[x];
			if(ans>=1LL<<61)ans%=MOD;
		}
		cout<<(ans%MOD+MOD)%MOD<<"\n";
	}
	return 0;
}
