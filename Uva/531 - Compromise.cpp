#include<stdio.h>
#include<string.h>
char a[110][40],bt[110][40];
int dp[110][110];
char b[110][110];
int first=1;
int bf(int p,int q)
{
	if(p==0||q==0)return 0;
//	printf("bf %d %d\n",p,q);
	if(b[p][q]=='f')
	{
		bf(p-1,q-1);
		if(first)first=0;
		else printf(" ");
		printf("%s",bt[q]);
		}
	else if(b[p][q]=='g')bf(p,q-1);
	else bf(p-1,q);
	}
int main()
{
	int i=1,j=1,m,n;
while(scanf("%s",a[1])!=EOF) 
{
	i=2;j=1;first=1;
	while(1)
	{
		scanf("%s",a[i]);
		if(strlen(a[i])==1&&a[i][0]=='#')
		{
			m=i-1;
			break;
			}
		i++;
		}
//	puts(a[m]);
	while(1)
	{
		scanf("%s",bt[j]);
		if(strlen(bt[j])==1&&bt[j][0]=='#')
		{
			n=j-1;
			break;
			}
		j++;
		}
//	puts(bt[n]);
	for(i=0;i<=m;i++)for(j=0;j<=n;j++)dp[i][j]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(strcmp(a[i],bt[j])==0)
			{
				dp[i][j]=dp[i-1][j-1]+1;
				b[i][j]='f';
				}
			else if(dp[i-1][j]>dp[i][j-1])
			{
				dp[i][j]=dp[i-1][j];
				b[i][j]='v';
				}			
			else 
			{
				dp[i][j]=dp[i][j-1];
				b[i][j]='g';
				}
			}
		}
	bf(m,n);
	printf("\n");
}	
//	return main();
	return 0;
	}
