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
const int MXN = 50005;
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
int x[MXN];
int small[MXN];
int big[MXN];
void solve(){
	int n;
	while(~scanf("%d",&n)){
		rep(i,0,n)scanf("%d",&x[i]);
		VI L;
		rep(i,0,n)L.PB(x[i]);
		sort(all(L));
		rep(i,0,n){
			small[i]=lower_bound(all(L),x[i])-L.OP;//<
			big[i]=upper_bound(all(L),x[i])-L.OP;//<=
		}
		L.erase(unique(all(L)),L.ED);
		LL inc=0,des=0;
		rep(i,0,n)x[i]=lower_bound(all(L),x[i])-L.OP;
		Y.init(sz(L));
		LL ans=0;
		rep(i,0,n){
			int lessleft=Y.query(x[i]-1);
			int moreleft=i-Y.query(x[i]);
			inc+=lessleft;
			des+=moreleft;
			int lessright=small[i]-lessleft;
			int moreright=(n-big[i])-moreleft;
			ans-=1LL*lessleft*lessright;
			ans-=1LL*moreleft*moreright;
			ans-=1LL*moreright*lessright;
			ans-=1LL*moreleft*lessleft;
			Y.update(x[i],1);
			//cout<<i<<" "<<lessleft<<"*"<<lessright<<" "<<moreleft<<"*"<<moreright<<"\n";
		}
		ans+=inc*des;
		//cout<<inc<<" "<<des<<"\n";
		cout<<ans<<"\n";
	}
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}