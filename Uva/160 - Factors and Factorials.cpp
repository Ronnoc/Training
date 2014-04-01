#include<stdio.h>
int map[110][110];
int kth_prime[110];
int is_prime(int a){
	int i;
	for(i=2;i*i<=a;i++)if(a%i==0)return 0;
	return 1;
	}
int main(){
	int i,j;
	int pk=0;
	for(i=2;i<=100;i++){
		if(is_prime(i)){
			pk++;
			kth_prime[i]=pk;
			}
		else kth_prime[i]=0;
		}
	for(i=1;i<=100;i++)for(j=1;j<=pk;j++)map[i][j]=0;
	for(i=2;i<=100;i++){
		for(j=1;j<=pk;j++)map[i][j]=map[i-1][j];
		int x=i;
		for(j=1;j<=100;j++){
			if(kth_prime[j]){
				if(x!=0&&x!=1&&x%j==0){
					x/=j;
					map[i][ kth_prime[j] ]++;
					j--;
					}
				}
			if(x==1)break;
			}
		}
	int n;
	while(scanf("%d",&n)!=EOF&&n>1){
		printf("%3d! =",n);
		for(j=1;j<=pk;j++){
			if(map[n][j]){
				if(j==16)printf("\n      ");
				printf("%3d",map[n][j]);
				}
			else break;
			}
		printf("\n");
		}
	return 0;
	}
