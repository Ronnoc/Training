#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char country[2010][76],count[2010];
int cmp_string(const void *_a,const void *_b)
{
	char *a=(char *)_a;
	char *b=(char *)_b;
	return strcmp(a,b);
	} 
int main()
{
	int n,z;
	scanf("%d",&n);
	for(z=1;z<=n;z++)
	{
		scanf("%s",country[z]);char a[75];gets(a);
		}
	//for(z=1;z<=n;z++)puts(country[z]);
	qsort(country[1],n,sizeof(country[1]),cmp_string);
	//for(z=1;z<=n;z++)puts(country[z]);
	int count=1,flag=0,i,wz=1;
	int weizhi[2100],jishu[2100];
	for(i=1;i<n;i++)
	{
		if(!(i-1)){weizhi[wz]=i;jishu[wz]=1;}
		if(strcmp(country[i],country[i+1])==0)jishu[wz]++;
		else if(strcmp(country[i],country[i+1])!=0){wz++;weizhi[wz]=i+1;jishu[wz]=1;}
		
		}
	for(i=1;i<=wz;i++)
	{
		printf("%s %d\n",country[weizhi[i]],jishu[i]);
		}
	//system("pause");
	return 0;
	}
