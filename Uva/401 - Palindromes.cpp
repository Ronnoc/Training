#include<string.h>		
#include<stdio.h>
char mir(char a)
{
	switch(a)
	{
		case 'A':a='A';break;
		case 'E':a='3';break;
		case 'H':a='H';break;
		case 'I':a='I';break;
		case 'J':a='L';break;
		case 'L':a='J';break;
		case 'M':a='M';break;
		case 'O':a='O';break;
		case 'S':a='2';break;
		case 'T':a='T';break;
		case 'U':a='U';break;
		case 'V':a='V';break;
		case 'W':a='W';break;
		case 'X':a='X';break;
		case 'Y':a='Y';break;
		case 'Z':a='5';break;
		case '1':a='1';break;
		case '2':a='S';break;
		case '3':a='E';break;
		case '5':a='Z';break;
		case '8':a='8';break;
		default :a='%';break;
		}
	return a;
	}
void f(char *a)
{
	int len=strlen(a);
	int i;
	for(i=0;i<len;i++)a[i]=mir(a[i]);
	}
int main()
{
	char a[1000];int i;
	while(scanf("%s",a)!=EOF)
	{
		char pa[1000],mi[1000];
		strcpy(pa,a);
		int len=strlen(a);
		for(i=len-1;i>=0;i--)pa[len-i-1]=a[i];
		strcpy(mi,pa);
		f(mi);
		int f1,f2;
		f1=strcmp(a,pa);
		if(f1==0)f1=1;else f1=0;
		f2=strcmp(a,mi);
		if(f2==0)f2=1;else f2=0;
	//	puts(a);puts(pa);puts(mi);
		if(!f1 && !f2)printf("%s -- is not a palindrome.\n",a);
		if(f1 && !f2)printf("%s -- is a regular palindrome.\n",a);
		if(f2 && !f1)printf("%s -- is a mirrored string.\n",a);
		if(f1 && f2)printf("%s -- is a mirrored palindrome.\n",a);
		for(i=0;i<1000;i++)a[i]='\0';
		printf("\n");
		}
	return 0;
	} 
