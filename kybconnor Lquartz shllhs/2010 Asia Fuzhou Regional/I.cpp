//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#define ls l,mid,rt<<1
#define rs mid+1,r,rt<<1|1
#define mid ((l+r)>>1)
#define N 5055
#define M 155
using namespace std;
struct node {
	int l,r,c,lazy;
} tree[4*N];
int t[M][N],d[M][N],dp[M][N];
void pushup (int rt) {
	tree[rt].c = min (tree[rt<<1].c,tree[rt<<1|1].c);
}
void pushdown (int rt) {
	if (tree[rt].lazy!=0x7f7f7f7f) {
		tree[rt<<1].lazy = min (tree[rt<<1].lazy,tree[rt].lazy);
		tree[rt<<1|1].lazy = min (tree[rt<<1|1].lazy,tree[rt].lazy);
		tree[rt<<1].c = min (tree[rt<<1].c,tree[rt].lazy);
		tree[rt<<1|1].c = min (tree[rt<<1|1].c,tree[rt].lazy);
		tree[rt].lazy = 0x7f7f7f7f;
	}
}
void build (int l,int r,int rt,int row) {
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].lazy = 0x7f7f7f7f;
	if (l == r) {
		tree[rt].c = dp[row][l];
		return;
	}
	build (ls,row);
	build (rs,row);
	pushup (rt);
}
void update (int l,int r,int rt,int L,int R,int c) {
	if (L<=l&&R>=r) {
		tree[rt].lazy = min (tree[rt].lazy,c);
		tree[rt].c = min (tree[rt].c,c);
		return;
	}
	pushdown (rt);
	if (L<=mid) update (ls,L,R,c);
	if (R>mid) update (rs,L,R,c);
	pushup (rt);
}
int query (int l,int r,int rt,int L,int R) {
	if (L<=l&&R>=r) {
		return tree[rt].c;
	}
	pushdown (rt);
	int ret = 0x7f7f7f7f;
	if (L<=mid) ret = min (ret,query (ls,L,R));
	if (R>mid) ret = min (ret,query (rs,L,R));
	return ret;
}
int main() {
	int n,m,i,j;
	while (scanf ("%d%d",&n,&m) &&n&&m) {
		for (i = 1; i<=n; i++) {
			for (j = 1; j<=m; j++) {
				scanf ("%d",&t[i][j]);
			}
		}
		for (i = 1; i<=n; i++) {
			for (j = 1; j<=m; j++) {
				scanf ("%d",&d[i][j]);
			}
		}
		memset (dp,0x7f,sizeof (dp));
		for (i = 1; i<=m; i++) dp[0][i] = 0;
		build (1,m,1,0);
		for (i = 1; i<=n; i++) {
			for (j = 1; j<=m; j++) {
				dp[i][j] = min (dp[i][j],t[i][j]+query (1,m,1,max (1,j-d[i][j]),min (m,j+d[i][j])));
			}
			build (1,m,1,i);
			for (j = 1; j<=m; j++) {
				update (1,m,1,max (1,j-d[i][j]),min (m,j+d[i][j]),dp[i][j]);
			}
		}
		int ans = 0x7f7f7f7f;
		for (i = 1; i<=m; i++) ans = min (ans,dp[n][i]);
		printf ("%d\n",ans);
	}
	return 0;
}
