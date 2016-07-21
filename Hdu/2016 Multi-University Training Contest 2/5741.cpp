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
const int MXN = 1000000+5;
inline int LB(int x) {return x & (-x);}
struct BIT {
	int _[MXN];
	int n;
	void init(int m) {
		n = m + 5;
		for (int i = 0; i <= n; i++)_[i] = 0;
	}
	int query(int w) {
		int ret = 0;
		for (w += 3; w > 0; w -= LB(w))ret += _[w];
		return ret;
	}
	void update(int w, int d) {
		for (w += 3; w < n; w += LB(w))_[w] += d;
	}
} Y;
int x[1005];
char s[500005];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	VI Z;
	vector<pair<PII,PII> >TL;
	rep(i,0,n)scanf("%d",&x[i]);
	rep(i,0,n){
		int w[2];
		w[0]=w[1]=0;
		rep(j,i+1,n){
			int d[2];
			d[0]=d[1]=0;
			d[i&1]+=x[i];
			d[j&1]+=x[j];
			Z.PB(w[0]);
			Z.PB(w[0]+d[0]+1);
			TL.PB(MP(MP(w[1],1),MP(w[0],w[0]+d[0]+1)));
			TL.PB(MP(MP(w[1]+d[1]+1,-1),MP(w[0],w[0]+d[0]+1)));
			w[j&1]+=x[j];
		}
	}
	sort(all(Z));
	Z.erase(unique(all(Z)),Z.ED);
	Y.init(sz(Z));
	rep(i,0,m){
		int q[2];
		scanf("%d%d",&q[0],&q[1]);
		TL.PB(MP(MP(q[1],2),MP(q[0],i)));
	}
	sort(all(TL));
	rep(i,0,sz(TL)){
		PII pr=TL[i].BB;
		int il=upper_bound(all(Z),pr.AA)-Z.OP-1;
		int ir=upper_bound(all(Z),pr.BB)-Z.OP-1;
		if(TL[i].AA.BB==1){
			Y.update(il,1);
			Y.update(ir,-1);
		}else if(TL[i].AA.BB==-1){
			Y.update(il,-1);
			Y.update(ir,1);
		}else {
			int w=Y.query(il);
			s[pr.BB]=w>0?'1':'0';
		}
	}
	rep(i,0,m)putchar(s[i]);
	printf("\n");
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}