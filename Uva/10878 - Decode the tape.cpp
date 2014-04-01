#include<stdio.h>
int main(){
	char s[110];
	int p[8]={6,5,4,3,0,2,1,0},i;
	while(gets(s)!=NULL){
		if(s[0]=='|'){
			int b=0;
			for(i=0;i<8;i++)b|=(s[2+i]=='o')<<(p[i]);
			printf("%c",b);
			}
		}
	return 0;
	}
