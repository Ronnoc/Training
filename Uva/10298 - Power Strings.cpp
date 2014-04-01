#include<stdio.h>
#include<string.h>
char s[1000010];
int main()
{
	while(scanf("%s",s)!=EOF){
		int i,j,res=0;
		int len=strlen(s);
		if(len==1)break;
		for(i=1;i<=len;i++){
			int flag=1;
			if(len%i!=0)continue; 
			for(j=i;j<len;j++){
				if(s[j%i]!=s[j]){flag=0;break;}
				}
			if(flag)break;
			}
		printf("%d\n",len/i);
		}
	return 0;
	}
