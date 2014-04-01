#include<stdio.h>
#include<math.h>
#define PI M_PI
#define eps 0.000001
int main(){
	double b,h;
	int t;
	scanf("%d",&t);
	while(t--){
		double b,h;
		double A;
		scanf("%lf%lf",&b,&h);
		double B=atan( (b/2)/h );
		double R=0,res=0;
		do{
			res+=2*R;
			R=h*sin(B)/(1+sin(B));
			h-=2*R;
			}while(R>eps);
		printf("%13lf\n",PI*res);
		if(t)printf("\n");
		} 
	return 0;
	}
