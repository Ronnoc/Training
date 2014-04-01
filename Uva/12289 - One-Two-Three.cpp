#include<stdio.h>
#include<string.h>
int main()
{
	int k,z,i;
	char a[10];
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		scanf("%s",a);
		if(strlen(a)==5)printf("%d\n",strlen(a)-2);
		else
		{
			if( (a[0]=='o'&&a[1]=='n') || (a[0]=='o'&&a[2]=='e') || (a[2]=='e'&&a[1]=='n') )printf("1\n");
			else printf("2\n");
			}
		for(i=0;i<10;i++)a[i]='\0';
		}
	return 0;
	}
