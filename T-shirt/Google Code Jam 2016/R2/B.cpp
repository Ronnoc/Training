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
double p[205];
double dp[222][222];
double play(vector<double>L){
	int n=L.SZ;
	int i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			dp[i][j]=0;
	dp[0][0]=1;
	for(i=0;i<n;i++)for(j=0;j<=i;j++)if(dp[i][j]>1e-100){
		dp[i+1][j+1]+=dp[i][j]*L[i];
		dp[i+1][j]+=dp[i][j]*(1-L[i]);
	}
	return dp[n][n>>1];
}
void solve(){
	int i,j,k;
	int N,K;
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;i++)
		scanf("%lf",&p[i]);
	sort(p+1,p+N+1);
	double ans;
	/*
	ans=0;
	for(k=0;k<1<<N;k++)if(__builtin_popcount(k)==K){
		vector<double>L;
		for(i=0;i<N;i++)if(k>>i&1)L.PB(p[i+1]);
		double now=play(L);
		cmax(ans,now);
	}
	printf("%.16lf\n",ans);
	return;
	*/
	ans=0;
	for(i=0;i<=K;i++){
		vector<double>L;
		for(j=1;j<=i;j++)
			L.PB(p[j]);
		for(j=1;j<=K-i;j++)
			L.PB(p[N+1-j]);
		double now=play(L);
		cmax(ans,now);
	}
	printf("%.16lf\n",ans);
}
int main(){
	int _T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		printf("Case #%d: ",CA);
		solve();
	}
	return 0;
}