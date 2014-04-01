#include<stdio.h>
int main()
{
	int n;
	int a[110];
	int i,t;
	
	while(scanf("%d",&n)==1 && n)
	{
		for(i=1;i<=100;i++)a[i]=0;
		for(i=1;i<=n;i++){scanf("%d",&t);a[t]++;}
		int j,fr=1;
		for(i=1;i<=100;i++)
		{
			for(j=0;j<a[i];j++)
			{
				if(fr)fr=0;
				else printf(" ");
				printf("%d",i);
				}
			}
		for(i=1;i<=100;i++)a[i]=0;
		printf("\n");
		}
return 0;	
	}
