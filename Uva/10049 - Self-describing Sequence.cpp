#include<stdio.h>
int dp[6800010];
int main()
{
	int i,j;
	dp[1]=1;dp[2]=2;
	j=2;
	int s=1;
	for(i=3;i<=6800000;i++)
	{
		if(s<dp[j]){dp[i]=j;s++;}
		else {j++;s=1;dp[i]=j;}
		}
//	for(i=1;i<=20;i++)printf("%4d",i);printf("\n");
//	for(i=1;i<=20;i++)printf("%4d",dp[i]);printf("\n");
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int sum=0;
		i=1;
		while(sum<n)
		{
			//printf("!");
			sum+=dp[i];
			i++;
			}
		i--;
		printf("%d\n",i);
		}
	return 0;
	}
