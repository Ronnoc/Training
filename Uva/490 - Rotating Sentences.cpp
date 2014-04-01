#include<stdio.h>
#include<string.h>
char map[110][110];
int len[110];
int main(){
	int i=0,j;
	while(gets(map[i]))i++;
	int n=i;
	for(i=0;i<n;i++)len[i]=strlen(map[i]);
//	for(i=0;i<n;i++)printf("%s~~%d\n",map[i],len[i]);
	for(i=0;2*i<n-1;i++){
		char s[110];
		memset(s,'\0',sizeof(s));
		memcpy(s,map[i],sizeof(map[i]));
		memset(map[i],'\0',sizeof(map[i]));
		memcpy(map[i],map[n-1-i],sizeof(map[n-1-i]));
		memset(map[n-i-1],'\0',sizeof(map[n-i-1]));
		memcpy(map[n-1-i],s,sizeof(s));
		}
	int max=len[0];
	for(i=1;i<n;i++)if(len[i]>max)max=len[i];
	for(i=0;i<max;i++){
		if(map[i][i]=='\0')map[i][i]=' ';
		for(j=i+1;j<max;j++){
			if(map[i][j]=='\0')map[i][j]=' ';
			if(map[j][i]=='\0')map[j][i]=' ';
			char c=map[i][j];
			map[i][j]=map[j][i];
			map[j][i]=c;
			}
		}
	for(i=0;i<max;i++){
		for(j=0;j<n;j++)printf("%c",map[i][j]);
		printf("\n");
		}
	return 0;
	}
