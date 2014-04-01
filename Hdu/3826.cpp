#include<stdio.h>
#include<math.h>
#define LL long long	
int main(){
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		LL i,n;
		int flag=1;
		scanf("%I64d",&n);
		printf("Case %d: ",k);
		if(n==1){
			printf("Yes\n");
			continue;
			}
		for(i=1;i*i*i<=n;i++){
			if(n%i==0){
				n/=i;
				if(n%i==0&&i!=1){
					flag=0;
					break;
					}
				}
			if(flag){
				double p=sqrt((double)n);
				if(floor(p+0.5)==p)flag=0;
				if(!flag)break;
				}
			}
		if(flag)printf("Yes\n");
		else printf("No\n");
		}
	return 0;
	}
