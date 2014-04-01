#include<stdio.h>
#include<string.h>
int min(int a,int b){
	if(a>b)return b;return a;
	}
int dp[110][2];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char s[110];
		scanf("%s",s);
		int len=strlen(s);
		int i;
		dp[0][0]=0;dp[0][1]=1;
		for(int j=0;j<len;j++){
			i=j+1;
			if(s[j]>='a'&&s[j]<='z'){
				dp[i][0]=min(dp[j][0]+1,dp[j][1]+2);
				dp[i][1]=min(dp[j][0]+2,dp[j][1]+2);
				}
			else {
				dp[i][0]=min(dp[j][0]+2,dp[j][1]+2);
				dp[i][1]=min(dp[j][1]+1,dp[j][0]+2);
				}
			}
		printf("%d\n",min(dp[len][0],dp[len][1]+1));
		}
	return 0;
	}
