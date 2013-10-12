#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
double x[222],y[222];
const double PI = acos(-1);
int n;
void play(double a1,double a2,double b1,double b2,double &r1,double &r2)
{	//(a1+a2i)*(b1+b2i)=r1+r2i,
	r1=a1*b1-a2*b2;
	r2=a1*b2+a2*b1;
}
double rx[222],ry[222];
double qx[222],qy[222];
double sx[222],sy[222];
void wa(double x){
	char s[22];
	sprintf(s,"%lf",x);
	if(strcmp(s,"-0.000000")==0)
		printf("0.000000");
//	else if(-x<1e10&&x<1e-10)
//		printf("0.000000");
	else printf("%lf",x);
}
int main(){
	while(~scanf("%d",&n)){
		double rotX,rotY;
		rotX=cos(2.0*PI/n);
		rotY=sin(2.0*PI/n);
		double ROTx,ROTy;
		ROTx=cos(-2.0*PI/n);
		ROTy=sin(-2.0*PI/n);
		int l,r;
		scanf("%d%d",&l,&r);
		scanf("%lf%lf",&x[l],&y[l]);
		scanf("%lf%lf",&x[r],&y[r]);
		if(l>r)swap(l,r);
		double dx=x[r]-x[l],dy=y[r]-y[l];
		int tp=l;
		while(tp>1){
			double tx=dx,ty=dy;
			play(tx,ty,rotX,rotY,dx,dy);
			tp--;
		}
		int i,j;
		rx[1]=1,ry[1]=0;
		for(i=2;i<=n+1;i++)
			play(rx[i-1],ry[i-1],ROTx,ROTy,rx[i],ry[i]);
		double xx=0,yy=0;
		for(i=1,j=1;i<=r-l;j++,i++)
			xx+=rx[j],yy+=ry[j];
		play(xx,-yy,dx,dy,dx,dy);
		dx/=xx*xx+yy*yy;
		dy/=xx*xx+yy*yy;
		for(i=2;i<=n;i++)
			play(dx,dy,rx[i-1],ry[i-1],qx[i],qy[i]);
		sx[1]=0,sy[1]=0;
		for(i=2;i<=n;i++)
			sx[i]=sx[i-1]+qx[i],sy[i]=sy[i-1]+qy[i];
		x[1]=x[l]-sx[l],y[1]=y[l]-sy[l];
		for(i=2;i<=n;i++)
			x[i]=x[1]+sx[i],y[i]=y[1]+sy[i];
		for(i=1;i<=n;i++){wa(x[i]);printf(" ");wa(y[i]);printf("\n");}
	}
	return 0;
}
