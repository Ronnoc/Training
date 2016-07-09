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
const int MXN = 600005+10;
inline int LB(int x) {return x & (-x);}
struct BIT {
	LL _[MXN];
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
LL inv[MXN];
LL A[MXN];
int l[MXN],r[MXN];
void solve(){
	int i;
	for(inv[0]=inv[1]=1,i=2;i<200005;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;//MOD is prime
	rep(i,1,200005)
		inv[i]=inv[i]*inv[i-1]%MOD;
	A[0]=1;
	rep(i,1,200005)A[i]=A[i-1]*i%MOD;
	int n,k;
	scanf("%d%d",&n,&k);
	VI Z;
	rep(i,0,n){
		scanf("%d%d",&l[i],&r[i]);
		Z.PB(l[i]);
		Z.PB(r[i]+1);
	}
	sort(all(Z));
	Z.erase(unique(all(Z)),Z.ED);
	Y.init(Z.SZ+5);
	rep(i,0,n){
		int il=lower_bound(all(Z),l[i])-Z.OP;
		int ir=lower_bound(all(Z),r[i]+1)-Z.OP;
		Y.update(il,1);
		Y.update(ir,-1);
	}
	LL ans=0;
	rep(i,0,Z.SZ-1){
		int len=Z[i+1]-Z[i];
		int m=Y.query(i);
		if(m>=k)
			ans=(ans+A[m]*inv[k]%MOD*inv[m-k]%MOD*len%MOD)%MOD;
	}
	cout<<ans%MOD<<"\n";
}

int main(){
	int _T=1;
	rep(CA,0,_T){
		solve();
	}
	return 0;
}