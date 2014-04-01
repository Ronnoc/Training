#include<stdio.h>
int f(int a,int b)
{
	int s=b-a;
	if(a>b)s=40-a+b;
	return s*9;
	}
int g(int a,int b)
{
	int s=a-b;
	if(a<b)s=40-b+a;
	return s*9;
	}
int main()
{
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)==4 && !(a==0 && b==0 && c==0 && d==0))
	{
		printf("%d\n",1080+g(a,b)+f(b,c)+g(c,d));
		}
	return 0;
	}
