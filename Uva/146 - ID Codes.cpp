#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	while(scanf("%s",s)!=EOF){
		int len=strlen(s);
		if(len==1&&s[0]=='#')break;
		int i;
		for(i=len-1;i>=1;i--){
			if(s[i]>s[i-1])break;
			}
		if(i==0){
			printf("No Successor\n");
			continue;
			}
		int l=i-1;
		int j;
		for(j=0;j<l;j++)printf("%c",s[j]);
		int sum[30];
		for(i=0;i<26;i++)sum[i]=0;
		for(j=l;j<len;j++)sum[s[j]-'a']++;
		for(i=s[l]-'a'+1;i<26;i++)if(sum[i])break;
		printf("%c",i+'a');
		sum[i]--;
		for(i=0;i<26;i++){
			for(j=1;j<=sum[i];j++)printf("%c",i+'a');
			}
		printf("\n");
		}
	return 0;
	}
