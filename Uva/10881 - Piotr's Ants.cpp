#include<stdio.h>
#include<stdlib.h>
struct Ant{int x;int w;int num;}ant[10010],end[10010];
int l,t,n;
int swap[10010];
int cmp(const void *a,const void *b){
	Ant* p=(Ant *)a;
	Ant* q=(Ant *)b;
	return (*p).x-(*q).x;
	}
int gei(Ant a){
	printf("x:%d w:%d num:%d\n",a.x,a.w,a.num);
	}
int main(){
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		int i;
		scanf("%d%d%d%*c",&l,&t,&n);
		for(i=1;i<=n;i++){
			char s[1010];
			gets(s);
			char w;
			int x;
			sscanf(s,"%d %c",&x,&w);
			ant[i].x=x;
			ant[i].w=(w=='L')?-1:1;
			ant[i].num=i;
			end[i].x=x+t*ant[i].w;
			end[i].w=ant[i].w;
			end[i].num=i;
			}
			
	//	for(i=1;i<=n;i++)gei(ant[i]);
	//	for(i=1;i<=n;i++)gei(end[i]);printf("\n");
		
		qsort(&ant[1],n,sizeof(Ant),cmp);
		qsort(&end[1],n,sizeof(Ant),cmp);
		
	//	for(i=1;i<=n;i++)gei(ant[i]);
	//	for(i=1;i<=n;i++)gei(end[i]);printf("\n");
		
		for(i=1;i<=n;i++)swap[ ant[i].num ]=i;
		for(i=1;i<n;i++)if(end[i].x==end[i+1].x){
			end[i].w=0;
			end[i+1].w=0;
			}
		printf("Case #%d:\n",k);
		for(i=1;i<=n;i++){
			Ant &h=end[swap[i]];
			if(h.x<0||h.x>l)printf("Fell off\n");
			else {
				printf("%d ",h.x);
				if(h.w==-1)printf("L");
				if(h.w==0)printf("Turning");
				if(h.w==1)printf("R");
				printf("\n");
				}
			}
		printf("\n");
		}
//	return main();
	return 0;
	}
