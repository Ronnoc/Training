#include<stdio.h>
#include<vector>
std::vector<int>L;
int num[1010];
int prime[1010];
int is_p[1010];
bool is_prime(int x){
	int i;
	for(i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
	}
int main(){
	int i;
	for(i=1;i<=1000;i++)is_p[i]=is_prime(i);
	num[0]=0;
	for(i=1;i<=1000;i++)num[i]=num[i-1]+is_p[i];
	L.clear();
	for(i=1;i<1000;i++)if(is_p[i])L.push_back(i);
	int n,c;
	while(scanf("%d%d",&n,&c)!=EOF){
	//	printf("%d\n",num[n]);
		printf("%d %d:",n,c);
		if(num[n]<=2*c){
			for(i=0;i<num[n];i++)printf(" %d",L[i]);
			}
		else {
			if(num[n]&1){
				int m=(num[n]-1)/2;
				for(i=m+1-c;i<=m+c-1;i++)printf(" %d",L[i]);
				}
			else {
				int m=num[n]/2;
				for(i=m-c;i<=m+c-1;i++)printf(" %d",L[i]);
				}
			}
		printf("\n\n");
		}
	return 0;
	}
