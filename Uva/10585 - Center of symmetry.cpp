#include<stdio.h>
#include<stdlib.h>
#define eps 1e-8
int equal(double x,double y){
	if(x-y>-eps&&x-y<eps)return 1;
	return 0;
	}
struct point{double x,y;}p[10010];
int f(double x){
	if(x>0)return 1;
	if(x==0)return 0;
	return -1;
	}
int cmp(const void *a,const void *b){
	point p=*(point *)a;
	point q=*(point *)b;
	if(equal(p.x,q.x))return f(p.y-q.y);
	return f(p.x-q.x);
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int i;
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
		qsort(&p[1],n,sizeof(point),cmp);
		point aim=(point){p[1].x/2+p[n].x/2,p[1].y/2+p[n].y/2};
		int flag=1;
		for(i=1;i*2<=n+1;i++){
			double x,y;
			x=p[i].x+p[n-i+1].x;x/=2;
			y=p[i].y+p[n-i+1].y;y/=2;
			if(equal(x,aim.x)&&equal(y,aim.y));
			else {
				flag=0;
				break;
				}
			}
		if(flag)printf("yes\n");
		else printf("no\n");
		}
	return 0;
	} 
