#include<stdio.h>
int a[2010];
int dpa[2010],dpb[2010];
int Dp[2010];
int n;
int max(int a,int b){
	if(a>b)return a;return b;
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int i,j;
		for(i=0;i<n;i++)scanf("%d",&a[n-1-i]);
		for(i=0;i<n;i++){
			dpa[i]=1;
			for(j=0;j<i;j++)if(a[i]>a[j])dpa[i]=max(dpa[i],dpa[j]+1);
			}
		for(i=0;i<n;i++){
			dpb[i]=1;
			for(j=0;j<i;j++)if(a[i]<a[j])dpb[i]=max(dpb[i],dpb[j]+1);
			}
		for(i=0;i<n;i++)Dp[i]=dpa[i]+dpb[i]-1;
	//	for(i=0;i<n;i++)printf("%d ",dpa[i]);printf("\n");
	//	for(i=0;i<n;i++)printf("%d ",dpb[i]);printf("\n");
	//	for(i=0;i<n;i++)printf("%d ",Dp[i]);printf("\n");
		int res=0;
		for(i=0;i<n;i++)res=max(res,Dp[i]);
		printf("%d\n",res);
		}
//	return main();
	return 0;
	}
