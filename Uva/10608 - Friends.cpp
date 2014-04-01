#include<stdio.h>
#define MAX 30010
int ft[MAX],res[MAX];
void in_ft(int n){
	int i;
	for(i=1;i<=n;i++)ft[i]=i;
	for(i=1;i<=n;i++)res[i]=0;
	}
int find(int x){
	int t=x,temp;
	while(ft[x]!=x)x=ft[x];
	while(t!=x){
		temp=ft[t];
		ft[t]=x;
		t=temp;
		}
	return x;
	}
void merge(int root1,int root2){
	int fr1=find(root1);
	int fr2=find(root2);
	ft[fr1]=fr2;
	find(root1);
	find(root2);
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);in_ft(n);
		int i;
		for(i=1;i<=m;i++){
			int p,q;
			scanf("%d%d",&p,&q);
			merge(p,q);
			}
		for(i=1;i<=n;i++)res[find(i)]++;
		int max=0;
		for(i=1;i<=n;i++)if(res[i]>max)max=res[i];
		printf("%d\n",max);
		}
	return 0;
	}
