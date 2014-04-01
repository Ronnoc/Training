#include<stdio.h>
int gcd(int a,int b){
	if(a<b)return gcd(b,a);
	if(b==0)return a;
	return gcd(b,a%b);
	}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int i,res=0;
		for(i=1;i<=n;i++)if(gcd(n,i)==1)res++;
		printf("%d\n",res);
		}
	return 0;
	}
