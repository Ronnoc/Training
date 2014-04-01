#include<stdio.h>
int main(){
	char c;
	int t=0;
	while( (c=getchar()) !=EOF){
		if(c=='b')c=' ';
		if(c>='0'&&c<='9')t+=c-'0';
		else if(c=='!'||c=='\n')printf("\n");
		else if(t>0){
			while(t--)putchar(c);
			t=0;
			}
		}
	return 0;
	}
