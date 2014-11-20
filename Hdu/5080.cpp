#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define BG begin()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))
const LL MOD = 1000000007;
int x[55],y[55];
int g[55][55];
int p[55];
bool v[55];
inline PII rotate(PII A){
	return MP(-A.BB,A.AA);
}
LL modPow(LL a,LL n){
	LL ret=1;a%=MOD;
	while(n){
		if(n&1)ret=ret*a%MOD;
		a=a*a%MOD;
		n>>=1;
	}
	return ret;
}
int main() {
	int i,j;
	int _T;
	scanf("%d",&_T);
	while(_T--){
		int n,m,c;
		scanf("%d%d%d",&n,&m,&c);
		memset(g,0,sizeof g);
		int sx=0,sy=0;
		for(i=1;i<=n;i++){
			scanf("%d%d",&x[i],&y[i]);
			x[i]*=n;
			y[i]*=n;
			sx+=x[i],sy+=y[i];
		}
		for(i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u][v]=g[v][u]=1;
		}
		sx/=n,sy/=n;
		for(i=1;i<=n;i++)x[i]-=sx,y[i]-=sy;
		map<pair<int,int>,int >V;
		for(i=1;i<=n;i++)V[MP(x[i],y[i])]=i;
		int ng=1;
		LL ans=modPow(c,n);
		for(int t=1;t<4;t++){
			int fail=0;
			memset(p,-1,sizeof p);
			for(i=1;i<=n;i++){
				PII z=MP(x[i],y[i]);
				for(j=0;j<t;j++)
					z=rotate(z);
				if(V.find(z)==V.ED){
					fail=1;break;
				}
				p[i]=V[z];
			}
			if(fail)continue;
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(g[p[i]][p[j]]!=g[i][j])
						fail=1;
			if(fail)continue;
			memset(v,0,sizeof v);
			int ff=0;
			for(i=1;i<=n;i++)if(!v[i]){
				v[i]=1;
				for(j=p[i];j!=i;j=p[j])
					v[j]=1;
				ff++;
			}
			ans=ans+modPow(c,ff);
			ng++;
			if(ans>=MOD)ans-=MOD;
		}
		ans=ans*modPow(ng,MOD-2)%MOD;
		printf("%I64d\n",ans);
	}
	return 0;
}
/*
2
5 6 2
0 0 1 0 0 1 -1 0 0 -1
1 2 1 3 2 3 3 4 4 5 5 2
5 4 2
0 0 1 0 0 1 -1 0 0 -1
2 3 3 4 4 5 5 2
*/
