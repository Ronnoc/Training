#include<stdio.h> 
#include<string.h>
bool is_17(char *s)
{
	int sum=0,len=strlen(s);
	int i;
	int k[20]={-5,1,-7,-2,-3,4,6,9,5,-1,7,2,3,-4,11,8};
	for(i=len-1;i>=0;i--)
	{
		sum+=k[(len-i)%16]*(s[i]-'0');
		}
	if(sum%17==0)return 1;
	return 0;
	}
int main()
{
	char s[1010];
	while(scanf("%s",s)!=EOF)
	{
		int len=strlen(s);
		if(len==1 && s[0]=='0')break;
		if(is_17(s))printf("1\n");
		else printf("0\n");
		}
	return 0;
	}
