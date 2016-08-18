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
#define RI(X) scan_d(X)
#define DRI(X) int (X); scan_d(X)
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
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
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
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

const int MXN = 200005;
inline int LB(int x) {return x & (-x);}
struct BIT {
	LL _[MXN+10];
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
} Y;
int ans[MXN];
int x[MXN][2],y[MXN][2],n;
int z[MXN];
pair<PII,PII>TL[MXN<<1];
template <class T>inline bool scan_d(T &ret) {
	char c; 
	int sgn;
	if((c=getchar())==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}
inline void out(LL x) {
	if(x>9) out(x/10);
	putchar(x%10+'0');
}
void solve(){
	int ntl=0,iz=0;
	RI(n);
	rep(i,0,n){
		rep(j,0,2){RI(x[i][j]);RI(y[i][j]);}
		if(x[i][0]>x[i][1])swap(x[i][0],x[i][1]);
		if(y[i][0]>y[i][1])swap(y[i][0],y[i][1]);
		rep(j,0,2)z[iz++]=x[i][j];
	}
	sort(z,z+iz);
	iz=unique(z,z+iz)-z;
	rep(i,0,n){
		if(x[i][0]==x[i][1]){
			x[i][0]=lower_bound(z,z+iz,x[i][0])-z;
			TL[ntl++]=(MP(MP(y[i][0]-1,1),MP(-1,x[i][0])));
			TL[ntl++]=(MP(MP(y[i][1],1),MP(1,x[i][0])));
		}
		if(y[i][0]==y[i][1]){
			rep(j,0,2)x[i][j]=lower_bound(z,z+iz,x[i][j])-z;
			TL[ntl++]=(MP(MP(y[i][0],0),MP(x[i][0],x[i][1])));
		}
	}
	sort(TL,TL+ntl);
	Y.init(iz+2);
	LL ans=0;
	rep(t,0,ntl){
		if(TL[t].AA.BB){
			ans+=TL[t].BB.AA*Y.query(TL[t].BB.BB);
		}else {
			Y.update(TL[t].BB.AA,1);
			Y.update(TL[t].BB.BB+1,-1);
		}
	}
	out(ans);puts("");
}

int main(){
	int _T=1;
	RI(_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}