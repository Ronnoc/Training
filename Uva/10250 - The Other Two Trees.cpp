#include<stdio.h>
int main(){
	double x1,y1,x2,y2;
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF){
		double x0=(x1+x2)/2,y0=(y1+y2)/2;
		double px=x1-x0,py=y1-y0;
		double qx=py,qy=-px;
		printf("%lf %lf %lf %lf\n",x0+qx,y0+qy,x0-qx,y0-qy); 
		}
	return 0;
	}
