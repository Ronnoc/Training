#include<stdio.h>
int main()
{
	int n; 
	while(scanf("%d",&n)!=EOF && n)
	{
		int a[1010],j=1,b[1010],i;
		for(i=1;i<=1000;i++)b[i]=0;
		for(i=1;i<=n;i++){scanf("%d",&a[i]);if(a[i]!=0)b[j++]=a[i];}
		printf("%d",b[1]);
		for(i=2;i<=j-1;i++)
		{
			printf(" %d",b[i]);
			}
		printf("\n");
		}
	return 0; 
	}
