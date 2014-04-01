#include<stdio.h>
#include<stdlib.h>
int a[110],b[110];
int cmp(const void *aa,const void *bb)
{
	int *a=(int *)aa;
	int *b=(int *)bb;
	return *a-*b;
	}
int main(){
	int n,d,r;
	while(scanf("%d%d%d",&n,&d,&r)!=EOF){
		if(n==0&&d==0&&r==0)break;
		int i;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)scanf("%d",&b[i]); 
		qsort(&a[1],n,sizeof(int),cmp);
		qsort(&b[1],n,sizeof(int),cmp);
		int p;
		int res=0;
		for(p=0;p<n;p++){
			if(a[1+p]+b[n-p]>d)res+=a[1+p]+b[n-p]-d;
			}
		res*=r;
		printf("%d\n",res);
		}
	return 0;
	}
