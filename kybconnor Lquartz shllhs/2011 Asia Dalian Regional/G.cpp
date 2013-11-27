//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#define N 1005
#define Max 4
#define inf 1000000007
using namespace std;
struct node {
	int count,id;
	node *next[Max],*fail;
} tree[N],*root;
int cnt;
node* newnode() {
	for (int i = 0; i<Max; i++) tree[cnt].next[i] = NULL;
	tree[cnt].fail = NULL;
	tree[cnt].count = 0;
	tree[cnt].id =  cnt;
	return &tree[cnt++];
}
int get (char x) {
	if (x == 'A') return 0;
	if (x == 'C') return 1;
	if (x == 'G') return 2;
	return 3;
}
void insert (char *str,int x) {
	int i = 0,s;
	node *t = root;
	while (str[i]) {
		s=get (str[i]);
		if (t->next[s]==NULL)
			t->next[s]=newnode();
		t=t->next[s];
		i++;
	}
	t->count += (1<<x);
}
void build_ac() {
	queue<node *>q;
	node *tmp = root;
	q.push (tmp);
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		for (int i = 0; i<Max; i++) {
			if (tmp->next[i]==NULL) {
				if (tmp==root) tmp->next[i]=root;
				else tmp->next[i]=tmp->fail->next[i];
			} else {
				if (tmp == root) tmp->next[i]->fail = root;
				else {
					tmp->next[i]->fail = tmp->fail->next[i];
					tmp->next[i]->count|=tmp->fail->next[i]->count;
				}
				q.push (tmp->next[i]);
			}
		}
	}
}
int n,l;
char s[1000005];
int dp[2][1005][1205];
int val[1205],c[15];
void ini() {
	for (int i = 0; i< (1<<n); i++) {
		val[i] = 0;
		for (int j = 0; j<n; j++)
			if (i& (1<<j)) val[i]+=c[j];
	}
}
int main() {
	while (scanf ("%d%d",&n,&l) !=EOF) {
		int i,j,k;
		cnt = 0;
		root = newnode();
		for (i = 0; i<n; i++) {
			scanf ("%s%d",s,&c[i]);
			if (strlen (s) <=l) insert (s,i);
		}
		ini();
		build_ac();
		for (int ii = 0; ii<1005; ii++)
			for (int jj = 0; jj<1205; jj++)
				dp[0][ii][jj] = -inf;
		dp[0][0][0] = 0;
		for (i = 0; i<l; i++) {
			int x = i&1,y = 1-x,z;
			for (int ii = 0; ii<1005; ii++)
				for (int jj = 0; jj<1205; jj++)
					dp[y][ii][jj] = -inf;
			for (j = 0; j<cnt; j++) {
				for (k = 0; k< (1<<n); k++) {
					if (dp[x][j][k] == -inf) continue;
					for (z = 0; z<Max; z++) {
						int nt = tree[j].next[z]->id;
						int st = k|tree[j].next[z]->count;
						dp[y][nt][st] = val[st];
					}
				}
			}
		}
		int ans = -1;
		for (j = 0; j<cnt; j++) {
			for (k = 0; k< (1<<n); k++) {
				ans = max (ans,dp[l&1][j][k]);
			}
		}
		if (ans>=0) printf ("%d\n",ans);
		else printf ("No Rabbit after 2012!\n");
	}
	return 0;
}
