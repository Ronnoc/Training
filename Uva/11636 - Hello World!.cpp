#include<stdio.h>
int main()
{
	int n;int count=0;
	while(scanf("%d",&n)==1)
	{
		printf("Case %d: ",++count);
		if(n<0)break;
		if(n==1){printf("0\n");continue;}
		int i,k=1;
		int res=1;
		while(!(res<= n && 2*res>=n))
		{
			res*=2;k++; 
			} 
		printf("%d\n",k);
		}
	return 0;
	} 
