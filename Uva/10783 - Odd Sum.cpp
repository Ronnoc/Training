#include<stdio.h>
int main()
{
	int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		int i,a,b,temp;
		scanf("%d%d",&a,&b);
		if(a>b){temp=a;a=b;b=temp;}
		printf("Case %d: ",x); 
		int sum=0;
		for(i=a;i<=b;i++)
		{
			if(i%2==1)sum+=i;
			}
		printf("%d\n",sum);
		}
	return 0;
	}
