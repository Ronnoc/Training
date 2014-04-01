#include<string.h>
#include<stdio.h>
char s[1000010];
int main(){
	int t;
	scanf("%d%*c",&t);
	while(t--){
		gets(s);
		char res;
		int len=strlen(s);
		if(strcmp(s,"1")==0)res='+';
		else if(strcmp(s,"4")==0)res='+';
		else if(strcmp(s,"78")==0)res='+';
		else {
			if(len>=2&&s[len-1]=='5'&&s[len-2]=='3')res='-';
			else if(len>=2&&s[0]=='9'&&s[len-1]=='4')res='*';
			else res='?';
			}
		printf("%c\n",res);
		}
	return 0;
	}
