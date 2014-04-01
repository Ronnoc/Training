#include<stdio.h>
#include<string.h>
char map[30]="22233344455566677778889999";
int main()
{
	char a[50];
	while(gets(a))
	{
		int i;
		int len=strlen(a);
		for(i=0;i<len;i++)
		{
			if(a[i]>='A' && a[i]<='Z')a[i]=map[a[i]-'A'];
			}
		puts(a);
		}
	return 0;
	} 
