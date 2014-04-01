#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
	char *p=(char *)a;
	char *q=(char *)b;
	return strcmp(p,q);
	}
char dic[1000010][210];
bool is_az(char x){
	if(x>='a'&&x<='z')return 1;
	if(x>='A'&&x<='Z')return 1;
	return 0;
	} 
char f(char x){
	if(x>='A'&&x<='Z')return x-'A'+'a';
	return x;
	}
int main(){
	int pd=0,i;
	char temp[5010];
	while(scanf("%s",temp)!=EOF){
		int len=strlen(temp);
		int v=0;
		for(i=0;i<len;i++){
			if(is_az(temp[i]))dic[pd][v++]=f(temp[i]);
			else {
				dic[pd][v]='\0';
				pd++;
				v=0;
				}
			}
		if(v>0)pd++;
		dic[pd][v]='\0';
		}
	qsort(dic,pd,sizeof(dic[0]),cmp);
	int j;
	for(i=0;i<pd;i++){
		if(strlen(dic[i])==0)continue;
		if(strcmp(temp,dic[i])!=0){
			printf("%s\n",dic[i]);
			for(j=0;j<=strlen(dic[i]);j++)temp[j]=dic[i][j];
			}
		}
//	system("pause");
	return 0;
	}
