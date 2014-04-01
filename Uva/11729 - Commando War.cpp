#include<stdio.h>
#include<stdlib.h>
struct ml{int b,j;}m[1100];
int cmp(const void *a,const void *b){
	ml *x=(ml *)a;
	ml *y=(ml *)b;
	ml p=*x,q=*y;
	return q.j-p.j;
	}
int main(){
	int n;
	int t=0;
	while(scanf("%d",&n)!=EOF&&n){
		int i;
		for(i=1;i<=n;i++)scanf("%d%d",&m[i].b,&m[i].j);
		qsort(&m[1],n,sizeof(ml),cmp);
		int time[1010];
		time[1]=m[1].b+m[1].j;
		for(i=2;i<=n;i++){
			time[i]=time[i-1]-m[i-1].j+m[i].b+m[i].j;
			}
		int res=time[1];
		for(i=2;i<=n;i++)if(time[i]>res)res=time[i];
		++t;
		printf("Case %d: %d\n",t,res);
		}
	return 0;
	}
