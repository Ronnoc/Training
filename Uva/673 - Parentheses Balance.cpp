#include<string.h>
#include<stdio.h>
int main()
{
	int k,z;
	scanf("%d",&z);
	char a[150];getchar();
	for(k=1;k<=z;k++)
	{
		gets(a);
		int len=strlen(a);
		int i,j;int p=0;
		
		while(++p<=len)
		{
		for(i=1;i<len;i++)
		{
			if( (a[i-1]=='['&&a[i]==']') || (a[i-1]=='('&&a[i]==')'))
			{
				for(j=i-1;j<len;j++)a[j]=a[j+2];
				} 
			}
			}	
		if(strlen(a)!=0)printf("No\n");else printf("Yes\n"); 
		}
	return 0;
	}
