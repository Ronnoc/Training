#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int z;
	for(z=1;z<=n;z++)
	{
		int m;
		scanf("%d",&m);
		int a[60];
		int i,temp;
		for(i=1;i<=m;i++)scanf("%d",&a[i]);
		int j;int count=0;
		for(j=1;j<=m*m;j++)
		{
			for(i=1;i<m;i++)
			{
				if(a[i]>a[i+1])
				{
					count++;
					temp=a[i];a[i]=a[i+1];a[i+1]=temp;
					}
				}
			}
		printf("Optimal train swapping takes %d swaps.\n",count);		
		}
	return 0;
	} 
