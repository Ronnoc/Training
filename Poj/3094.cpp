#include<stdio.h>
#include<string.h>
int f(char x){
	if(x<='z'&&x>='a')x+='A'-'a';
	if(x==' ')return 0;
	return x-'A'+1;
	}
int main(){
	char s[1010];
	while(gets(s)!=NULL){
		if(strcmp(s,"#")==0)break;
		long long res=0;
		for(int i=1;i<=strlen(s);++i){
			res+=i*f(s[i-1]);
			}
		printf("%lld\n",res);
		}
	return 0;
	} 
