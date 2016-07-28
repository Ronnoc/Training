#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b,d) for(int i=(a);i!=(b);i+=d)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}

const int MXN = 100005;
int p[MXN],n;
inline int LB(int x) {return x & (-x);}
struct BIT {
	LL _[MXN+5];
	int n;
	void init(int m) {
		n = m + 5;
		for (int i = 0; i <= n; i++)_[i] = 0;
	}
	LL query(int w) {
		LL ret = 0;
		for (w += 3; w > 0; w -= LB(w))ret += _[w];
		return ret;
	}
	void update(int w, LL d) {
		for (w += 3; w < n; w += LB(w))_[w] += d;
	}
	int find_Kth(int k) {		//UESTC_Dagon
		int idx = 0;
		for (int i = 20; i >= 0; i--) {
			idx |= 1 << i;
			if (idx <= n && _[idx] < k)k -= _[idx];
			else idx ^= 1 << i;
		}
		return idx - 2;
	}
} Y;
int re[MXN],tt[MXN];
void solve(){
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&p[i]);
	rep(i,1,n+1)tt[p[i]]=i;
	Y.init(n+1);
	repd(i,n,0,-1){
		re[p[i]]=i+Y.query(p[i]);
		Y.update(p[i],1);
	}
	rep(i,1,n+1){
		int le=min(tt[i],i);
		printf(" %d",re[i]-le);
	}
	printf("\n");
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		printf("Case #%d:",CA+1);
		solve();
	}
	return 0;
}