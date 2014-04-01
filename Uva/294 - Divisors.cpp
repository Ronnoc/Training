#include<stdio.h>
int s(int x)
{
	int i;int count=0;
	for(i=1;i*i<x;i++)
	{
		if(x%i==0)count++;
		}
	count*=2;
	if(i*i==x)count++;
	return count;
	}
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		int l,u,max;
		scanf("%d%d",&l,&u);
		int i;
		max=l;
		int c[10010];
		for(i=l;i<=u;i++)
		{c[i-l]=s(i);if(c[i-l]>c[max-l])max=i;}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,u,max,c[max-l]);
		}
	 return 0;
	} 
