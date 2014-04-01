#include<stdio.h>
#define MAX 50010
int ft[MAX];
void in_ft(int n){
	int i;
	for(i=1;i<=n;i++)ft[i]=i;
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
	}
int is_root(int x){
	if(ft[x]==x)return 1;
	return 0;
	}
int main(){
	int n,m;
	int z=0;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(!n&&!m)break;
		in_ft(n);
		int i;
		for(i=1;i<=m;i++){
			int p,q;
			scanf("%d%d",&p,&q);
			merge(p,q);
			}
		int res=0;
		for(i=1;i<=n;i++)res+=is_root(i);
		printf("Case %d: ",++z);
		printf("%d\n",res);
		}
	return 0;
	}
