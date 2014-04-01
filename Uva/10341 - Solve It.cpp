#include<stdio.h>
#include<math.h>
int p,q,r,s,t,u;
double eps=0.00000000001;
double f(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;	
	}
int main()
{
	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		double head=0,tail=1,body;
		int i;
		int flag=0;
		double x=f(head),y=f(tail);
		if(x*y>eps)flag=1;
		else
		for(i=1;head+eps<tail;i++)
		{
			body=(head+tail)/2;
		//	printf("i=%d\n",i);
		//	printf("%.4lf %.4lf %.4lf\n",head,body,tail);
		//	printf("%.4lf %.4lf %.4lf\n",f(head),f(body),f(tail));
			double temp=f(body);
			x=f(head),y=f(tail);
			if(x*temp>eps)head=body;
			else tail=body;
			}
		body=(head+tail)/2;
		if(flag)printf("No solution\n");
		else printf("%.4lf\n",body);
		}
	return 0;
	}
