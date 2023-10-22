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

int A[2000005];
int B[2000005];

int C[16000015];
int mp[16000015];

void manacher_odd(int *s, int bn,int *p) {
	int n = bn - 2;
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
}

void solve(){
	DRI(n);
	rep(i,0,n)RI(A[i]);
	rep(i,0,n)RI(B[i]);
	int ic = 0;
	C[ic++]=-2;
	rep(i,0,n){C[ic++]=-1;C[ic++]=A[i];}
	rep(i,0,n){C[ic++]=-1;C[ic++]=B[i];}
	rep(i,0,n){C[ic++]=-1;C[ic++]=A[i];}
	rep(i,0,n){C[ic++]=-1;C[ic++]=B[i];}
	C[ic++]=-1;
	C[ic++]=-3;
	rep(i,0,ic)mp[i]=0;
	manacher_odd(C, ic, mp);
	// rep(i,0,ic)cout<<i<<" "<<C[i]<<" "<<mp[i]<<endl;cout<<endl;

	int half = n/2;
	int c1 = 0, c2 = 0;
	rep(i, 0, half){
		int il = i;
		int ir = n -1 - i;
		if(A[il]<B[il])c1++;
		if(A[ir]>B[ir])c2++;
	}
	int p = 0;
	int q = half;
	int r = n - 1 - (half - 1);
	int s =  2 * n + 1;
	// - p + q
	// - r + p
	rep(i,0,2*n){
		// cout<<"!"<<s<<" "<<mp[s]<<endl;
		if(c1 == half && c2 == half && mp[s]>2*n){
			printf("%d\n",i);
			return;
		}
		if(A[p]<B[p])c1--;
		if(A[r]>B[r])c2--;
		swap(A[p],B[p]);
		if(A[q]<B[q])c1++;
		if(A[p]>B[p])c2++;
		p = ( p + 1 ) % n;
		q = ( q + 1 ) % n;
		r = ( r + 1 ) % n;
		s = s + 2;
		// cout<<c1<<","<<c2<<endl;
	}
	printf("-1\n");
}

int main()
{
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