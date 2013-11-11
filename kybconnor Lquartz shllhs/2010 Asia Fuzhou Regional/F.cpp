//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#define N 250000
#define Max 26
using namespace std;
struct node {
	int count,id,vis;
	node *next[Max],*fail;
} tree[N],*root;
int cnt;
node *newnode() {
	for (int i = 0; i<Max; i++) {
		tree[cnt].next[i] = NULL;
		tree[cnt].fail = NULL;
		tree[cnt].count = 0;
		tree[cnt].vis = 0;
		tree[cnt].id = cnt;
		return &tree[cnt++];
	}
}
void insert (char *str,int id) {
	int i = 0,s;
	node *t = root;
	while (str[i]) {
		s = str[i]-'A';
		if (t->next[s] == NULL)
			t->next[s] = newnode();
		t = t->next[s];
		i++;
	}
	t->count = id;
}
queue<node *>q;
void build_ac_automation() {
	while(!q.empty())q.pop();
	node *tmp=root;
	q.push (tmp);
	while (!q.empty()) {
		tmp=q.front();
		q.pop();
		for (int i=0; i<Max; i++)
			if (tmp->next[i]==NULL) {
				if (tmp==root) tmp->next[i]=root;
				else tmp->next[i]=tmp->fail->next[i];
			} else {
				if (tmp==root) tmp->next[i]->fail=root;
				else {
					tmp->next[i]->fail=tmp->fail->next[i];
					tmp->next[i]->count|=tmp->fail->next[i]->count;
				}
				q.push (tmp->next[i]);
			}
	}
}
char vi[300][1005];
char txt[5100100];
char s[5100100];
int hash[300];
int main() {
	int t,n,i,j;
	scanf ("%d",&t);
	while (t--) {
		cnt = 0;
		root = newnode();
		scanf ("%d",&n);
		for (i = 1; i<=n; i++) {
			scanf ("%s",vi[i]);
			insert (vi[i],i);
		}
		memset (hash,0,sizeof (hash));
		build_ac_automation();
		scanf ("%s",txt);
		int l = strlen (txt);
		int idx = 0;
		for (i = 0; i<l;) {
			if (txt[i]!='[') {
				s[idx++] = txt[i];
				i++;
			} else {
				int ret = 0;
				i++;
				while (txt[i]-'0'>=0&&txt[i]-'9'<=0) {
					ret = ret*10+txt[i]-'0';
					i++;
				}
				for (j = 0; j<ret; j++) {
					s[idx++] = txt[i];
				}
				i+=2;
			}
		}
		node *tmp = root;
		for (i = 0; i<idx; i++) {
			while (tmp->next[s[i]-'A'] == NULL&&tmp!=NULL)
				tmp = tmp->fail;
			if (tmp == NULL) tmp = root;
			else tmp = tmp->next[s[i]-'A'];
			if (tmp->count) hash[tmp->count] = 1;
		}
		for (i = idx-1; i>=0; i--) {
			while (tmp->next[s[i]-'A'] == NULL&&tmp!=NULL)
				tmp = tmp->fail;
			if (tmp == NULL) tmp = root;
			else tmp = tmp->next[s[i]-'A'];
			if (tmp->count) hash[tmp->count] = 1;
		}
		int ans = 0;
		for (i = 1; i<=n; i++) ans+=hash[i];
		printf ("%d\n",ans);
	}
	return 0;
}
