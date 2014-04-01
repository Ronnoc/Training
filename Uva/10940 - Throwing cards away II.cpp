#include<stdio.h>
int b[500001];
int f(int bi,int i)
{
	if(bi<=i-2)return bi+2;
	else if(bi==i-1)return 2;
	}
int main()
{
	int i,j,n;
	b[1]=1;b[2]=2;
	for(i=3;i<=500000;i++)
	{
		b[i]=f(b[i-1],i);
		//printf("b[%d]=%d\n",i,b[i]);
		}
	while(scanf("%d",&n)==1 && n!=0)
	{
		printf("%d\n",b[n]);
		}
	
	return 0;
	}
