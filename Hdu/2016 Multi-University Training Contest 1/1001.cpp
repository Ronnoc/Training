#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}
int fa[100005];
int getfa(int u){return fa[u]==u?u:fa[u]=getfa(fa[u]);}
PII S[1000005];
vector<PII>G[100005];
int q[100005],ql,qr;
int vis[100005];
int dp[100005],df[100005];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n)fa[i+1]=i+1,G[i+1].clear(),vis[i+1]=0,dp[i+1]=0;
	rep(i,0,1000001)S[i]=MP(-1,-1);
	rep(i,0,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		S[w]=MP(u,v);
	}
	LL cost=0;
	rep(i,0,1000001){
		PII pr=S[i];
		if(pr.AA==-1)continue;
		int u=pr.AA,v=pr.BB,w=i;
		if(getfa(u)!=getfa(v)){
			cost+=w;
			fa[getfa(u)]=getfa(v);
			G[u].PB(MP(v,w));
			G[v].PB(MP(u,w));
		}
	}
	ql=qr=0;
	q[qr++]=1;
	vis[1]=1;
	while(qr>ql){
		int u=q[ql++];
		rep(i,0,sz(G[u])){
			int v=G[u][i].AA;
			if(!vis[v]){
				vis[v]=1;
				df[v]=G[u][i].BB;
				q[qr++]=v;
			}
		}
	}
	for(int i=qr-1;i>=0;i--){
		dp[q[i]]=1;
		rep(j,0,sz(G[q[i]]))
			dp[q[i]]+=dp[G[q[i]][j].AA];
	}
	LL sum=0;
	LL tot=1LL*n*(n-1);
	rep(i,1,qr){
		sum+=1LL*df[q[i]]*dp[q[i]]*(n-dp[q[i]])*2;
	}
	printf("%I64d %.2f\n",cost,1.*sum/tot);
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}