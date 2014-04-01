#include<stdio.h>
#include<math.h>
int main()
{
	int h,m;
	while(scanf("%d:%d",&h,&m)==2)
	{
		if(h==0 && m==0)break;
		double res,hh=h,mm=m;
		double amm=mm*6;
		double ahh=hh*30;
		ahh+=mm/2;
		res=ahh-amm; 
		if(res<0)res=-res;
		if(res>180)res=360-res;
		printf("%.3lf\n",res); 
		}
	
	return 0;
	} 
