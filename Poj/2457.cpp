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

vector<int>G[1010];
int d[1010],pre[1010];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,T;
	while(~scanf("%d%d",&m,&n)) {
		for(i=1; i<=n; i++)G[i].clear(),d[i]=MOD,pre[i]=-1;
		for(i=0; i<m; i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].PB(v);
		}
		d[1]=0;
		priority_queue<PII>Q;
		Q.push(MP(-d[1],1));
		while(!Q.empty()) {
			PII tp=Q.top();
			Q.pop();
			int u=tp.BB,t=-tp.AA;
			if(d[u]<t)continue;
			for(i=0; i<G[u].SZ; i++) {
				int v=G[u][i];
				if(d[v]>t+1) {
					d[v]=t+1;
					pre[v]=u;
					Q.push(MP(-d[v],v));
				}
			}
		}
		vector<int>L;
		L.PB(n);
		while(~pre[n]) {
			n=pre[n];
			L.PB(n);
		}
		reverse(L.OP,L.ED);
		if(d[n]!=MOD) {
			printf("%d\n",L.SZ);
			for(i=0; i<L.SZ; i++)printf("%d\n",L[i]);
		}else puts("-1");
	}
	return 0;
}

