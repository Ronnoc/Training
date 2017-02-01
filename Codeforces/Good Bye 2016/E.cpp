//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int MXN = 200000 + 10;
char s[MXN];
int w[MXN];
void update(int &z,int u){
	if(~z)cmin(z,u);
	else z=u;
}
struct Value{
	int g[5][5];
	Value(){memset(g,-1,sizeof g);}
	void init(int t=-1){
		memset(g,-1,sizeof g);
		if(~t){
			g[0][0]=t==2?1:0;
			g[0][1]=t==2?0:-1;
			g[1][1]=t==0?1:0;
			g[1][2]=t==0?0:-1;
			g[2][2]=t==1?1:0;
			g[2][3]=t==1?0:-1;
			g[3][3]=t==7?1:(t==6?1:0);
			g[3][4]=t==7?0:-1;
			g[4][4]=t==6?1:0;
		}
	}
	Value friend operator *(Value x,Value y){
		Value z;
		z.init(-1);
		// x.show();
		// cout<<"*\n";
		// y.show();
		// cout<<"=\n";
		rep(i,0,5)rep(j,0,5)if(~x.g[i][j])rep(k,0,5)if(~y.g[j][k]){
			update(z.g[i][k],x.g[i][j]+y.g[j][k]);
		}
		// z.show();
		// cout<<"\n";
		return z;
	}
	void show(){
		rep(i,0,5){
			rep(j,0,5)cout<<g[i][j]<<"\t";
			cout<<"\n";
		}
	}
};
struct SEG {
	int l, r;
	Value w;
	SEG( int _l = 0, int _r = 0 ) {l = _l, r = _r;}
} SGT[MXN << 2 | 1];
void create( SEG &T, int t ) {
	T.w.init(w[t]);
}
void fresh( SEG &T, SEG &L, SEG &R ) {
	// cout<<L.l<<","<<L.r<<" * "<<R.l<<","<<R.r<<"\n";
	T.w=L.w*R.w;
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
void query( int id, SEG &A ) {
	SEG &T = SGT[id];
	// cout<<A.l<<","<<A.r<<" in "<<T.l<<","<<T.r<<"\n";
	// T.w.show();
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

void solve(){
	int n,q;
	while(~scanf("%d%d",&n,&q)){
		scanf("%s",s);
		rep(i,1,n+1)
			w[i]=s[i-1]-'0';
		build(1,1,n);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			SEG A(l,r);
			query(1,A);
			printf("%d\n",A.w.g[0][4]);
		}
	}
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}