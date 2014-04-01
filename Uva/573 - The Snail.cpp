#include<stdio.h>
int main()
{
	double h,u,d,f;		//h是目标高度，u是第一天的高度，d是每天晚上掉下来的高度，f是消极比例 
	while(scanf("%lf%lf%lf%lf",&h,&u,&d,&f)==4)
	{
		if(h==0)break;
		int date=1;int flag=0;
		double h0=h;h=0;
		for(date=1;;date++)
		{
			//printf("day %d high %.2lf up %.2lf down %.2lf\n",date,h,(1-((date-1)*f/100))*u,d);
			if((date-1)*f<=100)h+=(1-((date-1)*f/100))*u;
			if(h>h0){flag=1;break;}
			h-=d;
			if(h<0)break;
			}
		if(flag)printf("success on day %d\n",date);
		else printf("failure on day %d\n",date);
		}
		return 0;
	}
