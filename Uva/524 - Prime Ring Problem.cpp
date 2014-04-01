#include<stdio.h>
int num[20];		//表示第几位置是什么 
bool isp[40];
int n;
bool isprime(int x){
	int i;
	for(i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
	}
bool place(int k){
	int i;
	for(i=1;i<k;i++){
		if(num[i]==num[k])return 0;
		}
	if(k==n){
		if(!isp[ num[n]+num[1] ])return 0;
		}
	if(k>=2)if(!isp[ num[k]+num[k-1] ])return 0;
	return 1;
	}
void op(int s){
	int i;
	if(s>n){
		int flag=1;
		for(i=1;i<=n;i++){
			if(flag)flag=0;
			else printf(" ");
			printf("%d",num[i]);
			}
		printf("\n");
		}
	else {
		for(i=2;i<=n;i++){
			num[s]=i;
			if(place(s))op(s+1);
			}
		}
	}
int main(){
	int k=0;
	int i;
	for(i=1;i<=32;i++)isp[i]=isprime(i);
	while(scanf("%d",&n)!=EOF){
		if(k!=0)printf("\n");
		++k;
		printf("Case %d:\n",k);
		num[1]=1;
		op(2);
		}
	return 0;
	}
