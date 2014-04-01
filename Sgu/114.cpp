#include<stdio.h>
#define N 15010
#define eps 1e-8
int x[N],p[N];
int n;
double abs(double y){if(y>0)return y;return -y;}
double f(double xx){
	double res=0;
	for(int i=1;i<=n;i++)res+=abs(x[i]-xx)*p[i];
	return res;
	}
double Find3(double l,double r){
//	printf("find3(%lf,%lf)\n",l,r);
	double x=r-l;
	if(x<eps)return l;x/=3.0;
	double ll=l+x,rr=r-x;
//	printf("ll=%lf,rr=%lf\n",ll,rr);
	double fll=f(ll),frr=f(rr);
//	printf("fll=%lf,frr=%lf\n\n",fll,frr);
	if(fll<frr)return Find3(l,rr);
	else return Find3(ll,r);
	}
int main(){
	while(scanf("%d",&n)!=EOF){
		int i;
		double max=-1e18,min=1e18;
		for(i=1;i<=n;i++){
			scanf("%d%d",&x[i],&p[i]);
			if(x[i]>max)max=x[i];
			if(x[i]<min)min=x[i];
			}
	//	printf("%lf %lf\n",max,min);
		double res=Find3(min,max);
		printf("%.5lf\n",res);
	//	while(scanf("%lf",&res)!=EOF&&abs(res)>eps)printf("%lf\n",f(res));
		}
	return 0;
	}
