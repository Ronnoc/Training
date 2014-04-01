#include<stdio.h>
#include<string.h>
char _s[110],s[110];
int p[10],q[10];
void P(int x){
	int i;
	for(i=p[x];i<=q[x];i++)printf("%c",_s[i]);
	}
int main(){
	int z;
	scanf("%d",&z);getchar();
	while(z--){
		gets(_s);gets(s);
		int i,j;
		int first=0,end;
		p[1]=0;
		for(i=0;i<strlen(_s);i++){
			if(!first&&_s[i]=='<'){
				q[1]=i-1;
				p[2]=i+1;
				}
			else if(!first&&_s[i]=='>'){
				first=1;
				q[2]=i-1;
				p[3]=i+1;
				}
			else if(_s[i]=='<'){
				q[3]=i-1;
				p[4]=i+1;
				}
			else if(_s[i]=='>'){
				q[4]=i-1;
				p[5]=i+1;
				}
			}
		q[5]=strlen(_s)-1;
		for(i=1;i<=5;i++){
			for(j=p[i];j<=q[i];j++)printf("%c",_s[j]);
			}
		printf("\n");
		for(i=0;i<strlen(s)-3;i++)printf("%c",s[i]);
		P(4);P(3);P(2);P(5);printf("\n");
		}
	return 0;
	}
