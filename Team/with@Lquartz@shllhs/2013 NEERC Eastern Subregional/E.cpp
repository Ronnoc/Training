//kybconnor
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
long double dp[222][22];
int vis[222][22];
long double comb[222][222];
long double dfs (int n,int k) {
	n-=k;
	if (k==0) return n;
	if (n<=k) return 0;
	if (vis[n][k]) return dp[n][k];
	long double mxexp=0;
	int kill=n,i,j;
	for (i=1; i<n; i++) {
		long double zong=comb[n][i];
		long double now=0;
		for (j=0; j<=k&&j<=i; j++) {
			long double psb=comb[k][j]*comb[n-k][i-j]/zong;
			now+=psb* dfs(n-i,k-j);
		}
		if (now>mxexp) mxexp=now,kill=i;
	}
	vis[n][k]=1;
	return dp[n][k]=mxexp;
}
int main() {
	int i,j;
	for (i=0; i<=200; i++) for (j=0; j<=200; j++)
			comb[i][j]=0;
	comb[0][0]=1;
	for (i=1; i<=200; i++) {
		comb[i][0]=1;
		for (j=1; j<=i; j++)
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
	}
	int n,k;
	while (~scanf ("%d%d",&n,&k)) {
		memset (vis,0,sizeof vis);
		printf("%.15lf\n",double(dfs(n,k)));
	}
	return 0;
}
