#include<stdio.h>
#include<string.h>
char map[30]="_abcdefghijklmnopqrstuvwxyz.";
char f(char a,int i)
{
	int s;
	if(a=='_')s=0;
	if(a>='a' && a<='z')s=a-'a'+1;
	if(a=='.')s=27;
//	printf("%d ",s);
	s+=i;
	s%=28;
//	printf("%d\n",s);
	return map[s];
	}
int main()
{
	int k;
	while(scanf("%d",&k)&&k)
	{
		char cipher[100],plain[100];
		scanf("%s",cipher);
		int i;
		int n=strlen(cipher);
		int cid[100];
		for(i=0;i<n;i++)cid[i]=k*i%n;
		int dic[100];
		for(i=0;i<n;i++)dic[cid[i]]=i;
		//for(i=0;i<n;i++)printf("%d %d\n",dic[i],cid[i]);printf("\n");
		for(i=0;i<n;i++)plain[cid[i]]=f(cipher[i],i);
		for(i=0;i<n;i++)printf("%c",plain[i]);printf("\n");
		}
	return 0;
	
	}
