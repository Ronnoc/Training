#include<stdio.h>
#define MAX 1000000 +10
int sum[MAX];
int isp[100];
int is_prime(int x){
	int i;
	if(x==1)return 0;
	for(i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
	}
int check(int x){
	int a=0;
	int y=x;
	while(y){
		a+=y%10;y/=10;
		}
	if(isp[a])return is_prime(x);
	return 0;
	}
int main(){
	int i;
	for(i=1;i<=60;i++)isp[i]=is_prime(i);
	sum[0]=0;
	for(i=1;i<1000000;i++)sum[i]=sum[i-1]+check(i);
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		printf("%d\n",sum[m]-sum[n-1]); 
		}
	return 0;
	}
