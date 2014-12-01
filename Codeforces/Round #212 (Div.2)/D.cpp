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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define UNIQUE(x) x.erase(unique(x.OP,X.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int n,m,p,q;
int fa[111111];
LL s[111111];
const LL UB = 1000000000LL;
int getfa (int id) {
	return fa[id]==id?id:fa[id]=getfa (fa[id]);
}
void solve() {
	while (~scanf ("%d%d%d%d",&n,&m,&p,&q)) {
		int i,j;
		for (i=1; i<=n; i++) fa[i]=i;
		set<int>S;
		set<pair<LL,int> >M;
		set<pair<LL,int> >::iterator iter;
		LL tmd=0;
		PII tp=MP (-1,-1);
		for (i=1; i<=n; i++) S.insert (i);
		for (i=1; i<=n; i++) M.insert (MP (0,i));
		for (j=1; j<=m; j++) {
			int x,y,l;
			scanf ("%d%d%d",&x,&y,&l);
			tmd+=l;
			int fx=getfa (x);
			int fy=getfa (y);
			if (fx!=fy) {
				fa[fx]=fy;
				M.erase (M.find (MP (s[fx],fx)));
				M.erase (M.find (MP (s[fy],fy)));
				s[fy]+=s[fx]+l;
				s[fx]=0;
				M.insert (MP (s[fy],fy));
				tp=MP (x,y);
//				cout<<fx<<" "<<fy<<endl;
				S.erase (S.find (fx));
			} else {
				M.erase (M.find (MP (s[fx],fx)));
				s[fx]+=l;
				tp=MP (x,y);
				M.insert (MP (s[fx],fx));
			}
		}
		if (n==1) {
			if (p==0&&q==1) printf ("YES\n");
			else printf ("NO\n");
			continue;
		}
		if (S.SZ<q) {
			printf ("NO\n");
			continue;
		}
		vector<PII>res;
		for (i=1; i<=p; i++) {
			if (S.SZ==q) {
				if (tp.AA==-1) break;
				else {
					res.PB (tp);
					int fx=getfa (tp.AA);
					M.erase (M.find (MP (s[fx],fx)));
					tmd+=1000;
					s[fx]+=1000;
					M.insert (MP (s[fx],fx));
				}
			} else {
				iter=M.begin();
				pair<LL,int>x=*iter;
				M.erase (iter);
				iter=M.begin();
				pair<LL,int>y=*iter;
				M.erase (iter);
				fa[x.BB]=fa[y.BB];
				LL how=min (UB,s[x.BB]+s[y.BB]+1);
				s[y.BB]+=s[x.BB]+how;
				s[x.BB]=0;
				tmd+=how;
				M.insert (MP (s[y.BB],y.BB));
				tp=MP (x.BB,y.BB);
				res.PB (tp);
//				cout<<tp.AA<<"~"<<tp.BB<<endl;
				S.erase (S.find (x.BB));
			}
		}
		if (S.SZ==q&&res.SZ==p) {
			printf ("YES\n");
			for (i=0; i<res.SZ; i++) printf ("%d %d\n",res[i].AA,res[i].BB);
		} else printf ("NO\n");
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
/*
2 10 1 1
1 2 1000000000
2 1 1000000000
2 1 1000000000
1 2 1000000000
1 2 56556756
2 1 1
1 2 1000000000
2 1 1000000000
2 1 1000000000
1 2 1000000000
*/
