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

//FFT
//> 验题: NEERC 2013 Eastern subregional G

const int MXN = 1 << 20;
double ax[MXN], ay[MXN];
double bx[MXN], by[MXN];
double ansx[MXN], ansy[MXN];
int revv(int x, int mask) {
	int ret = 0;
	for (int i = 0; i < mask; i++) {
		ret <<= 1;
		ret |= x & 1;
		x >>= 1;
	}
	return ret;
}
void fft(double * rl, double * ig, int n, bool sign) {
	int d = 0;
	while ((1 << d) < n) ++d;
	for (int i = 0; i < n; i++) {
		int j = revv(i, d);
		if (i < j) swap(rl[i], rl[j]), swap(ig[i], ig[j]);
	}
	for (int m = 2; m <= n; m <<= 1) {
		int mh = m >> 1;
		double _wr = cos(2 * PI / m), _wi = sin(2 * PI / m);
		if (sign) _wi *= -1.0;
		for (int i = 0; i < n; i += m) {
			double wr = 1, wi = 0;
			for (int j = i; j < mh + i; j++) {
				int k = j + mh;
				double er = rl[k] * wr - ig[k] * wi;
				double ei = rl[k] * wi + ig[k] * wr;
				double cr = rl[j], ci = ig[j];
				rl[j] += er, ig[j] += ei;
				rl[k] = cr - er, ig[k] = ci - ei;
				double qr = wr * _wr - wi * _wi;
				double qi = wr * _wi + wi * _wr;
				wr = qr, wi = qi;
			}
		}
	}
	if (sign) for (int i = 0; i < n; i++)
			rl[i] /= n, ig[i] /= n;
}
int fftmultiply(int *a, int la, int *b, int lb, LL *ans) {
	int lans = max(la, lb), ln = 0, i;
	while ((1 << ln) < lans) ++ln;
	lans = 2 << ln;
	for (i = 0; i < lans; i++)
		ax[i] = i < la ? a[i] : 0, ay[i] = 0;
	fft(ax, ay, lans, 0);
	for (i = 0; i < lans; i++)
		bx[i] = i < lb ? b[i] : 0, by[i] = 0;
	fft(bx, by, lans, 0);
	for (i = 0; i < lans; i++) {
		ansx[i] = ax[i] * bx[i] - ay[i] * by[i];
		ansy[i] = ax[i] * by[i] + ay[i] * bx[i];
	}
	fft(ansx, ansy, lans, 1);
	for (i = 0; i < lans; i++)
		ans[i] = ansx[i] + 0.5;
	return lans;
}
int a[100005];
int f[100005<<2];
int p[100005<<2];
int q[100005<<2];
LL r[100005<<2];
void solve(int le,int re){
	if(re<=le+1)return;
	int me=(le+re)/2;
	solve(le,me);
	rep(i,0,re-le)p[i]=a[i];
	rep(i,le,me)q[i-le]=f[i];
	fftmultiply(p,re-le,q,me-le,r);
	rep(i,me,re)f[i]=(f[i]+r[i-le])%313;
	solve(me,re);
}
void solve(){
	int n;
	while(~scanf("%d",&n)&&n){
		a[0]=0;
		rep(i,1,n+1)scanf("%d",&a[i]);
		rep(i,1,n+1)a[i]%=313;
		memset(f,0,sizeof f);
		f[0]=1;
		solve(0,n+1);
		printf("%d\n",f[n]%313);
	}
}

int main(){
	int _T=1;
	rep(CA,0,_T){
		solve();
	}
	return 0;
}