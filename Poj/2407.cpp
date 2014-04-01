#include<stdio.h>
#define ULL unsigned long long
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int i,tp=n;
		ULL res=n;
		for(i=2;i<=n;i++){
			while(n%i==0){
				res*=(i-1);
				res/=i;
				while(n%i==0)n/=i;
				}
			}
		printf("%I64u\n",res);
		}
	return 0;
	}
