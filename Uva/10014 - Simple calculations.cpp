#include<stdio.h>
#define eps 1e-3
double abs(double x){
	if(x>0)return x;
	return -x; 
	}
double a[3010],c[3010];
double aim;
int n;
double progress(){
	int i;
	for(i=2;i<=n+1;i++)a[i]=2*a[i-1]+2*c[i-1]-a[i-2];
	return a[n+1]-aim;
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int i;
		scanf("%lf%lf",&a[0],&aim);
		double l=-1000.0;
		double r=1000.0;
		for(i=1;i<=n;i++)scanf("%lf",&c[i]);
		while(abs(r-l)>eps){
			double m=(l+r)/2;
			double fl,fr,fm;
			a[1]=l;fl=progress();//printf("f(%.2lf)=%.2lf\n",l,fl);
			a[1]=r;fr=progress();//printf("f(%.2lf)=%.2lf\n",r,fr);
			a[1]=m;fm=progress();//printf("f(%.2lf)=%.2lf\n",m,fm);
			if(fr*fm<0)l=m;
			else r=m;
			}
		printf("%.2lf\n",l);
		if(t)printf("\n");
		}
	return 0;
	}
