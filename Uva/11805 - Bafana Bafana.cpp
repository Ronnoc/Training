#include<stdio.h>
int main()
{
	int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		int n,k,p;
		scanf("%d%d%d",&n,&k,&p);
		int s=(k+p)%n;
		if(s==0)s=n;
		printf("Case %d: %d\n",x,s);
		}
	return 0;
	} 
