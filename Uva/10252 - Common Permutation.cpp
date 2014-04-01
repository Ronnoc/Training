#include<stdio.h>
#include<string.h>
#include<algorithm>
char a[10010],b[10010];
int main(){
	while(gets(a)!=NULL){
		gets(b);
		int la=strlen(a);
		int lb=strlen(b);
		int i;
		int xa[30],xb[30];
		memset(xa,0,sizeof(xa));
		memset(xb,0,sizeof(xb));
		for(i=0;i<la;i++)if(a[i]>='a'&&a[i]<='z')xa[a[i]-'a']++;
		for(i=0;i<lb;i++)if(b[i]>='a'&&b[i]<='z')xb[b[i]-'a']++;
		for(i=0;i<26;i++){
			int l=std::min(xa[i],xb[i]);
			for(int j=1;j<=l;j++)printf("%c",'a'+i);
			}
		printf("\n");
		}
	return 0;
	}
