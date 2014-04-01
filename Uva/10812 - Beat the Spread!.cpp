#include<stdio.h>
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		long long a,b;
		scanf("%lld%lld",&a,&b);
		if(a<b)printf("impossible\n");
		else if((a-b)%2==1)printf("impossible\n");
		else printf("%lld %lld\n",(a+b)/2,(a-b)/2);
		}
	return 0;
	} 
