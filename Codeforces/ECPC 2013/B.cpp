#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define OP begin()
#define ED end()
#define BB second
#define AA first
#define SZ size()
typedef pair<int,int> PII;
typedef long long LL;
const double PI = acos(-1.);
const double eps = 1e-8;
int rk[200005];
int fa[200005];
int lazy[200005];
int getfa(int u){
	if(u==fa[u])return u;
	int v=fa[u];
	int f=getfa(v);
	if(v!=f)lazy[u]+=lazy[v];
	if(v!=f)rk[v]-=rk[u];
	return fa[u]=f;
}
int main(){
	freopen("road.in","r",stdin);
	int i,j,T;
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		printf("Case %d:\n",CA);
		int n,m;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)fa[i]=i,rk[i]=1,lazy[i]=0;
		int next=n;
		vector<pair<int,PII> >L;
		while(m--){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			L.PB(MP(w,MP(u,v)));
		}
		sort(L.OP,L.ED);
		for(i=0;i<L.SZ;i++){
			int u=L[i].BB.AA;
			int v=L[i].BB.BB;
			u=getfa(u);
			v=getfa(v);
			if(u!=v){
				next++;
				fa[next]=next;
				rk[next]=rk[u]+rk[v];
				lazy[next]=0;
				fa[u]=next;
				fa[v]=next;
				lazy[u]+=L[i].AA*rk[v];
				lazy[v]+=L[i].AA*rk[u];
			}
		}
		for(i=1;i<=n;i++)getfa(i);
		for(i=1;i<=n;i++)printf("%d\n",lazy[i]);
	}
	return 0;
}
