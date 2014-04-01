#include<stdio.h>
#include<string.h>
int main()
{
	int z;
	scanf("%d",&z);
	int k;
	for(k=1;k<=z;k++)
	{
		char a[999];
		scanf("%s",a);
		int p,j;
		int len=strlen(a);
		for(p=1;;p++)
		{
			if(len%p!=0)continue;
			//printf("%d\n",len);
			//printf("%d\n",p);
			int flag=1;
			for(j=p; flag && j<len;j++)
			{
				if(a[j]!=a[j%p])flag=0;
				}
			if(flag)
			{
				//for(j=0;j<p;j++)printf("%c",a[j]);
				printf("%d\n",p);
				break;
				}
			}
			if(k!=z)printf("\n");
		}
	return 0; 
	} 
