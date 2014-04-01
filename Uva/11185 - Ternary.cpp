#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n<0)break;
		int a[1000],pa=0;
		int y=n,i;
		while(y){
			a[++pa]=y%3;
			y/=3;
			}
		for(i=pa;i>=1;i--)printf("%d",a[i]);
		if(n==0)printf("0");
		printf("\n");
		}
	return 0;
	}
