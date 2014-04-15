#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
//Segment Tree
#define L(t) (t << 1)  //Left son
#define R(t) (t << 1 | 1) //Right son
#define mid(a,b) ((a+b)>>1) //Get Mid
#define MAXN 1003
int n,m;
struct sub_node {
	short l, r;
	long long val;
} sub_tree[MAXN * 4][MAXN * 4];
struct node { //main tree
	short l, r;
} tree[MAXN * 4];
void sub_build (int mroot, int l, int r, int root) {
	sub_tree[mroot][root].l = l;
	sub_tree[mroot][root].r = r;
	sub_tree[mroot][root].val = 0LL;
	if (l == r) return ;
	int m = mid (l, r);
	sub_build (mroot, l, m, L (root));
	sub_build (mroot, m + 1, r, R (root));
}
void build (int l, int r, int root) {
	tree[root].l = l;
	tree[root].r = r;
	sub_build (root, 1, n, 1);
	if (l == r) return ;
	int m = mid (l, r);
	build (l, m, L (root));
	build (m + 1, r, R (root));
}
void sub_modify (int mroot, int l, int r, int root, long long val) {
	if (sub_tree[mroot][root].l == l && sub_tree[mroot][root].r == r) {
		/*if((r-l+1)%2==1)*/sub_tree[mroot][root].val ^= val;
		return ;
	}
	int m = mid (sub_tree[mroot][root].l, sub_tree[mroot][root].r);
	if (r <= m)
		sub_modify (mroot, l, r, L (root), val);
	else if (l > m)
		sub_modify (mroot, l, r, R (root), val);
	else {
		sub_modify (mroot, l, m, L (root), val);
		sub_modify (mroot, m + 1, r, R (root), val);
	}
}
void modify (int l, int r, int ly, int ry, int root, long long val) {
	if (tree[root].l == l && tree[root].r == r) {
		sub_modify (root, ly, ry, 1, val);
		return ;
	}
	int m = mid (tree[root].l, tree[root].r);
	if (r <= m)
		modify (l, r, ly, ry, L (root), val);
	else if (l > m)
		modify (l, r, ly, ry, R (root), val);
	else {
		modify (l, m, ly, ry, L (root), val);
		modify (m + 1, r, ly, ry, R (root), val);
	}
}
long long sub_query (int mroot, int l, int r, int root, int val) {
	if (sub_tree[mroot][root].l == l && sub_tree[mroot][root].r == r)
		return sub_tree[mroot][root].val;
	int m = mid (sub_tree[mroot][root].l, sub_tree[mroot][root].r);
	long long ret = 0;
	if (r <= m)
		ret ^= sub_query (mroot, l, r, L (root), val);
	else if (l > m)
		ret ^= sub_query (mroot, l, r, R (root), val);
	else {
		ret ^= sub_query (mroot, l, m, L (root), val);
		ret ^= sub_query (mroot, m + 1, r, R (root), val);
	}
	return ret;
}
long long query (int l, int r, int ly, int ry, int root, int val) {
	if (tree[root].l == l && tree[root].r == r)
		return sub_query (root, ly, ry, 1, val);
	int m = mid (tree[root].l, tree[root].r);
	long long ret = 0;
	if (r <= m)
		ret ^= query (l, r, ly, ry, L (root), val);
	else if (l > m)
		ret ^= query (l, r, ly, ry, R (root), val);
	else {
		ret ^= query (l, m, ly, ry, L (root), val);
		ret ^= query (m + 1, r, ly, ry, R (root), val);
	}
	return ret;
}
int main() {
	cin >> n >> m;
	build(1,n,1);
	while (m--) {
		int q, x1, x2, y1, y2;
		long long val=0LL;
		cin >> q;
		cin >> x1 >> y1 >> x2 >> y2;
		if (q == 1)
			cout << query (x1, x2, y1, y2, 1, val) << endl;
		else {
			cin >> val;
			modify (x1, x2, y1, y2, 1, val);
		}
	}
	return 0;
}
