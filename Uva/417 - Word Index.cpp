#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int dp[30][30][30][30][30];
char s[10];
int f(char x){
	if(x=='?')return 0;
	return x-'a'+1;
	}
bool check(){
	int len=strlen(s);
	int i;
	for(i=0;i<len-1;i++)if(s[i]>=s[i+1])return 0;
	return 1;
	}
void next(){
	int i,len=strlen(s);
	s[len-1]++;
	for(i=len-1;i>=1;i--)if(s[i]=='z'+1){
		s[i]='a';
		s[i-1]++;
		}
	if(s[0]=='z'+1){
		for(i=0;i<=len;i++)s[i]='a';s[len+1]='\0';
		}
	}
int main(){
	memset(s,0,sizeof(s));s[0]='a';
	int m=1;
	while(m<=83681){
		if(check()){
			int x[10];
			int i;
			int len=strlen(s);
			for(i=5;i>len;i--)x[i]=0;
			for(i=1;i<=len;i++)x[i]=f(s[i-1]); 
			dp[x[5]][x[4]][x[3]][x[2]][x[1]]=m++;			
			}
		next();
		}//printf("%s\n",s);
	while(scanf("%s",s)!=EOF){
		if(check()){
			int x[10];
			int i;
			int len=strlen(s);
			for(i=5;i>len;i--)x[i]=0;
			for(i=1;i<=len;i++)x[i]=f(s[i-1]); 
			int y=dp[x[5]][x[4]][x[3]][x[2]][x[1]];	
			printf("%d\n",y);		
			}
		else printf("0\n");
		}
	return 0;
	}
