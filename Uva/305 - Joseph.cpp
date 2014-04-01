#include<stdio.h>
int Josephus(int n,int m){
	int i,j;
	int ok[1600];
	for(i=1;i<=n;i++)ok[i]=0;
	int count=1,start=1;
	for(i=1;i<=n/2;i++){
		int j;
		int sum=0;
		for(j=1;j<=n;j++)if(!ok[j])sum++;
		int t=(m-count)/sum;
		count+=t*sum;
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
		for(j=1;j<=n/2;j++)if(ok[j])return 0;
		}
	return 1;
	}
int main(){
//	freopen("305db.txt","w",stdout);
	int dp[16];
	int i,j;
	for(i=1;i<14;i++){
		dp[i]=-1;
		for(j=i;;j++){
			if(Josephus(2*i,j)){
				dp[i]=j;
				break;
				}
			}
	//	printf("dp[%d]=%d;\n",i,dp[i]);
		}
	int n;
	//while(scanf("%d",&n)!=EOF&&n)printf("%d\n",dp[n]);
	return 0;
	}
/*
#include<stdio.h>
int main(){
int dp[20];
dp[1]=2;
dp[2]=7;
dp[3]=5;
dp[4]=30;
dp[5]=169;
dp[6]=441;
dp[7]=1872;
dp[8]=7632;
dp[9]=1740;
dp[10]=93313;
dp[11]=459901;
dp[12]=1358657;
dp[13]=2504881;
int n;
while(scanf("%d",&n)!=EOF&&n)printf("%d\n",dp[n]);
return 0;
}*/
