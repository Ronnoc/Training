#include<stdio.h>
#include<string.h>
#include<algorithm>
int f(char x){
	if(x>='0'&&x<='9')return x-'0';
	if(x>='A'&&x<='Z')return x-'A'+10;
	if(x>='a'&&x<='z')return x-'a'+36;
	return 0;
	}
char s[40000];
int main(){
	while(scanf("%s",s)!=EOF){
		int len=strlen(s),i,j;
		int res=2;
		for(i=0;i<len;i++)res=std::max(res,f(s[i])+1);
		int x=0;
		for(i=0;i<len;i++)x+=f(s[i]);
	//	if(s[i]=='-')x=-x;
		for(;res<=62;res++)if(x%(res-1)==0)break;
		if(res==63)printf("such number is impossible!\n");
		else printf("%d\n",res);
		}
	return 0;
	}
