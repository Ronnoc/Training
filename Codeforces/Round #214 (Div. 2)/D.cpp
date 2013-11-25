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
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int a[3333],b[3333],l[3333],r[3333];
int n,m;
struct edge{
	int to,l,r;
	edge(int _t,int _l,int _r)
		{to=_t,l=_l,r=_r;}
};
vector<edge>G[1111];
int d[1111];
priority_queue<PII>Q;
void solve(){
	while(scanf("%d%d",&n,&m)!=EOF){
		int i,x;
		for(i=1;i<=m;i++)
			scanf("%d%d%d%d",&a[i],&b[i],&l[i],&r[i]);
		int ll=1111111,rr=-1;
		for(i=1;i<=n;i++)G[i].clear();
		for(i=1;i<=m;i++){
			ll=min(ll,l[i]);
			rr=max(rr,r[i]);
			G[a[i]].PB(edge(b[i],l[i],r[i]));
			G[b[i]].PB(edge(a[i],l[i],r[i]));
		}
		int res=0;
		for(x=ll;x<=rr;x++){
			for(i=2;i<=n;i++)d[i]=-1;
			d[1]=rr;
			Q.push(MP(d[1],1));
			while(!Q.empty()){
				int u=Q.top().BB;
				int D=Q.top().AA;
				Q.pop();
				if(D<d[u])continue;
				if(D<d[n])continue;
				for(i=0;i<G[u].SZ;i++){
					if(x<G[u][i].l||x>G[u][i].r)continue;
					int v=G[u][i].to;
					int R=min(D,G[u][i].r);
					if(d[v]<R){
						d[v]=R;
						Q.push(MP(d[v],v));
					}
				}
			}
			if(d[n]!=-1){
				res=max(res,d[n]-x+1);
				x=d[n];
			}
		}
		if(res)printf("%d\n",res);
		else printf("Nice work, Dima!\n");
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
