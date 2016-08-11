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
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
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
const int MXN = 100005;
int a[MXN],n;
struct SEG {
	int l, r;
	LL m,lazy,equal;
	//equal && !lazy = true
	SEG( int _l = 0, int _r = 0 ) {l = _l, r = _r;}
} SGT[MXN << 2 | 1];
void create( SEG &T, int t ) {
	T.m = a[t];
	T.lazy = 0;
	T.equal= a[t];
}
void fresh( SEG &T, SEG &L, SEG &R ) {
	T.equal=(L.equal&&L.equal==R.equal)?L.equal:0;
	T.m=L.m+R.m;
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
void update( int id, int l, int r, LL w ) {
	SEG &T = SGT[id];
	int mid = ( T.l + T.r ) / 2;
	//cout<<"u"<<id<<" "<<l<<"~"<<r<<"+"<<w<<"\n";
	if ( T.l == l && T.r == r ) {
		T.m+=w*(r-l+1);
		if(T.equal){
			T.equal+=w;
		}else {
			T.lazy+=w;
		}
		return;
	}
	if ( T.lazy ) {
		update( id << 1, T.l, mid, T.lazy );
		update( id << 1 | 1, mid + 1, T.r, T.lazy );
		T.lazy = 0;
	}
	if(T.equal){
		SGT[id << 1].equal=T.equal;
		SGT[id << 1].m=T.equal*(mid-T.l+1);
		SGT[id << 1].lazy=0;
		SGT[id << 1 | 1].equal=T.equal;
		SGT[id << 1 | 1].m=T.equal*(T.r-mid);
		SGT[id << 1 | 1].lazy=0;
		T.equal=0;
	}
	if ( r <= mid )update( id << 1, l, r, w );
	else if ( l > mid )update( id << 1 | 1, l, r, w );
	else {
		update( id << 1, l, mid, w );
		update( id << 1 | 1, mid + 1, r, w );
	}
	fresh( T, SGT[id << 1], SGT[id << 1 | 1] );
}
void play(int id,int l,int r){
	SEG &T = SGT[id];
	int mid = ( T.l + T.r ) / 2;
	if ( T.lazy ) {
		update( id << 1, T.l, mid, T.lazy );
		update( id << 1 | 1, mid + 1, T.r, T.lazy );
		T.lazy = 0;
	}
	if(T.l==l&&T.r==r){
		if(T.equal){
			T.equal=sqrt(T.equal);
			T.m=1LL*(r-l+1)*T.equal;
		}else {
			play(id<<1,l,mid);
			play(id<<1|1,mid+1,r);
			fresh( T, SGT[id << 1], SGT[id << 1 | 1] );
		}
		return;
	}
	if(T.equal){
		SGT[id << 1].equal=T.equal;
		SGT[id << 1].m=T.equal*(mid-T.l+1);
		SGT[id << 1].lazy=0;
		SGT[id << 1 | 1].equal=T.equal;
		SGT[id << 1 | 1].m=T.equal*(T.r-mid);
		SGT[id << 1 | 1].lazy=0;
	}
	if(r<=mid)play(id<<1,l,r);
	else if(l>mid)play(id<<1|1,l,r);
	else {
		play(id<<1,l,mid);
		play(id<<1|1,mid+1,r);
	}
	fresh( T, SGT[id << 1], SGT[id << 1 | 1] );
}
void query( int id, SEG &A ) {
	SEG &T = SGT[id];
	int mid = ( T.l + T.r ) / 2;
	if ( T.lazy ) {
		update( id << 1, T.l, mid, T.lazy );
		update( id << 1 | 1, mid + 1, T.r, T.lazy );
		T.lazy = 0;
	}
	if(T.equal){
		A.m=T.equal*(A.r-A.l+1);
		return;
	}
	if (T.l == A.l && T.r == A.r) {A = T; return;}
	if ( A.r <= mid )query( id << 1, A );
	else if ( A.l > mid )query( id << 1 | 1, A );
	else {
		SEG L( A.l, mid ), R( mid + 1, A.r );
		query( id << 1, L );
		query( id << 1 | 1, R );
		fresh( A, L, R );
	}
}
void dfs(int id){
	SEG &T = SGT[id];
	int mid = ( T.l + T.r ) / 2;
	cout<<"@"<<id<<" "<<T.l<<"~"<<T.r<<" m"<<T.m<<" z"<<T.lazy<<" e"<<T.equal<<"\n";
	if(T.l!=T.r){
		dfs(id<<1);
		dfs(id<<1|1);
	}
}
void solve(){
	RI(n);
	DRI(m);
	rep(i,1,n+1)RI(a[i]);
	build(1,1,n);
	//cout<<"@"<<0<<"\n";dfs(1);
	rep(t,0,m){
		int q,l,r,x;
		scanf("%d%d%d",&q,&l,&r);
		if(q==1){
			RI(x);
			update(1,l,r,x);
		}
		if(q==2){
			play(1,l,r);
		}
		if(q==3){
			SEG A(l,r);
			query(1,A);
			printf("%I64d\n",A.m);
		}
		//cout<<"@"<<t+1<<" "<<q<<" "<<l<<" "<<r<<"\n";dfs(1);
	}
}
/*
1
5 9
2 2 1 5 5
3 1 5
1 1 3 3
3 1 5
1 3 3 1
3 1 5
2 1 5
3 1 5
1 2 4 2
3 1 5
*/
int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}