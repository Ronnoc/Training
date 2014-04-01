#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *aa,const void *bb)
{
	int *a=(int *)aa;
	int *b=(int *)bb;
	return *b-*a;
	}
int main(){
	char a[110],b[110];
	while(scanf("%s%s",a,b)!=EOF){
		int pa[30],pb[30];
		int i;
		for(i=0;i<26;i++)pa[i]=0;	
		for(i=0;i<26;i++)pb[i]=0;	
		int len=strlen(a);
		for(i=0;i<len;i++){
			pa[a[i]-'A']++;
			pb[b[i]-'A']++;
			}
		qsort(pa,26,sizeof(int),cmp);
		qsort(pb,26,sizeof(int),cmp);
		int flag=0;
		for(i=0;i<25;i++)if(pa[i]!=pb[i])flag=1;
		if(flag)printf("NO\n");
		else printf("YES\n");
		}
	return 0;
	}
