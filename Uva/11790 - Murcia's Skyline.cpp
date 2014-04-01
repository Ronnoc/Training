#include<stdio.h>
#define SMAX 10010
int a[SMAX],val[SMAX];
int dp[SMAX],w[SMAX];
int max(int a,int b){
	if(a>b)return a;return b;
	}
int main(){
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)scanf("%d",&val[i]);
		int j;
		for(i=1;i<=n;i++){
			dp[i]=1;
			w[i]=val[i];
			for(j=1;j<i;j++)if(a[i]>a[j]&&w[i]<w[j]+val[i]){
				dp[i]=dp[j]+1;
				w[i]=w[j]+val[i];
				}
			}
		int inc=0;
		for(i=1;i<=n;i++)inc=max(inc,w[i]);
		
		for(i=1;i<=n;i++){
			dp[i]=1;
			w[i]=val[i];
			for(j=1;j<i;j++)if(a[i]<a[j]&&w[i]<w[j]+val[i]){
				dp[i]=dp[j]+1;
				w[i]=w[j]+val[i];
				}
			}
		int dec=0;
		for(i=1;i<=n;i++)dec=max(dec,w[i]);
		if(inc>=dec)printf("Case %d. Increasing (%d). Decreasing (%d).\n",k,inc,dec);
		else printf("Case %d. Decreasing (%d). Increasing (%d).\n",k,dec,inc);
		}
//	return main();
	return 0;
	}
