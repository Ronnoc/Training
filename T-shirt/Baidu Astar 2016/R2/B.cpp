#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000009;
const double eps = 1e-9;

vector<int>G[22];
vector<PII>E;
int g[22][22];
LL f[1<<15];
int ne[1<<15];
LL dp[1<<15][16];
LL dfs(int mask,int cnt){
	LL &tp=dp[mask][cnt];
	if(~tp)return tp;
	int cp=__builtin_popcount(mask);
	if(cp<cnt)return tp=0;
	if(cp==cnt)return tp=1;
	tp=0;
	vector<int>L;
	int all=mask;
	while(mask){
		int id=__builtin_ctz(mask&-mask);
		L.PB(id);
		mask^=1<<id;
	}
	int m=L.SZ-1;
	int i,j;
	for(i=0;i<1<<m;i++){
		int now=1<<L[0];
		for(j=0;j<m;j++)if(i>>j&1)
			now|=1<<L[j+1];
		if(f[now])
			tp=(tp+f[now]*dfs(all^now,cnt-1)%MOD)%MOD;
	}
	//cout<<mask<<" "<<cnt<<" "<<tp<<"\n";
	return tp;
}
LL two[333];
int main(){
	int i,j,k,_T;
	for(two[0]=i=1;i<=300;i++)two[i]=two[i-1]*2%MOD;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		int N,M,K;
		scanf("%d%d%d",&N,&M,&K);
		for(i=0;i<=N;i++)
			G[i].clear();
		E.clear();
		memset(ne,0,sizeof ne);
		memset(g,0,sizeof g);
		int fuck=0;
		for(i=0;i<M;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			if(u==v){
				fuck++;
				continue;
			}
			if(u>v)swap(u,v);
			G[u].PB(v),G[v].PB(u);
			g[u][v]=g[v][u]=1;
			E.PB(MP(u,v));
			int mask=((1<<N)-1)^(1<<u)^(1<<v);
			int sub=mask;
			do{
				ne[sub|(1<<u)|(1<<v)]++;
				sub=(sub-1)&mask;
			}while(sub!=mask);
		}
		for(int mk=1;mk<1<<N;mk++){
			vector<int>W;
			for(j=0;j<N;j++)if(mk>>j&1)W.PB(j);
			int u=W[0];
			f[mk]=two[ne[mk]];
			int mask=mk^(1<<u);
			int sub=mask;
			do{
				int now=sub|(1<<u);
				if(now!=mk)
					f[mk]-=f[now]*two[ne[mk^now]]%MOD;
				sub=(sub-1)&mask;
			}while(sub!=mask);
			f[mk]=(f[mk]%MOD+MOD)%MOD;
			//cout<<mk<<"~"<<f[mk]<<"\n";
		}
		for(i=0;i<1<<N;i++)for(j=0;j<=N;j++)
			dp[i][j]=-1;
		printf("Case #%d:\n",CA);
		printf("%d\n",dfs((1<<N)-1,K)*two[fuck]%MOD);
	}
	return 0;
}