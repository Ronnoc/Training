#include<stdio.h>
#include<math.h>
int dp[2200];
int f[2200];
int main(){
	int i,j;
	f[1959]=2;
	for(i=1960;i<=2160;i++){
		if(i%10!=0)f[i]=f[i-1],dp[i]=dp[i-1];
		else {
			f[i]=2*f[i-1];
			double res=0;
			double max=f[i]*log(2);
			for(j=1;res<=max;j++)res+=log(j);
			j--;j--;
			dp[i]=j;
			}
		}
	int n;
	while(scanf("%d",&n)!=EOF&&n)printf("%d\n",dp[n]);
	return 0;
	}
