#include<string.h>
#include<stdio.h>
char done[]="DONE";
int can(char x){
	if(x>='A'&&x<='Z')return 1;
	if(x>='a'&&x<='z')return 1;
	if(x=='\0')return 1;
	return 0;
	}
char f(char x){
	if(x>='a'&&x<='z')return x-'a'+'A';
	return x;
	}
int main(){
	char s[1010];
	while(gets(s)!=NULL){
		if(strcmp(s,done)==0)break;
		int i=0,j=strlen(s)-1,len=strlen(s),flag=1;
		while(!can(s[i]))i++;
		while(!can(s[j]))j--;
		while(i<j){
		//	printf("%d %d\n",i,j);
			if(f(s[i])!=f(s[j]))flag=0;
			if(!flag)break; 
			i++;j--;
			while(!can(s[i]))i++;
			while(!can(s[j]))j--;
			}
		if(flag)printf("You won't be eaten!\n");
		else printf("Uh oh..\n");
		}
	return 0;
	}
