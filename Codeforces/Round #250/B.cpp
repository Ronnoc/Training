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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
int fa[100005];
int rk[100005];
int getfa(int u){
	if(fa[u]==u)return u;
	rk[fa[u]]+=rk[u];
	rk[u]=0;
	return fa[u]=getfa(fa[u]);
}
vector<pair<int,PII> >L;
int w[100005];
int main(){
	int i,j,u,v;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		L.clear();
		for(i=1;i<=n;i++)scanf("%d",&w[i]);
		for(i=1;i<=n;i++)fa[i]=i;
		for(i=1;i<=n;i++)rk[i]=1;
		for(i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			L.PB(MP(-min(w[u],w[v]),MP(u,v)));
		}
		SORT(L);
		LL ans=0;
		for(i=0;i<L.SZ;i++){
			int u=L[i].BB.AA;
			int v=L[i].BB.BB;
			int fu=getfa(u);
			int fv=getfa(v);
			//cout<<u<<" "<<v<<" "<<rk[u]<<" "<<rk[v]<<endl;
			if(fu!=fv){
				ans+=1LL*rk[fu]*rk[fv]*L[i].AA;
				rk[fu]+=rk[fv];
				rk[fv]=0;
				fa[fv]=fu;
			}
		}
		double out=-ans;
		out/=n;
		out/=n-1;
		out*=2;
		printf("%.6lf\n",out);
	}
	return 0;
}
