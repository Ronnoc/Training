#include<stdio.h>
int main()
{
	int s[62];
	int i;
	for(i=0;i<=59;i++)s[i]=i*i*i;
	int z,j;
	bool flag[10010];int big[10010],small[10010];
	for(i=1;i<=10009;i++){flag[i]=0,big[i]=0,small[i]=0;}
	for(i=59;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			int p=s[i]-s[j];
			if(p>0 && p<=10001){flag[p]=1;big[p]=i;small[p]=j;}
			}
		}
	while(scanf("%d",&z)==1 && z!=0)
	{
		if(flag[z])printf("%d %d\n",big[z],small[z]);
		else printf("No solution\n");
		}
	return 0;
	}
