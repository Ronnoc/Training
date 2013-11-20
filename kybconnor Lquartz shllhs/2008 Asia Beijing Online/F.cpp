//kybconnor
#include <cstdio>
#include <cstring>
#define LL long long
LL dp[1010][1010];
LL str[1010][1010];
const LL mod = 1000000007;
int n,r,k,m;
int main() {
	int i,j;
	for (i=0; i<=1000; i++) str[0][i]=0;
	for (i=0; i<=1000; i++) str[i][0]=0;
	for (i=1; i<=1000; i++) {
		str[i][1]=1;
		for (j=2; j<=i; j++) str[i][j]= (j*str[i-1][j]+str[i-1][j-1]) %mod;
	}
	while (~scanf ("%d%d%d%d",&n,&r,&k,&m)) {
		for (i=0; i<=n; i++) for (j=0; j<=r; j++)
				dp[i][j]=0;
		for (i=1; i<=n; i++) dp[i][1]=i;
		for (i=2; i<=r; i++) {
			for (j=1; j<=n; j++) {
				dp[j][i]=dp[j-1][i];
				if (j>k) dp[j][i]+=dp[j-k][i-1];
				dp[j][i]%=mod;
			}
//			for(j=1;j<=n;j++)printf("%I64d ",dp[j][i]);
//			printf("\n");
		}
		LL left=dp[n][r];
		LL right=0;
		for (i=1; i<=m; i++) right= (right+str[r][i]) %mod;
//		printf ("%I64d * %I64d :",left,right);
		LL res=left*right%mod;
		printf ("%I64d\n",res);
	}
	return 0;
}
