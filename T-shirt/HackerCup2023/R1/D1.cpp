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


int A[1000007];

const int MXN = 1000007 + 10;
struct SEG {
	int l, r, lazy;
	LL v1, v2;
	int iv1, iv2;
	SEG( int _l = 0, int _r = 0 ) {l = _l, r = _r;}
} SGT[MXN << 2 | 1];
void create( SEG &T, int t ) {
	T.v1 = T.v2 = A[t];
	T.iv1 = T.iv2 = t;
	T.lazy = 0;
}
void fresh( SEG &T, SEG &L, SEG &R ) {
	if(L.v1 >= R.v1){
		T.v1 = L.v1;
		T.iv1 = L.iv1;
	}else {
		T.v1 = R.v1;
		T.iv1 = R.iv1;
	}

	LL lv2 = 1LL*L.v2*(MOD-1)%MOD;
	LL rv2 = 1LL*R.v2*(MOD-1)%MOD;
	if(lv2 >= rv2){
		T.v2 = L.v2;
		T.iv2 = L.iv2;
	}else {
		T.v2 = R.v2;
		T.iv2 = R.iv2;
	}
	T.lazy = 0;
}
void build( int id, int l, int r ) {
	SGT[id] = SEG( l, r );
	int mid = ( l + r ) / 2;
	if ( l != r ) {
		build( id * 2, l, mid );
		build( id * 2 + 1, mid + 1, r );
		fresh( SGT[id], SGT[id << 1], SGT[id << 1 | 1] );
	} else create( SGT[id], l );
}
void update( int id, int l, int r, int w ) {
	SEG &T = SGT[id];
	int mid = ( T.l + T.r ) / 2;
	if ( T.l == l && T.r == r ) {
		T.lazy^=1;
		T.v1 = T.v1 * (MOD - 1) % MOD;
		T.v2 = T.v2 * (MOD - 1) % MOD;
		swap(T.v1,T.v2);
		swap(T.iv1,T.iv2);
		return;
	}
	if ( T.lazy ) {
		update( id << 1, T.l, mid, T.lazy );
		update( id << 1 | 1, mid + 1, T.r, T.lazy );
		T.lazy = 0;
	}
	if ( r <= mid )update( id << 1, l, r, w );
	else if ( l > mid )update( id << 1 | 1, l, r, w );
	else {
		update( id << 1, l, mid, w );
		update( id << 1 | 1, mid + 1, r, w );
	}
	fresh( T, SGT[id << 1], SGT[id << 1 | 1] );
}
void query( int id, SEG &A ) {
	SEG &T = SGT[id];
	if ( T.lazy ) {
		int mid = (T.l + T.r) / 2;
		update( id << 1, T.l, mid, T.lazy );
		update( id << 1 | 1, mid + 1, T.r, T.lazy );
		T.lazy = 0;
	}
	if (T.l == A.l && T.r == A.r) {A = T; return;}
	int mid = ( T.l + T.r ) / 2;
	if ( A.r <= mid )query( id << 1, A );
	else if ( A.l > mid )query( id << 1 | 1, A );
	else {
		SEG L( A.l, mid ), R( mid + 1, A.r );
		query( id << 1, L );
		query( id << 1 | 1, R );
		fresh( A, L, R );
	}
}

void show( int id, int l, int r ) {
	int mid = ( l + r ) / 2;
	if ( l != r ) {
		show( id * 2, l, mid );
		show( id * 2 + 1, mid + 1, r );
	}
	SEG &T=SGT[id];
	if(l!=r)
	cout<<"show "<<T.l<<"~"<<T.r<<" v1:"<<T.v1<<"@"<<T.iv1<<" v2:"<<T.v2<<"@"<<T.iv2<<" lazy?"<<T.lazy<<endl;
	if(id==1)cout<<endl;
}

void solve(){
	DRI(N);
	rep(i,1,N+1)RI(A[i]);
	build(1, 1, N);
	DRI(Q);
	LL ans = 0;
	// show(1, 1, N);
	rep(_,0,Q){
		DRI(le);
		DRI(re);
		update(1, le, re, 1);
		// show(1, 1, N);
		SEG A(1, N);
		query(1, A);
		// show(1, 1, N);
		// cerr<<_<<"@ "<<A.iv1<<endl;
		ans+=A.iv1;
	}
	cout<<ans<<endl;
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