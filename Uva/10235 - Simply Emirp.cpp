#include<stdio.h>
int dp[1000010];
int isp[1000010];
int f(int x){
	int i;
	int res=0;
	while(x>0){
		res*=10;
		res+=x%10;
		x/=10;
		}
	return res;
	}
int is_prime(int x){
	int i;
	for(i=2;i*i<=x;i++){
		if(x%i==0)return 0; 
		}
	return 1;
	}
int main(){
/*	int i;
	for(i=2;i<=1000000;i++)isp[i]=is_prime(i);
	for(i=2;i<=1000000;i++){
		if(isp[i]){
			if(isp[f(i)])dp[i]=2;
			else dp[i]=1;
			}
		else dp[i]=0;
		}*/
	int n;
	while(scanf("%d",&n)!=EOF){
		if(is_prime(n)&&is_prime(f(n))&&f(n)!=n)printf("%d is emirp.\n",n);
		else if(is_prime(n))printf("%d is prime.\n",n);
		else printf("%d is not prime.\n",n);
		}
	return 0;
	}
