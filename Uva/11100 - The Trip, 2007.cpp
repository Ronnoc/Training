#include<stdio.h>
#include<stdlib.h>
int cmp(const void *aa,const void *bb)
{
	int *a=(int *)aa;
	int *b=(int *)bb;
	return *a-*b;
	}
int v[10010];
int a[10010];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int i,j;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)v[i]=0;
		qsort(&a[1],n,sizeof(int),cmp);
		a[0]=-1;a[n+1]=-1;
		int pv=1;
		int temp=a[1];
		for(i=1;i<=n;i++){
			if(a[i]==temp){
				v[pv]++;
				}
			else {
				temp=a[i];
				++pv;
				v[pv]++;
				}
			}
		int res=0;
		for(i=1;i<=pv;i++){
		//	printf("%d ",v[i]);
			if(v[i]>res)res=v[i];
			}
		printf("%d\n",res);
		for(i=1;i<=res;i++){
			int fi=1;
			for(j=i;j<=n;j+=res){
				if(fi)fi=0;
				else printf(" ");
				printf("%d",a[j]);
				}
			printf("\n");
			}
		}
	return 0;
	}
