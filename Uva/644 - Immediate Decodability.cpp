#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
	char *p=(char *)a;
	char *q=(char *)b;
	return strcmp(p,q);
	}
int f(char *a,char *b){
	if(strlen(b)<strlen(a))return 0;
	int i,len=strlen(a);
	for(i=0;i<len;i++){
		if(a[i]!=b[i])return 0;
		}
	return 1;
	}
int main(){
	char map[20][20];
	char temp[20];
	int i;
	int pm=0;
	int time=0;
	while(scanf("%s",temp)!=EOF){
		int flag=0;
		if(strlen(temp)==1&&temp[0]=='9')flag=1;
		if(!flag){
			for(i=0;i<=strlen(temp);i++)map[pm][i]=temp[i];
			pm++;
			}
		else {
			flag=0;
			qsort(map,pm,sizeof(map[0]),cmp);
			int orz=0;
			for(i=1;i<pm;i++){
				if(f(map[i-1],map[i]))orz=1;
				if(orz)break; 
				}
			if(orz)printf("Set %d is not immediately decodable\n",++time);
			else printf("Set %d is immediately decodable\n",++time);
			pm=0;
			}
		}
	return 0;
	}
