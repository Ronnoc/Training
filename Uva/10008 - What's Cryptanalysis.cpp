#include<stdio.h>
#include<string.h>
int main()
{
	int i,k,z,j;
	char a[10000];
	int count[30],px[30];
	scanf("%d",&z);
	for(i=1;i<=26;i++){px[i]=i;count[i]=0;}
	for(k=1;k<=z+1;k++)
	{
		gets(a);
		int len=strlen(a);
		for(i=0;i<len;i++)if(a[i]>='A' && a[i]<='Z')a[i]+='a'-'A'; 
		for(i=0;i<len;i++)
		{
			if(a[i]>='a' && a[i]<='z')count[a[i]-'a'+1]++; 
			}
		}
	for(i=1;i<=26*26;i++)
	{
		for(j=1;j<=25;j++)
		{
			if(count[j+1]>count[j])
			{
				int temp;
				temp=count[j+1];count[j+1]=count[j];count[j]=temp;
				temp=px[j+1];px[j+1]=px[j];px[j]=temp;
				}
			if(count[j+1]==count[j] && px[j+1]<px[j])
			{
				int temp;
				temp=px[j+1];px[j+1]=px[j];px[j]=temp;
				}
			}
		memset(a,'\0',sizeof(a));
		}
	for(i=1;i<=26;i++)
	{
		if(count[i]>0)printf("%c %d\n",px[i]-1+'A',count[i]); 
		} 
	return 0;
	}
