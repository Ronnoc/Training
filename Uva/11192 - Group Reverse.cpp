#include<stdio.h>
#include<string.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		char s[110];
		scanf("%s",s);
		int len=strlen(s);
		int k=len/n;
		int i,j;
		for(i=0;i<n;i++){
			int z=0;
			for(j=k-1+k*i;z<k;z++,j--)printf("%c",s[j]);
			} 
		printf("\n");
		}
	return 0;
	}
