#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) \
  int(X);      \
  scanf("%d", &X)
#define rep(i, a, n) for (int i = (a); i < (int)(n); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
const LL MOD = 1000000007;
const long double PI = acos(-1.);
const long double eps = 1e-9;
LL modPow(LL a, LL b, LL MOD)
{
  LL ret = 1;
  for (; b; b >>= 1)
  {
    if (b & 1)
      ret = ret * a % MOD;
    a = a * a % MOD;
  }
  return ret;
}

LL extGcd (LL a, LL b, LL &x, LL &y) {
	LL ret = a;
	if (b) {
		ret = extGcd (b, a % b, y, x);
		y -= (a / b) * x;
	} else x = 1, y = 0;
	return ret;
}

LL modInv (LL a, LL m=MOD) {
	LL x, y;
	extGcd(a,m,x,y);
	return (m+x%m)%m;
}//if m为质数 [费马小定理]a^(m-1)=1 mod m ==>a^(m-2)是a关于m的逆元

const int MXN = 1000007;

int mu[MXN], p[MXN], pn;
bool flag[MXN];	//true为合数
LL FAC[MXN];
LL FACinv[MXN];
void init(int n) {
	pn = 0;
	mu[1] = 1;
	FAC[0] = 1;
	rep(i,1,n+1)
		FAC[i] = FAC[i-1]*i%MOD;
	rep(i,0,n+1)
		FACinv[i] = modInv(FAC[i]);
	for(int i = 2; i <= n; i++) {
		if(!flag[i]) {
			p[pn ++ ] = i;
			mu[i] = -1;						//phi[i]=i-1;
		}
		for(int j = 0; j < pn && i * p[j] <= n; j++) {
			flag[i * p [j]] = true;
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;			//phi[i * p[j]] = p[j] * phi[i];
				break;
			} else  mu[i * p[j]] = -mu[i];	//phi[i * p[j]] = (p[j] - 1) * phi[i];
		}
	}
}


int H[MXN];
int v[MXN];
int c[MXN];

LL f[MXN], g[MXN];


void solve(){
	DRI(N);
	DRI(K);
	DRI(D);
	rep(i,0,N)RI(H[i]);
	int mxh = 0;
	rep(i,0,N)cmax(mxh, H[i]);
	mxh++;
	rep(i,1,mxh)v[i]=0, c[i]=0, f[i]=0, g[i]=0;

	rep(i,0,N)v[H[i]]=1;

	rep(i,1,mxh){
		for(int j=i;j<mxh;j+=i)
			c[i]+=v[j];
	}

	rep(i,1,mxh){
		if(c[i]<K){
			f[i]=0;
			continue;
		}
		f[i] = 1LL;
		f[i] = f[i] * FAC[c[i]] %MOD;
		f[i] = f[i] * FACinv[K] % MOD;
		f[i] = f[i] * FACinv[c[i]-K] % MOD;
	}
	rep(i,1,mxh){
		for(int j=i;j<mxh;j+=i){
			g[i]+=mu[j/i]*f[j];
		}
	}
	LL ans = 0;
	rep(i,1,mxh)if(D%i==0)
		ans = ans + g[i];
	ans%=MOD;
	ans +=MOD;
	ans%=MOD;
	ans = ans * FAC[K] %MOD;
	cout<<ans<<endl;
}

int main()
{
  init(1000000);
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    printf("Case #%d: ", CA);
    solve();
  }
  fflush(stdout);
  return 0;
}