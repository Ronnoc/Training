#include<stdio.h>
int k[10010];
int res[10010];
int main()
{
	int n,q;
	int c=1;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		if(n==0 && q==0)break;
		int i,j,t;
		for(i=1;i<=10000;i++)k[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&t);
			k[t]++;
			}
		res[1]=1;
		for(i=2;i<=10001;i++)
		{
			res[i]=res[i-1]+k[i-1];
			}
		printf("CASE# %d:\n",c);c++;
		for(i=1;i<=q;i++)
		{
			scanf("%d",&t);
			if(res[t]==res[t+1])printf("%d not found\n",t);
			else printf("%d found at %d\n",t,res[t]);
			}
		}
	return 0;
	}
