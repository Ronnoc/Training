//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#define ls l,mid,rt<<1
#define rs mid+1,r,rt<<1|1
#define mid ((l+r)>>1)
#define N 200505
using namespace std;
struct node {
	int v,next;
} edge[2*N];
int head[N],l[N],r[N];
int cnt,idx;

struct seg {
	int l,r,num,rev;
} tree[5*N];
void addedge (int a,int b) {
	edge[cnt].v = b;
	edge[cnt].next = head[a];
	head[a] = cnt++;
}
void dfs (int u,int fa) {
	l[u] = idx++;
	for (int i = head[u]; i!=-1; i = edge[i].next) {
		int v = edge[i].v;
		if (v == fa) continue;
		dfs (v,u);
	}
	r[u] = idx++;
}
void build (int l,int r,int rt) {
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].num = 0;
	tree[rt].rev = 0;
	if (l == r) return;
	build (ls);
	build (rs);
}
void pushdown (int rt) {
	if (tree[rt].rev) {
		tree[rt<<1].rev = tree[rt<<1].rev^tree[rt].rev;
		tree[rt<<1|1].rev = tree[rt<<1|1].rev^tree[rt].rev;
		tree[rt<<1].num = tree[rt<<1].r-tree[rt<<1].l+1-tree[rt<<1].num;
		tree[rt<<1|1].num = tree[rt<<1|1].r-tree[rt<<1|1].l+1-tree[rt<<1|1].num;
		tree[rt].rev = 0;
	}
}
void pushup (int rt) {
	tree[rt].num = tree[rt<<1].num+tree[rt<<1|1].num;
}
void update (int l,int r,int rt,int L,int R) {
	if (L<=l&&R>=r) {
		tree[rt].rev = 1-tree[rt].rev;
		tree[rt].num = r-l+1-tree[rt].num;
		return;
	}
	pushdown (rt);
	if (L<=mid) update (ls,L,R);
	if (R>mid) update (rs,L,R);
	pushup (rt);
}
int query (int l,int r,int rt,int L,int R) {
	if (L<=l&&R>=r) return tree[rt].num;
	pushdown (rt);
	int ret = 0;
	if (L<=mid) ret+=query (ls,L,R);
	if (R>mid) ret+=query (rs,L,R);
	return ret;
}
int main() {
	int n,m,i,j;
	while (scanf ("%d%d",&n,&m) !=EOF) {
		memset (head,-1,sizeof (head));
		cnt = 0;
		idx = 1;
		for (i = 1; i<n; i++) {
			int x;
			scanf ("%d",&x);
			addedge (i+1,x);
			addedge (x,i+1);
		}
		dfs (1,-1);
		idx--;
		build (1,idx,1);
		for (i = 1; i<=m; i++) {
			char op[2];
			int x;
			scanf ("%s %d",op,&x);
			if (op[0] == 'o') update (1,idx,1,l[x],r[x]);
			else printf ("%d\n",query (1,idx,1,l[x],r[x]) /2);
		}
		printf ("\n");
	}
	return 0;
}
