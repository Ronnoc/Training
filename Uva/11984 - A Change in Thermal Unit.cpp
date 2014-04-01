#include<stdio.h>
int main(){
	double c,d;
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		scanf("%lf%lf",&c,&d);
		d*=5/9.0;
		printf("Case %d: ",k);
		printf("%.2lf\n",c+d);
		}
	return 0;
	}
