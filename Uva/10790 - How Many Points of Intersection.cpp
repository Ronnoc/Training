#include<stdio.h>
#define LL long long
LL C2(LL x){
	return x*(x-1)/2;
	}
int main(){
	LL a,b;
	int t=0;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		if(a==0&&b==0)break;
		printf("Case %d: ",++t);
		printf("%I64d\n",C2(a)*C2(b));
		}
	return 0;
	}
