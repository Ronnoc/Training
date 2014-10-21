#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;
const int MXN = 20000 + 10;
struct State {
	State *suf, *go[26], *nxt;//nxt FOR cnt,suf is Parrent
	int val, cnt;//val=Maxlen,cnt=num of suffix start from=|Right|
	State() {fresh();}//Minlen=suf->val+1
	void fresh() {
		suf=0,val=0;
		memset(go, 0, sizeof go);
	}
}*root, *last;
State statePool[MXN<<1],*cur;
State*first[MXN] = {};

void init() {
	cur = statePool;
	root = last = cur++;
	root->fresh();
	/*
	for(State*i = statePool; i != cur; ++i)
		i->nxt = first[i->val], first[i->val] = i;
	for(int it = L; it >= 0; --it) {
		for(State*i = first[it]; i; i = i->nxt)
			if(i->suf)
				i->suf->cnt += i->cnt;
	}
	/**/
}
void extend(int w) {
	State*p = last, *np = cur++;
	np->fresh();
	np->val = p->val + 1;
	np->cnt = 1;
	while(p && !p->go[w])
		p->go[w] = np, p = p->suf;
	if(!p)
		np->suf = root;
	else {
		State*q = p->go[w];
		if(p->val + 1 == q->val) {
			np->suf = q;
		} else {
			State*nq = cur++;
			nq->fresh();
			memcpy(nq->go, q->go, sizeof q->go);
			nq->val = p->val + 1;
			nq->suf = q->suf;
			q->suf = nq;
			np->suf = nq;
			while(p && p->go[w] == q)
				p->go[w] = nq, p = p->suf;
		}
	}
	last = np;
}
int dp[MXN<<2];
int gao(State *now) {
	int &tp=dp[now-statePool];
	if(~tp)return tp;
	if(now==last)return tp=now->val;
	tp=MOD;
	for(int i=0; i<26; i++)if(now->go[i])
			cmin(tp,gao(now->go[i])-1);
	return tp;
}
char s[MXN];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--) {
		init();
		scanf("%s",s);
		int len=strlen(s);
		for(i=0; i<len; i++)extend(s[i]-'a');
		for(i=0; i<len; i++)extend(s[i]-'a');
		for(State*i=statePool; i!=cur; ++i)
			dp[i-statePool]=-1;
		gao(root);
//		for(State*i=statePool; i!=cur; ++i) {
//			printf("%4d:val=%2d,dp=%2d",i-statePool,i->val,dp[i-statePool]);
//			printf(" suf@%2d",i->suf?i->suf-statePool:-1);
//			for(int j=0; j<26; j++)if(i->go[j])printf(" ->%c@%d",j+'a',i->go[j]-statePool);
//			printf("\n");
//		}
		State *now=root;
		int tmp=len;
		while(tmp--)
			for(i=0; i<26; i++)if(now->go[i]) {
					now=now->go[i];
					break;
				}
		printf("%d\n",dp[now-statePool]-len+1);
	}
	return 0;
}
