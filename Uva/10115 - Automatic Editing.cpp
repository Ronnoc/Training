#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char rule_from[11][400],rule_to[11][400];
char temp[400],map[400];
int main(){
//	freopen("autoedit.in","r",stdin);
//	freopen("autoedit.out","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		getchar();
		int i,j;
		for(i=1;i<=n;i++){
			gets(rule_from[i]);
			gets(rule_to[i]);
	//		printf("rule%d:%s ~to~ %s\n",i,rule_from[i],rule_to[i]);
			}
		gets(map);
		int len=strlen(map),k;
		for(j=1;j<=n;j++){
			for(i=0;i<len;i++){
				int flag=1;
				for(k=0;k<strlen(rule_from[j]);k++){
					if(map[i+k]!=rule_from[j][k]){
						flag=0;break;
						}
					}
				if(flag){
					int l;
					for(k=0,l=0;k<i;k++,l++)temp[l]=map[k];
					for(k=0;k<strlen(rule_to[j]);k++,l++)temp[l]=rule_to[j][k];
					for(k=i+strlen(rule_from[j]);k<=len;k++,l++)temp[l]=map[k];
					temp[l]='\0';
					len=strlen(temp);
			//		printf("rule%d from %s ~to~ %s\n",j,map,temp);
					for(k=0;k<=len;k++)map[k]=temp[k];
					i=-1;
					}
				if(i==-1)break;
				}
			if(i==-1)j--;
			}
		printf("%s\n",map);
		}
	return 0;
	}
