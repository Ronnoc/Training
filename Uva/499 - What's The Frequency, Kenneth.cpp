#include<stdio.h>
#include<string.h>
int main()
{
	char b[10000];
	while(gets(b))
	{
		int len=strlen(b);
		int i;
		int a[60];
		for(i=1;i<=52;i++)a[i]=0;
		char dic[60];
		for(i=1;i<=26;i++)dic[i]='A'-1+i;
		for(i=27;i<=52;i++)dic[i]='a'-1+i-26;
		for(i=0;i<len;i++)
		{
			char s=b[i];
			if(s>='a' && s<='z')a[s-'a'+1+26]++;
			if(s>='A' && s<='Z')a[s-'A'+1]++;
			}
		int max=0;
		for(i=1;i<=52;i++)
		{
			if(a[i]>max)max=a[i];
			}
		for(i=1;i<=52;i++)
		{
			if(a[i]==max)printf("%c",dic[i]);
			}
		printf(" %d\n",max);
		}
	return 0;
	}
