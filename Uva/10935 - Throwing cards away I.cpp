#include<stdio.h>
int len;
int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		int a[200],i,top=1,down=n,fi=1;
		for(i=1;i<=n;i++)a[i]=i;
		printf("Discarded cards:");
		for(i=1;;i++)
		{
			if(down==top)break;
			if(fi)fi=0;else printf(",");
			printf(" %d",a[top]);
			top++;
			a[down+1]=a[top];
			top++;
			down++; 
			}
		printf("\nRemaining card: %d\n",a[top]);
		}
	return 0;
	}
