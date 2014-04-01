#include<stdio.h>
int main()
{
	int max1[7510],max5[7510],max10[7510],max25[7510],max50[7510];
	int i;
	max1[0]=1;max5[0]=1;max10[0]=1;max25[0]=1;max50[0]=1;
	for(i=1;i<=7500;i++)
	{
		max1[i]=max1[i-1];
		}
	for(i=1;i<=7500;i++)
	{
		max5[i]=max1[i];
		if(i>=5)max5[i]+=max5[i-5]; 
		}
	for(i=1;i<=7500;i++)
	{
		max10[i]=max5[i];
		if(i>=10)max10[i]+=max10[i-10]; 
		}
	for(i=1;i<=7500;i++)
	{
		max25[i]=max10[i];
		if(i>=25)max25[i]+=max25[i-25]; 
		}
	for(i=1;i<=7500;i++)
	{
		max50[i]=max25[i];
		if(i>=50)max50[i]+=max50[i-50]; 
		}
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("%d\n",max50[n]);
		}
	return 0;
	} 
