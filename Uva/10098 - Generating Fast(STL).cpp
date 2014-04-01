#include<stdio.h>
#include<string.h>
#include<algorithm>
int main(){
	char s[110];
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		std::sort(s,s+len);
		do{
			printf("%s\n",s);
			}while(std::next_permutation(s,s+len));
		printf("\n");
		}
	return 0;
	}
