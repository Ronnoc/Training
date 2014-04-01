#include<stdio.h>
#include<stdlib.h>
int m,n;
int abs(int x){
	if(x<0)return -x;
	return x;
	}
int sc(const void *a,const void *b){
	int *p=(int *)a;
	int *q=(int *)b;
	int x=*p,y=*q;
	int xx=x%m,yy=y%m;
//	printf("%d ->%d %d ->%d\n",x,xx,y,yy);
	if(xx!=yy)return xx-yy;
	else {
		if(abs(x%2)==0&&abs(y%2)==0){
			if(x>y)return 1;
			else return -1;
			}
		else if(abs(x%2)==1&&abs(y%2)==1){
			if(y<x)return -1;
			else return 1;
			}
		else {
			if(abs(x%2)==1)return -1;
			else return 1;
			}
		}
	}
int main()
{	
	int a[10010];
	while(scanf("%d%d",&n,&m)!=EOF){
		int i,j;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		printf("%d %d\n",n,m);
		if(n==0 && m==0)break;
		qsort(&a[1],n,sizeof(int),sc);
		for(i=1;i<=n;i++)printf("%d\n",a[i]);
		}
	return 0;
	}
