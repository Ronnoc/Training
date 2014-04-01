#include<stdio.h>
#include<math.h>
#define LL long long
int main(){
	LL n;
	int z=0;
	while(scanf("%lld",&n)!=EOF&&n){
		LL res=(3+sqrt(8*n+9))/2;
		while(res*(res-1)/2-res<n)res++;
		printf("Case %d: ",++z);
		printf("%lld\n",res);
		}
	return 0;
	}
