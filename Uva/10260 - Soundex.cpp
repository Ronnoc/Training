#include<stdio.h>
#include<string.h>
int f(char a)
{
	if(a=='B'||a=='F'||a=='P'||a=='V')return 1;
	if(a=='C'||a=='G'||a=='J'||a=='K'||a=='Q'||a=='S'||a=='X'||a=='Z')return 2;
	if(a=='D'||a=='T')return 3;
	if(a=='L')return 4;
	if(a=='M'||a=='N')return 5;
	if(a=='R')return 6;
	return 0;
	}
int main()
{
	char a[100];
	while(scanf("%s",a)!=EOF)
	{
		int i;
		int len=strlen(a);
		for(i=0;i<len;i++)
		{
			if( (i>=1&&f(a[i-1])==f(a[i])) || !f(a[i]) )continue;
			printf("%d",f(a[i]));
			}
		printf("\n");
		}
	return 0;
	}
