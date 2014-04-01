#include<stdio.h>
#define LL long long
int isp[1000010];
LL prime[80000],ptp;
int f(LL x,int l){
//	printf("%lld %d\n",x,l);
	if(x==1)return 0;
	int i;
	for(i=l;i<=ptp;i++)if(x%prime[i]==0){
		printf("    %d\n",prime[i]);
		return 1+f(x/prime[i],i);
		}
	printf("    %lld\n",x);
	return 1;
	}
int main(){
	LL i,j;
	for(i=1;i<=1000000;i++)isp[i]=1;
	for(i=2;i<=500000;i++){
		for(j=2;i*j<=1000000;j++)isp[i*j]=0;
		}
	ptp=0;
	for(i=2;i<=1000000;i++)if(isp[i])prime[++ptp]=i;
	LL n;
//	printf("%lld!\n",ptp);
	while(scanf("%lld",&n)!=EOF&&n>=0){
		f(n,1);
		printf("\n");
		}
	return 0; 
	}
