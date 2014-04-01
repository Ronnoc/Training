#include<stdio.h>
#include<algorithm>
#define LL long long
LL a[1000011];
LL c[1000011];
LL abs(LL a){
	if(a>0)return a;
	return -a;
	}
int main(){
	LL n;
	while(scanf("%lld",&n)!=EOF&&n){
		int i;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		LL ev=0;
		for(i=1;i<=n;i++)ev+=a[i];
		ev/=n;
		c[1]=0;
		for(i=2;i<=n;i++)c[i]=c[i-1]+a[i-1]-ev;
		std::sort(c+1,c+n+1);
		LL x=c[n/2+1];
		LL res=0;
		for(i=1;i<=n;i++)res+=abs(x-c[i]);
		printf("%lld\n",res);
		}
	return 0;
	}
