#include<stdio.h>
int main()
{
	int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		int n;
		scanf("%d",&n);
		printf("Case %d:",x);
		int i;
		for(i=1;i*i<n;i++);i--;
		for(;i>=1;i--)
		{
			if(n%i==0)printf(" %d",n-i*i);
			}
		printf("\n");
		}
	return 0;
	} 
