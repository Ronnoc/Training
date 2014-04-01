#include<stdio.h>
int main()
{
	double n;
	while(scanf("%lf",&n)==1)
	{
		if(n==0)break;
		double i;
		for(i=0;;i++)
		{
			if(i*i*i>n)break;
			}
		i--;
		double s=i+(n-i*i*i)/(3*i*i);
		printf("%.4lf\n",s);
		}
	return 0;
	}
