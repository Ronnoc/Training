#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <string>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
double P[1<<17],Q[1<<17];
double dp[22][1<<17];
double p[22],q[22];
int H[22][22];
int hp[22][1<<17];
double S[1<<17];
double eps=1e-16;
int main() {
//	freopen("5013.in","r",stdin);
//	freopen("5013wa.out","w",stdout);
	int i, j, k;
	int m,n;
	while(~scanf("%d%d",&m,&n)) { //m people n citys
		for(i=0; i<m; i++)scanf("%lf",&p[i]);
		for(i=0; i<m; i++)if(p[i]>eps)p[i]-=eps;
		for(i=0; i<m; i++)for(j=0; j<n; j++)scanf("%d",&H[i][j]);
		for(i=0; i<m; i++)q[i]=1-p[i];
		for(i=0; i<n; i++) {
			hp[i][0]=0;
			for(j=1; j<1<<m; j++) {
				int la=j&(-j);
				int id=__builtin_ctz(la);
				hp[i][j]=hp[i][j^la]+H[id][i];
			}
		}
		P[0]=1,Q[0]=1;
		for(i=1; i<1<<m; i++) {
			int la=i&(-i);
			int id=__builtin_ctz(i);
			P[i]=P[i^la]*p[id];
			Q[i]=Q[i^la]*q[id];
		}
		for(i=0; i<n; i++)for(j=0; j<1<<m; j++)dp[i][j]=0;
		double ans=0;
		int ALL=(1<<m)-1;
		dp[0][ALL]=1;
		for(i=0; i<n; i++) {
			for(j=0; j<1<<m; j++)S[j]=dp[i][j]*Q[j];
			for(j=0; j<m; j++) {
				int host=ALL^(1<<j);
				int sub=host;
				do {
					S[sub]+=S[sub^(1<<j)];
					sub=(sub-1)&host;
				} while(sub!=host);
			}
			for(j=0; j<1<<m; j++)ans+=dp[i][j]*hp[i][j];
			if(i+1<n) {
				for(j=0; j<1<<m; j++)dp[i+1][j]=S[j]*P[j]/Q[j];
				for(j=1,S[0]=0; j<1<<m; j++)S[j]=dp[i][j]*Q[j]/__builtin_popcount(j);
				for(j=0; j<m; j++) {
					int host=ALL^(1<<j);
					int sub=host;
					do {
						S[sub]+=S[sub^(1<<j)];
						sub=(sub-1)&host;
					} while(sub!=host);
				}
				for(j=0; j<1<<m; j++)if(Q[j])ans+=P[j]*__builtin_popcount(j)*hp[i+1][j]*S[j]/Q[j];
			}
		}
		printf("%.8f\n",ans);
	}
	return 0;
}
/*
2 2
1 1
1 3
9 27

70
*/
