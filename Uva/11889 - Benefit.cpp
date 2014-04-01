#include<stdio.h>
#define LL long long
int isp[1000010];
int prime[80000],tp=0;
int is_prime(int x){
	int i;
	for(i=2;i*i<=x;i++)if(x%i==0)return 0;
	prime[++tp]=x;
	return 1;
	}
int gcd(int a,int b){
	int t;
	for(;t=b;b=a%b,a=t);
	return a;
	}
int lcm(int a,int b){
	int res=a/gcd(a,b);
	return res*b;
	}
int main(){
	int t;
	scanf("%d",&t);
	int i;
	for(i=2;i<=1000000;i++)is_prime(i);
	while(t--){
		int a,c;
		scanf("%d%d",&a,&c);
		if(c%a!=0){
			printf("NO SOLUTION\n");
			continue;
			}
		else {
			int d=c/a;
			for(i=1;i<=a;i++){
				if(a%i!=0)continue;
				if(lcm(d*i,a)==c){
					printf("%d\n",d*i);
					break;
					}
				}
			}
		}
	return 0;
	}
