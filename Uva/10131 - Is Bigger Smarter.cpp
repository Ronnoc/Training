#include<stdio.h>
#include<stdlib.h>
struct ept{int w;int s;int k;}a[1010];
int lis[1010];
int pre[1010];
int put[1010];
int cmp(const void *aa,const void *bb)
{
	ept *a=(ept *)aa;
	ept *b=(ept *)bb;
	ept x=*a,y=*b;
	return y.w-x.w;
	}
int main(){
	int i=1,j;
	while(scanf("%d%d",&a[i].w,&a[i].s)!=EOF){
		a[i].k=i;
		i++;
		}
	int n=i-1;
	qsort(&a[1],n,sizeof(ept),cmp);
	for(i=1;i<=n;i++)lis[i]=1;
	for(i=1;i<=n;i++)pre[i]=-1;
	for(i=2;i<=n;i++){
		for(j=1;j<i;j++){
			if(a[j].s<a[i].s && a[j].w>a[i].w && lis[j]+1>lis[i])lis[i]=lis[j]+1;
			}
		for(j=1;j<i;j++)if(lis[i]==lis[j]+1)pre[i]=j;
		}
	int res=0,start;
	for(i=1;i<=n;i++)if(res<lis[i])res=lis[i];
	for(i=1;i<=n;i++)if(lis[i]==res){
		start=i;
		break;
		} 
	i=0;
	while(1){
		++i;
		put[i]=start;
		start=pre[start];
		if(start==-1)break;
		}
	printf("%d\n",res);
	for(j=1;j<=i;j++){
		printf("%d\n",a[put[j]].k);
		} 
//	return main();
	return 0;
	}
