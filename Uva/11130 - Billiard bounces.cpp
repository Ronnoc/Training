#include<stdio.h>
#include<math.h>
#define PI 3.1415926
double min(double a,double b)
{
	if(a>b)return b;
	else return a;
	}
int f(int x)
{
	if(x%2==0)return x/2;
	}
int main()
{
	double a,b,v,p,s;
	while(scanf("%lf%lf%lf%lf%lf",&a,&b,&v,&p,&s)!=EOF)
	{
		if(a==0 && b==0 && v==0 & p==0 & s==0)break;
		int cy=0,cx=0;double t=0,x=a/2,y=b/2;
		v/=2;
		while(v>=min(a/2,b/2)){v/=2;s*=2;}
		for(t=1;t<=s;t++)
		{
			x+=v*cos(p/180*PI);
			y+=v*sin(p/180*PI);
			if(x>=a){cy++;p=180-p;x=2*a-x;}
			if(x<=0){cy++;p=180-p;x=-x;}
			if(y>=b){cx++;p=-p;y=2*b-y;}
			if(y<=0){cx++;p=-p;y=-y;}
			}
		printf("%d %d\n",cy,cx); 
		}
	return 0;
	}
