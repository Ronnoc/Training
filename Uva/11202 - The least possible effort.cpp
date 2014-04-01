#include<stdio.h>
int f(int x)
{
	if(x%2==1)x+=1;
	return x/2;
	} 
int u(int x)
{
	int i;
	int res=0;
	for(i=1;i<=x;i++)res+=i;
	return res;
	}
int g(int x)
{
	if(x%2==1)x+=1;
	return u(x/2);
	}
int main()
{
	int m,n;
	int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
	scanf("%d%d",&m,&n);if(m!=n)printf("%d\n",f(m)*f(n)); 
	else printf("%d\n",g(m));
		}
	return 0;
	}
