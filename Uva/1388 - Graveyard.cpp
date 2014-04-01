#include<stdio.h>
#include<vector>
#include<stdlib.h>
struct tmd{int x,y;};
tmd q[3010],z[3010];
int cmp(const void *a,const void *b){
	tmd *p=(tmd *)a;
	tmd *q=(tmd *)b;
	tmd x=*p,y=*q;
	return x.x-y.x;
	}
int min(int a,int b){
	if(a>b)return b;
	return a;
	}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int i;
		for(i=0;i<n;i++)q[i]=(tmd){(n+m)*i,1};
		for(i=0;i<m+n;i++)q[i+n]=(tmd){n*i,-1};
		qsort(q,m+n+n,sizeof(tmd),cmp);
		int rs=0;
		int pz=0;
		for(i=0;i<m+n+n;i++){
			if(q[i].y==-1){
				int temp=n*(m+n);
				if(i>0&&q[i-1].y==1)temp=min(temp,abs(q[i-1].x-q[i].x));
				if(i+1<m+n+n&&q[i+1].y==1)temp=min(temp,abs(q[i+1].x-q[i].x));
				if(temp!=n*(m+n))z[pz++]=(tmd){temp,0};
			//	printf("z[%d].x=%d,y=%d\n",pz-1,z[pz-1].x,z[pz-1].y);
				}
		//	printf("q[%d].x=%d,y=%d\n",i,q[i].x,q[i].y);
			}
		qsort(z,pz,sizeof(tmd),cmp);
	//	for(i=0;i<pz;i++)printf("z[%d].x=%d,y=%d\n",i,z[i].x,z[i].y);
		for(i=0;i<min(n,pz);i++)rs+=z[i].x;
		double res=(double)rs/(n*(n+m))*10000;
		printf("%.4lf\n",res);
		}
	return 0;
	}
