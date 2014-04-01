#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		long long k=1,ws=1;
		while(k%n)
		{
			k%=n;
			k*=10;k+=1;
			k%=n;
			ws++;
			}
		printf("%d\n",ws);
		}
	return 0;
	} 
