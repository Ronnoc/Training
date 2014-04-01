#include<stdio.h>
unsigned long long d[1000010];
int main()
{
	unsigned long long i;
	d[0]=0;
	for(i=1;i<=1000010;i++)d[i]=i*(i-1);
	unsigned long long m,n;
	while(scanf("%llu%llu",&m,&n)==2)
	{
		if(m==0 && n==0)break;	
		unsigned long long res=0;
		res+=n*d[m];
		res+=m*d[n];
		unsigned long long min=m>n?n:m;
		unsigned long long max=m+n-min;
		for(i=1;i<min;i++)
		{
			//printf("%d+=%llu",res,d[i]);
			res+=4*d[i];
		}
		res+=((max-min)+1)*2*d[min];
		printf("%llu\n",res);
		}
	return 0;}
