#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char word[110][8],sort[110][8];
int cmp_char(const void *aa,const void *bb)
{
	char *a=(char *)aa;
	char *b=(char *)bb;
	return *a-*b; 
	}
int cmp_string(const void *aa,const void *bb)
{
	char *a=(char *)aa;
	char *b=(char *)bb;
	return strcmp(a,b); 
	}
int main()
{
	int n=0,i;
	while(scanf("%s",word[n])!=EOF)
	{
		if(word[n][0]=='X')break;
		n++;
		}
	qsort(word,n+1,sizeof(word[0]),cmp_string);
	for(i=0;i<n;i++)
	{
		strcpy(sort[i],word[i]);
		qsort(sort[i],strlen(sort[i]),sizeof(char),cmp_char);
		}
	char s[10];
	while(scanf("%s",s)!=EOF)
	{
		if(s[0]=='X')break;
		qsort(s,strlen(s),sizeof(char),cmp_char);
		int ok=0;
		for(i=0;i<n;i++)
		{
			if(strcmp(s,sort[i])==0)
			{
				ok=1;
				printf("%s\n",word[i]);
				}
			}
		if(!ok)printf("NOT A VALID WORD\n");
		printf("******\n");
		}
	return 0;
	}
