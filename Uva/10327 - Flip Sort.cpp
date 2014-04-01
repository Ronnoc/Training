#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[1010],i,j,t,res=0;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(j=1;j<=n;j++)
		{
			for(i=1;i<=n-1;i++)
			{
				if(a[i]>a[i+1])
				{
					t=a[i];a[i]=a[i+1];a[i+1]=t;res++;
					}
				}
			}
		printf("Minimum exchange operations : %d\n",res);
		}
	return 0;
	
	}
