#include<stdio.h>
#include<string.h>
char key[110][110],pk;
char map[110][6000],pm;
bool check(char c){
	if(c>='a'&&c<='z')return 0;
	if(c>='A'&&c<='Z')return 0;
	return 1;
	}
bool is_here(char *s,int l,char *key){
	int lk=strlen(key),i;
	for(i=0;i<lk;i++){
		if(s[l+i]!=key[i])return 0;
		}
	return check(s[l+lk]);
	}
int f(char *s){
	int i,j,len=strlen(s);
//	int ok[110];
	int sum=0;
//	for(i=1;i<=pk;i++)ok[i]=0;
	for(i=0;i<len;i++){
		for(j=1;j<=pk;j++){
			if(/*!ok[j]&& */is_here(s,i,key[j]) )sum++;//ok[j]=1;
			}
		}
/*	int sum=0;
	for(i=1;i<=pk;i++)sum+=ok[i];*/
	return sum;
	}
int main(){
	int z=0;
	while(scanf("%d%d%*c",&pk,&pm)!=EOF){
		int i,j;
		for(i=1;i<=pk;i++)gets(key[i]);//printf("!");
		for(i=1;i<=pm;i++)gets(map[i]);
		char save[110][6000];
		for(i=1;i<=pm;i++)for(j=0;j<strlen(map[i]);j++)save[i][j]=map[i][j];
		for(i=1;i<=pm;i++)for(j=0;j<strlen(map[i]);j++)if(map[i][j]>='A'&&map[i][j]<='Z')map[i][j]+='a'-'A';
		int res[110];
		for(i=1;i<=pm;i++)res[i]=f(map[i]);
	//	for(i=1;i<=pm;i++)printf("%d ",res[i]);printf("\n");
		int big=-1;
		for(i=1;i<=pm;i++)if(res[i]>big)big=res[i];
		printf("Excuse Set #%d\n",++z);
		for(i=1;i<=pm;i++)if(res[i]==big)puts(save[i]);
		printf("\n");
		}
	return 0;
	}
