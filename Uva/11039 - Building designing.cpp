#include<stdio.h>
#include<stdlib.h>
struct num{int a,b;}a[500010];
int cmp(const void *aa,const void *bb)
{
	num *a=(num *)aa;
	num *b=(num *)bb;
	num x=*a,y=*b;
	return x.a-y.a;
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x>0){
				a[i].a=x;a[i].b=1;
				}
			else {
				a[i].a=-x;a[i].b=-1;
				}
			}
		qsort(&a[1],n,sizeof(num),cmp);
		int flag=a[1].b,res=1;
		for(i=2;i<=n;i++){
			if(a[i].b!=flag){
				flag=-flag;
				res++;
				}
			}
		printf("%d\n",res);
		}
	return 0;
	}
