#include<stdio.h>
#include<string.h>
bool is_1(char *s)
{return true;}
bool is_2(char *s)
{
	int len=strlen(s);
	int x=s[len-1]-'0';
	if(x%2==0)return 1;
	return 0;
	}
int sum(char *s)
{
	int res=0;
	int len=strlen(s);
	int i;
	for(i=0;i<len;i++)res+=s[i]-'0';
	return res;
	}
bool is_3(char *s)
{
	if(sum(s)%3==0)return 1;
	return 0;
	}
bool is_4(char *s)
{
	int len=strlen(s);
	int i;
	int k;
	if(len==1)
	{
		if( (s[0]-'0') %4==0 )return 1;
		return 0;
		}
	k=(s[len-1]-'0')+(s[len-2]-'0')*10;
	if(k%4==0)return 1;
	return 0;
	}
bool is_5(char *s)
{
	int len=strlen(s);
	if( s[len-1]=='0' ||s[len-1]=='5' )return 1;
	return 0;
	}
bool is_6(char *s)
{
	return is_2(s)*is_3(s);
	}
bool is_7(char *s)
{
	int sum=0,len=strlen(s);
	int i;
	int k[7]={5,1,3,2,6,4};
	for(i=len-1;i>=0;i--)
	{
		sum+=k[(len-i)%6]*(s[i]-'0');
		}
	if(sum%7==0)return 1;
	return 0;
	}
bool is_8(char *s)
{
	int len=strlen(s);
	int i;
	int k;
	if(len==1)
	{
		if( (s[0]-'0') %8==0 )return 1;
		return 0;
		}
	if(len==2)
	{
		k=(s[len-1]-'0')+(s[len-2]-'0')*10;
		if(k%8==0)return 1;
		return 0;
		}
	k=(s[len-1]-'0')+(s[len-2]-'0')*10+(s[len-3]-'0')*100;
	if(k%8==0)return 1;
	return 0;
	}
bool is_9(char *s)
{
	if(sum(s)%9==0)return 1;
	return 0;
	}
bool is_10(char *s)
{
	if(s[strlen(s)-1]=='0')return 1;
	return 0;
	}
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
bool is_12(char *s)
{
	return is_3(s)*is_4(s);
	}
bool is(char *s,int i)
{
	if(i==1)return is_1(s);
	if(i==2)return is_2(s);
	if(i==3)return is_3(s);
	if(i==4)return is_4(s);
	if(i==5)return is_5(s);
	if(i==6)return is_6(s);
	if(i==7)return is_7(s);
	if(i==8)return is_8(s);
	if(i==9)return is_9(s);
	if(i==10)return is_10(s);
	if(i==11)return is_11(s);
	if(i==12)return is_12(s);
	}
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		char s[1010];
		int m,i,a[2000];
		scanf("%s%d",s,&m);
		for(i=1;i<=m;i++)scanf("%d",&a[i]);
		int flag=1;
		for(i=1;i<=m && flag;i++)
		{
			flag*=is(s,a[i]);
			}
		if(flag)printf("%s - Wonderful.\n",s);
		else printf("%s - Simple.\n",s);
		} 
	return 0;
	}
