#include<stdio.h>
int ft[10030];
void in_ft(int n){
	int i;
	for(i=1;i<=n;i++)ft[i]=i;
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
		int n,i;
		scanf("%d%*c",&n);
		in_ft(n);
		int n1=0,n2=0;
		char s[1000];
		while(gets(s)!=NULL){
			if(s[0]=='\0')break;
			char q;
			int x,y;
			sscanf(s,"%c %d %d",&q,&x,&y);
			if(q=='c')merge(x,y);
			else {
				if(find(x)==find(y))n1++;
				else n2++;
				}
			}
		printf("%d,%d\n",n1,n2);
		if(t)printf("\n");
		}
	return 0; 
	}
