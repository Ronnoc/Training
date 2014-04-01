#include<stdio.h>
#include<string.h>
void f(char *a)
{
	int len=strlen(a);
	int i;
	for(i=0;i<len;i++)
	{
	if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')a[i]='a';	
	}	
	}
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		char a[30],b[30];
		scanf("%s%s",a,b);
		f(a);f(b);
		if(strcmp(a,b)==0)printf("Yes\n");else printf("No\n");
		}
	return 0;
	}
