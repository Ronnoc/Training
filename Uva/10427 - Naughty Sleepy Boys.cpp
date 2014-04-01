#include<stdio.h>
int ten(int i)
{
	int j;int res=1;
	for(j=2;j<=i;j++)res*=10;
	return res;
	}
int f(int num,int k)
{
	int i,temp;
	for(i=1;i<=k;i++)
	{
		temp=num%10;
		num/=10;
		}
	return temp;
	}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		int num=0;
		int k=1,i;
		for(i=1;i<=10;i++)
		{
			if(n>ten(i)*i*9)n-=ten(i)*i*9;
			else break;
			}
		int ws=i;
		n+=ws-1;
		num=n/ws+ten(ws)-1;
		k+=n%ws;k=ws-k+1; 
	//	printf("%d\t%d\t%d\t%d\n",num,n,ws,k);
		printf("%d\n",f(num,k));
		}
	return 0;
	}
