#include<stdio.h>
#include<math.h>
int main()
{
	int k[320];int i;
	for(i=0;i<=317;i++)k[i]=i*i;
	int a,b;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==0 && b==0)break;
		int count=0;
		for(i=sqrt(a)-1;i<=sqrt(b)+1;i++)
		{
			if(k[i]>=a && k[i]<=b)count++;
			}
		printf("%d\n",count);
		} 
	return 0;
	}
