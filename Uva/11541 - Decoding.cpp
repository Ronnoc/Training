#include<stdio.h>
#include<string.h>
int main(){
	char c;
	int k,z;
	scanf("%d",&z);getchar();
	for(k=1;k<=z;k++){
		printf("Case %d: ",k);
		while(c=getchar()){
			int s,i;
			if(c=='\n')break;
		//	while(c==' ')c=getchar();
			scanf("%d",&s);
			for(i=1;i<=s;i++)printf("%c",c);
			}
		printf("\n");
		}
	return 0;
	}
