#include<stdio.h>
#include<string.h>
char s[]="?czaqsdfyghjbvui?w?etx??r?";
char f(char x){
	if(x>='A'&&x<='Z')return s[x-'A'];
	if(x>='a'&&x<='z')return s[x-'a'];
	if(x=='[')return 'o';
	if(x==']')return 'p';
	if(x==';')return 'k';
	if(x=='\'')return 'l';
	if(x==',')return 'n';
	if(x=='.')return 'm';
	if(x=='?')return ',';
	if(x=='\\')return '[';
	return x; 
	}
int main(){
	char s[1010];
	while(gets(s)!=NULL){
		int i,len=strlen(s);
		for(i=0;i<len;i++)printf("%c",f(s[i]));
		printf("\n");
		}
	return 0;
	}
