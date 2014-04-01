#include<stdio.h>
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int res;
		if(m==0&&n==0)break;
		if(m*n==0)res=0;
		else if(m>=3&&n>=3)
		{
			if(m*n%2==0)res=m*n/2;
			else res=(m*n+1)/2;
			}
		else if(m==1)res=n;
		else if(n==1)res=m;
		else if(m==2)
		{
			if(n==2)res=4;
			else if(n%4==1)res=2+(n-1);
			else if(n%4==3)res=m*(n+1)/2;
			else if(n%4==2)res=4+(n-2);
			else res=n;
			}
		else if(n==2)
		{
			if(m==2)res=4;
			else if(m%4==1)res=2+(m-1);
			else if(m%4==3)res=n*(m+1)/2;
			else if(m%4==2)res=4+(m-2);
			else res=m;
			}
		printf("%d knights may be placed on a %d row %d column board.\n",res,m,n);
		res=0;
		}
	return 0;
	}
