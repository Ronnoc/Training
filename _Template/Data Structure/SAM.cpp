const int MXN = 100000 + 10;///TODO
const int goSZ = 26;		///TODO
inline int mhash(char c) {	///TODO
	return c - 'a';
}
struct SAM {
	struct State {
		State *suf, *go[goSZ], *nxt; //Parent=suf
		int val, cnt, le; //le~val |Right|=cnt
		int ans;
		void clear() {
			val = cnt = le = 0, suf = nxt = 0;
			ans = 0;
			memset(go, 0, sizeof go);
		}
	}*root, *last;
	State pool[MXN << 1 | 1], *cur;
	State *head[MXN | 1];
	int L;
	void init() {
		L = 0, cur = pool;
		cur->clear();
		root = last = cur++;
	}
	void extend(int w) {
		L++;
		State *p = last, *np = cur++;
		cur->clear();
		np->val = p->val + 1, np->cnt = 1;
		while (p && !p->go[w])p->go[w] = np, p = p->suf;
		if (!p)np->suf = root;
		else {
			State *q = p->go[w];
			if (p->val + 1 == q->val)np->suf = q;
			else {
				State *nq = cur++;
				cur->clear();
				memcpy(nq->go, q->go, sizeof q->go);
				nq->val = p->val + 1;
				nq->suf = q->suf;
				q->suf = nq;
				np->suf = nq;
				while (p && p->go[w] == q)
					p->go[w] = nq, p = p->suf;
			}
		}
		last = np;
	}
	void topo() {
		for (int i = 0; i <= L; i++)head[i] = 0;
		for (State *p = pool; p != cur; ++p) {
			p->nxt = head[p->val], head[p->val] = p;
			if (p->suf)p->le = p->suf->val + 1;
			else p->le = 1;
		}
		for (int i = L; i >= 0; --i)
			for (State *p = head[i]; p; p = p->nxt)
				if (p->suf)p->suf->cnt += p->cnt;
	}
	void solve(char *s = "") {
		State *now = root;
		int len = 0;
		for (int i = 0; s[i]; i++) {
			int w = mhash(s[i]);
			if (now->go[w]) {
				len++;
				now = now->go[w];
			} else {
				while (now->suf && !now->go[w])
					now = now->suf;
				if (now->go[w]) {
					len = now->val + 1;
					now = now->go[w];
				} else len = 0;
			}
			cmax(now->ans, len);
		}
		for (State *p = pool; p != cur; ++p)if (p->suf)
				cmax(p->ans, p->suf->ans);
		int ans = 0;
		for (State *p = pool; p != cur; ++p)
			cmax(ans, p->ans);
		printf("%d\n", ans);
	}
} foo;