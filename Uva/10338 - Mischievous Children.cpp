#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *_a,const void *_b)
{
	char *a=(char *)_a;
	char *b=(char *)_b; 
	return *a-*b;
	}
unsigned long long jc[30];
int main()
{
	int z,k;
	int i;
	jc[0]=1;
	for(i=1;i<=26;i++)jc[i]=jc[i-1]*i;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		char s[100];
		scanf("%s",s);
		qsort(s,strlen(s),sizeof(char),cmp);
		int len=strlen(s),p=1;
		unsigned long long res=jc[len];
		for(i=0;i<len;i++)
		{
			if(s[i]==s[i+1]){p++;}
			else {res/=jc[p];p=1;}
			}
		printf("Data set %d: %llu\n", k, res);
		}
	return 0;
	} 
