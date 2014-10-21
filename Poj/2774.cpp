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
const int MXN = 100000 + 10;//sizeof str
struct State {
	State *suf, *go[26];
	int val,ans;//val=Maxlen
	State() {fresh();}//Minlen=suf->val+1
	void fresh() {
		suf=0,val=0,ans=0;
		memset(go, 0, sizeof go);
	}
}*root, *last;
State statePool[MXN<<1],*cur;
State*first[MXN] = {};
void init() {
	cur = statePool;
	root = last = cur++;
	root->fresh();
}
void extend(int w) {
	State*p = last, *np = cur++;
	np->fresh();
	np->val = p->val + 1;
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
char a[MXN],b[MXN];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	while(~scanf("%s%s",a,b)) {
		int la=strlen(a),lb=strlen(b);
		init();
		for(i=0; i<la; i++)extend(a[i]-'a');
		State *now=root;
		int len=0;
		for(i=0; i<lb; i++) {
			if(now->go[b[i]-'a']) {
				len++;
				now=now->go[b[i]-'a'];
			} else {
				while(now!=root&&!now->go[b[i]-'a'])
					now=now->suf;
				if(now->go[b[i]-'a']) {
					len=now->val+1;
					now=now->go[b[i]-'a'];
				} else len=0;
			}
			cmax(now->ans,len);
		}
		int ans=0;
		for(State *i=statePool; i!=cur; ++i)
			cmax(ans,i->ans);
		printf("%d\n",ans);
	}
	return 0;
}
