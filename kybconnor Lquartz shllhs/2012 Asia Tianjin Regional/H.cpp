//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#define eps 1e-7
using namespace std;
int main() {
	int t,i,j;
	double x,y,p,q;
	scanf ("%d",&t);
	while (t--) {
		scanf ("%lf%lf%lf%lf",&x,&y,&p,&q);
		double a = q* (p*x+p*y) + (1.0-q) *x;
		double b = q*y+ (1.0-q) * (p*x+p*y);
		if (a>b+eps) printf ("tiger ");
		else printf ("wolf ");
		printf ("%.4lf\n",max (a,b));
	}
	return 0;
} s
