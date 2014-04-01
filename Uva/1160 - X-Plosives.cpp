#include<stdio.h>
int ft[100010];
void in_ft(){
	int i;
	for(i=1;i<=100000;i++)ft[i]=i;
	}
int find(int x){
	int t=x,temp;
	while(x!=ft[x])x=ft[x];
	while(t!=x){
		temp=ft[t];
		ft[t]=x;
		t=temp;
		}
	return x;
	}
void merge(int a,int b){
	int fa=find(a);
	int fb=find(b);
	ft[fb]=fa;
	}
int main(){
	int x,y;
	int sum=0;
	in_ft();
	while(scanf("%d",&x)!=EOF){
		if(x==-1){
			printf("%d\n",sum);
			in_ft();
			sum=0;
			continue;
			}
		scanf("%d",&y);
		if(find(x)!=find(y))merge(x,y);
		else sum++;
		}
	return 0;
	}
