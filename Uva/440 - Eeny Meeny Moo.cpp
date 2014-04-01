#include<stdio.h>
int Josephus(int n,int m){
	int i,j;
	int ok[160];
	for(i=1;i<=n;i++)ok[i]=0;
	int count=m,start=1;
	for(i=1;i<n;i++){
		int j;
		for(j=start;;j++){
			if(j>n)j-=n;
			if(!ok[j]){
				if(count==m){
					start=j+1;
					ok[j]=1;
					count=1;
					break;
					}
				else count++;
				}
			}
		if(ok[2])return 0;
		}
	return 1;
	}
int main(){
	int dp[160];
	int i,j;
	for(i=3;i<=150;i++){
		for(j=1;;j++){
		//	printf("%d %d\n",i,j);
			if(Josephus(i,j)){
				dp[i]=j;
				break;
				}
			}
		}
	int n;
	while(scanf("%d",&n)!=EOF&&n)printf("%d\n",dp[n]);
	return 0;
	}
