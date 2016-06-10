#include<bits/stdc++.h>
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
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
const int MXN = 100000+5;
vector<int>G[MXN];
int a[MXN];
int s[MXN];
int mu[MXN], p[MXN], pn;
bool flag[MXN];
void sieve(int n) {
	pn = 0;
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			p[pn ++ ] = i;
			mu[i] = -1;						//phi[i]=i-1;
		}
		for (int j = 0; j < pn && i * p[j] <= n; j++) {
			flag[i * p [j]] = true;
			if (i % p[j] == 0) {
				mu[i * p[j]] = 0;			//phi[i * p[j]] = p[j] * phi[i];
				break;
			} else  mu[i * p[j]] = -mu[i];	//phi[i * p[j]] = (p[j] - 1) * phi[i];
		}
	}
}
LL dp[MXN];
LL ct[MXN];
LL ANS;
void dfs(int u,int f,int g){
	int i,v;
	dp[u]=0,ct[u]=0;
	for(i=0;i<G[u].SZ;i++){
		v=G[u][i];
		if(v==f)continue;
		dfs(v,u,g);
		ANS+=(dp[u]+ct[u])*ct[v]+(dp[v]+ct[v])*ct[u];
		dp[u]+=dp[v];
		ct[u]+=ct[v];
	}
	//cout<<u<<" "<<dp[u]<<" "<<ct[u]<<" "<<ANS<<"\n";
	if(a[u]%g==0){
		ANS+=dp[u]+ct[u];
		dp[u]+=ct[u];
		ct[u]++;
	}else
		dp[u]+=ct[u];
	//cout<<u<<" "<<dp[u]<<" "<<ct[u]<<" "<<ANS<<"\n";
}
int main(){
	int i,j,k,_T;
	int n;
	sieve(100005);
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=n;i++)G[i].clear();
		for(i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].PB(v);
			G[v].PB(u);
		}
		LL res=0;
		for(i=1;i<=100000;i++)s[i]=0;
		for(i=1;i<=n;i++)s[a[i]]++;
		for(i=1;i<=100000;i++)
			for(j=i<<1;j<=100000;j+=i)
				s[i]+=s[j];
		for(i=1;i<=100000;i++)if(mu[i]&&s[i]>1){
			ANS=0;
			dfs(1,-1,i);
			res+=mu[i]*ANS;
			//cout<<"~"<<i<<" "<<ANS<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}