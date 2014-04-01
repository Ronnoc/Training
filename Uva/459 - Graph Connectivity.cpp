#include<stdio.h>
int ft[30];
void in_ft(int n){
	int i;
	for(i=0;i<=n;i++)ft[i]=i;
	}
int find(int x){
	int temp,t=x;
	while(ft[x]!=x)x=ft[x];
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
	ft[fa]=fb;
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char s[3];
		scanf("%s%*c",s);
		in_ft(s[0]-'A');
		char x,y;
		int i,res=0;
		while(scanf("%c",&x)!=EOF){
			if(x=='\n')break;
			scanf("%c%*c",&y);
			merge(x-'A',y-'A');
			}
	//	for(i=0;i<=s[0]-'A';i++)printf("%d ",ft[i]);printf("\n");
		for(i=0;i<=s[0]-'A';i++)if(ft[i]==i)res++;
		printf("%d\n",res);
		if(t)printf("\n");
		}
	return 0;
	}
