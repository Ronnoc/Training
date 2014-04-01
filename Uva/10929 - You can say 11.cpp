#include<stdio.h>
#include<string.h>
bool is_11(char *s)
{
	int sum=0,len=strlen(s);
	int i;
	int k[2]={1,-1};
	for(i=len-1;i>=0;i--)
	{
		sum+=k[(len-i)%2]*(s[i]-'0');
		}
	if(sum%11==0)return 1;
	return 0;
	}
int main()
{
	char s[1010];
	while(scanf("%s",s)!=EOF)
	{
		int len=strlen(s);
		if(len==1 && s[0]=='0')break;
		if(is_11(s))printf("%s is a multiple of 11.\n",s);
		else printf("%s is not a multiple of 11.\n",s); 
		}
	return 0;
	}
