#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main(){
	int T,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		double x,y;
		scanf("%lf%lf",&x,&y);
		double r=sqrt(x*x+y*y);
		double S=PI*r*r/2;
		int res=S/50;
		if(res*50<S-1e-8)res++;
		printf("Property %d: This property will begin eroding in year %d.\n",t,res);
		}
	printf("END OF OUTPUT.\n");
	return 0;
	} 
