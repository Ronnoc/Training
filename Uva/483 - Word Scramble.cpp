#include<stdio.h>
#include<string.h>
int main()
{
	char a[1100];
	while(gets(a))
	{
		char b[1100];
		int i=0,j,k,l=0,start=0,end=0;
		for(i=0;i<1100;i++)b[i]='\0';
		int len=strlen(a);
		a[len]=' ';a[len+1]='\0'; 
		for(i=0;i<=len;i++)
			{
			for(j=i;j<=len;j++)
				{
				if(a[j]==' ' || a[j]=='\0')//i,j×ª»»£¬break;i=j; 
					{
				if(j>=1)for(k=j-1;k>=i;k--)
						{
							b[l++]=a[k];
						}
					b[l++]=a[j];
					i=j;
					break;
					}
				}		
			}
		for(i=0;i<len;i++)printf("%c",b[i]);printf("\n");
		}
	return 0;
	}
