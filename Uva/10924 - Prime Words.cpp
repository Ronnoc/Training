#include<stdio.h>
#include<string.h>
int f(char x){
	if(x>='a'&&x<='z')return x-'a'+1;
	if(x>='A'&&x<='Z') return x-'A'+27;
	return 0;
	}
int is_prime(int x){
	int i;
	for(i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
	}
int main(){
	char s[1010];
	while(gets(s)!=NULL){
		int sum=0;
		for(int i=0;i<strlen(s);i++)sum+=f(s[i]);
		if(is_prime(sum))printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
		}
	return 0;
	}
