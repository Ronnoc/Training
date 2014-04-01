#include<stdio.h>
bool ban[40001][40001];
int main()
{
	int n,m,c;
	while(scanf("%d%d%d",&n,&m,&c)==3 && !(n==0 && m==0 && c==0))
	{
		n=n-7;
		m=m-7;
		int i,j,out=0;
		int s=m*n;
		if(s%2==0)out=s/2;
		else 
		{
			if(c==1) out=(s+1)/2;
			else out=(s-1)/2;
			}
		if(s<0)s=0;
		printf("%d\n",out);
		}
	return 0;}
