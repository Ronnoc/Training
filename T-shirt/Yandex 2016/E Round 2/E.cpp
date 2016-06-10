#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
const int MXN = 200000 + 10;
struct SEG {
	int l, r, m;
	SEG( int _l = 0, int _r = 0 ) {l = _l, r = _r;}
} SGT[MXN << 2 | 1];
void create( SEG &T, int t ) {
	T.m = 0;
}
void fresh( SEG &T, SEG &L, SEG &R ) {
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
void update( int id, int x, int w ) {
	SEG &T = SGT[id];
	int mid = ( T.l + T.r ) / 2;
	if ( T.l == x && T.r == x ) {
		T.m += w;
		return;
	}
	if ( x <= mid )update( id << 1, x, w );
	else update( id << 1 | 1, x, w );
	fresh( T, SGT[id << 1], SGT[id << 1 | 1] );
}
void query( int id, SEG &A ) {
	SEG &T = SGT[id];
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
vector<int>G[MXN],tp[MXN];
int a[MXN],n;
int le[MXN],re[MXN],tim;
int s[MXN],z[MXN];
void dfs(int u,int f){
	++tim;
	le[u]=tim;
	for(auto v:G[u])if(v!=f)
		dfs(v,u);
	re[u]=tim;
}
LL dp[MXN];
void dfsdp(int u,int f){
	//cout<<u<<" "<<f<<" "<<dp[u]<<"\n";
	for(int i=0;i<G[u].SZ;i++){
		int v=G[u][i];
		if(v==f)continue;
		dp[v]=dp[u]-tp[u][i]-s[v]+z[v];
		dfsdp(v,u);
	}
}
int main(){
	int i,j,k,_T;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)
			G[i].clear(),tp[i].clear();
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		map<int,vector<int> >F;
		for(i=1;i<=n;i++)
			F[-a[i]].PB(i);
		for(i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].PB(v),G[v].PB(u);
		}
		tim=0;
		dfs(1,-1);
		build(1,1,n);
		int cnt=0;
		for(auto f:F){
			for(i=0;i<(f.BB).SZ;i++){
				int u=f.BB[i];
				SEG A(le[u],re[u]);
				query(1,A);
				s[u]=A.m;
				z[u]=cnt;
				for(j=0;j<G[u].SZ;j++){
					int v=G[u][j];
					SEG A(le[v],re[v]);
					query(1,A);
					tp[u].PB(A.m);
				}
			}
			for(auto u:f.BB)
				update(1,le[u],1),cnt++;
		}
		dp[1]=0;
		for(i=1;i<=n;i++)
			dp[1]+=s[i];
		dfsdp(1,-1);
		LL ans=dp[1];
		int id=1;
		for(i=1;i<=n;i++)
			if(dp[i]<dp[id])
				ans=dp[id=i];
		cout<<id<<" "<<ans<<"\n";
	}
	return 0;
}