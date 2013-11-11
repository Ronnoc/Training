//kybconnor
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define SQ(x) ((x)*(x))
double xx,yy,dx,dy;
double x[44],y[44];
double cnt(double X,double Y){
	double ret=0;
	for(int i=0;i<=3;i++)ret+=sqrt(SQ(X-x[i])+SQ(Y-y[i]));
	return ret;
}
double solve(){
	double l0=-2000,r0=2000;
	int T=100;
	while(T--){
		double lr=r0-l0;
		lr/=3.0;
		double lmid=l0+lr;
		double rmid=r0-lr;
		double fl=cnt(xx+dx*lmid,yy+dy*lmid);
		double fr=cnt(xx+dx*rmid,yy+dy*rmid);
		if(fl>fr)l0=lmid;
		else r0=rmid;
	}
	return cnt(xx+dx*l0,yy+dy*l0);
}
int main() {
	while (~scanf ("%lf%lf",&x[0],&y[0])) {
		int i,j;
		for (i=1; i<=3; i++) scanf ("%lf%lf",&x[i],&y[i]);
		int flag=0;
		for (i=0; i<=3; i++) if (x[i]==-1) flag=1;
		for (i=0; i<=3; i++) if (y[i]==-1) flag=1;
		if (flag) break;
		double dis=cnt(x[0],y[0]);
		for (i=0; i<=3; i++) {
			double tp=cnt(x[i],y[i]);
			dis=min (dis,tp);
		}
		for (i=0; i<=3; i++) for (j=0; j<=3; j++) {
				xx=x[i];
				yy=y[i];
				dx=x[j]-x[i];
				dy=y[j]-y[i];
				double temp=sqrt(SQ(dx)+SQ(dy));
				if(fabs(temp)<1e-8)continue;
				dx/=temp;
				dy/=temp;
				dis=min(dis,solve());
			}
		printf ("%.4lf\n",dis+1e-8);
	}
	return 0;
}
//0 0 0 1 1 2 129 1
//0 0 1 0 2 0 1 3
//0 0 5 1 6 0 4 4
