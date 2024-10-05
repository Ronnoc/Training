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

const int MXN = 10000000+5;
int mu[MXN], p[MXN], pn;
bool flag[MXN];	//true为合数
//for(inv[1]=1,i=2;i<10000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;//MOD is prime
void sieve(int n) {
	pn = 0;
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			p[pn ++ ] = i;
			mu[i] = -1;						//phi[i]=i-1;
		}
		for (int j = 0; j < pn && i * p[j] <= n; j++) {
			flag[i * p [j]] = true;
			if (i % p[j] == 0) {
				mu[i * p[j]] = 0;			//phi[i * p[j]] = p[j] * phi[i];
				break;
			} else  mu[i * p[j]] = -mu[i];	//phi[i * p[j]] = (p[j] - 1) * phi[i];
		}
	}
	// flag[1]=0;
	// rep(i,2,n+1)flag[i]=flag[i-1]+(!flag[i]);
}

int ans[MXN];
void solve(){
  DRI(n);
  printf("%d\n",ans[n]);
}


int main()
{
  int i, j, k, _T = 1;
  sieve(10000000);
  flag[1]=1;
  // rep(i,1,100)cerr<<i<<" "<<!flag[i]<<endl;
  ans[0]=0;
  rep(i,1,10000000+1){
    ans[i]=ans[i-1];
    if(i==2){
      ans[i]++;
    }else if(i>2 && !flag[i] && !flag[i-2]){
      ans[i]++;
    }
  }
  ans[2]=0;
  ans[3]=0;
  ans[4]=0;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    printf("Case #%d: ", CA);
    solve();
  }
  fflush(stdout);
  return 0;
}