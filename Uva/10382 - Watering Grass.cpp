#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct water{double l,r;}u[10010];
int n,pu;
double s,w;
int  cmp(const void *a,const void *b){
	water *p=(water *)a;
	water *q=(water *)b;
	double z=(*p).l-(*q).l;
	if(z>0)return 1;
	if(z<0)return -1;
	return 0;
	}
int main(){
	while(scanf("%d%lf%lf",&n,&s,&w)!=EOF){
		pu=0;
		w/=2;
		int i;
		for(i=1;i<=n;i++){
			double x,r;
			scanf("%lf%lf",&x,&r);
			if(r>w){
				++pu;
				u[pu].l=x-sqrt(r*r-w*w);
				u[pu].r=x+sqrt(r*r-w*w);
				}
			}
		qsort(&u[1],pu,sizeof(water),cmp);
	//	for(i=1;i<=pu;i++)printf("%lf~%lf\n",u[i].l,u[i].r);printf("\n");
		double left=0;
		int res=0;
		int flag=1;
		int last=0;
		while(last!=pu){
			if(u[last+1].l>left){flag=0;break;}
			for(i=last+1;i<=pu;i++)if(u[i].l>left)break;
			int rr=i;
			double max=u[rr-1].r;
			int pax=rr-1;
		//	printf("left:%lf\n",left);
			for(i=last+1;i<rr;i++)
			{
		//		printf("%lf~%lf\t",u[i].l,u[i].r);
				if(u[i].r>max){
					max=u[i].r;
					pax=i;
					}
				}
			last=rr-1;
			left=u[pax].r;
		//	printf("\nnow left:%lf\n",left);
		//	printf("last:%d\n\n",last);
			res++;
			}
		if(last!=pu||left<s)flag=0;
		if(!flag)printf("-1\n");
		else printf("%d\n",res);
		}
	return 0;
	}
