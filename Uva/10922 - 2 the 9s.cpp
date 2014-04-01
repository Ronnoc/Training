#include<stdio.h>
#include<string.h>
int sum(char *s)
{
	int res=0;
	int len=strlen(s);
	int i;
	for(i=0;i<len;i++)res+=s[i]-'0';
	return res;
	}
int main()
{
	char s[1010];
	while(scanf("%s",s)!=EOF)
	{
		int len=strlen(s);
		if(len==1 && s[0]=='0')break;
		int k=0;
		int p=sum(s);
		while(1)
		{
			if(p==9){k++;break;}
			if(p%9==0)
			{
				k++;
				p=p/1000+p%1000/100+p%100/10+p%10;
				}
			else break;
			}
		if(!k)printf("%s is not a multiple of 9.\n",s);
		else printf("%s is a multiple of 9 and has 9-degree %d.\n",s,k);
		}
	return 0;
	}
