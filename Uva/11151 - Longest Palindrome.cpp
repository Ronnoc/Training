#include<stdio.h>
#include<string.h>
char a[1010],b[1010];
int dp[1010][1010];
int max(int a,int b){
	if(a>b)return a;return b;
	}
int main(){
	int t;
	scanf("%d%*c",&t);//gets(b);
	while(t--){
		int i,j=0;
		gets(a);
		int len=strlen(a);
		for(i=len-1;i>=0;i--)b[j++]=a[i];
		for(i=0;i<len;i++)for(j=0;j<len;j++)dp[i][j]=0;
		for(i=0;i<len;i++){
			for(j=0;j<len;j++){
				if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;
				else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
				}
			}
		printf("%d\n",dp[len][len]);
		}
	return 0;
	}
