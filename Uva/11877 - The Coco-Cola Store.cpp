#include<stdio.h>
int f(int x)
{
	if(x==2)return 3;
	if(x<=1)return x;
	return 3+f(x-2);
	} 
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n==0)break;
		printf("%d\n",f(n)-n);
		}
	return 0;
	}
