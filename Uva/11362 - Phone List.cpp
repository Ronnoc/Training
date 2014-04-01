#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define min(a,b) ((a)>(b)?(b):(a))
int cmp(const void *a,const void *b){
	char *p=(char *)a;
	char *q=(char *)b;
	int lenp=strlen(p),lenq=strlen(q);
	int i;
	for(i=0;i<min(lenp,lenq);i++){
		if(p[i]!=q[i])return p[i]-q[i];
		}
	return lenp-lenq;
	}
int check(char *p,char *q){
	int lenp=strlen(p),lenq=strlen(q);
	int i;
	for(i=0;i<min(lenp,lenq);i++){
		if(p[i]!=q[i])return 0;
		}
	return 1;	
	}
int main(){
	char map[10010][20];
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		int i,n;
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%s",map[i]);
		qsort(map[1],n,sizeof(map[1]),cmp);
		int flag=0;
		for(i=2;i<=n;i++)flag+=check(map[i-1],map[i]);
		if(flag)printf("NO\n");
		else printf("YES\n"); 
		}
	}
