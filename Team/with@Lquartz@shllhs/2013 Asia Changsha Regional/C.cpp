//shllhs
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define eps 1e-10
using namespace std;
double ox (double x1,double y1,double x2,double y2) {
	return x1*x2+y1*y2;
}
double xx (double x1,double y1,double x2,double y2) {
	return x1*y2-x2*y1;
}
int main() {
	double r1,r2,r3,x,y,vx,vy;
	while (scanf ("%lf%lf%lf%lf%lf%lf%lf",&r1,&r2,&r3,&x,&y,&vx,&vy) !=EOF) {
		double v = sqrt (vx*vx+vy*vy);
		if (ox (-x,-y,vx/v,vy/v) <eps) {
			printf ("0.000\n");
			continue;
		}
		double h = fabs (xx (-x,-y,vx/v,vy/v));
		double rr = sqrt (x*x+y*y);
		if (h>r2+r3+eps) {
			printf ("0.000\n");
			continue;
		}
		double l1 = 2.0* (r2+r3) *sqrt (1.0 - h*h/ ( (r2+r3) * (r2+r3))) /v;
		if (h>r1+r3+eps) {
			printf ("%.4lf\n",l1);
			continue;
		} else {
			double l2 = 2.0* (r1+r3) *sqrt (1.0 - h*h/ ( (r1+r3) * (r1+r3))) /v;
			printf ("%.4lf\n",l1-l2);
			continue;
		}
	}
	return 0;
}
