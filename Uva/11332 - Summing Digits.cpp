#include<stdio.h>
int f(int x)
{
	if(x<10)return x;
	int sum=0,t=x,i;
	for(i=1;i<=10;i++)
	{
		sum+=t%10;
		t/=10;
		}
	return f(sum);
	}
int main()
{
	int n;
	while(scanf("%d",&n)==1 && n!=0)
	{
		printf("%d\n",f(n));
		}
	return 0;
	} 
