#include<stdio.h>
#include<string.h>
int dic[30]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4,1};
int main()
{
	int z,k;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		char a;	int res=0;int flag=1;
		while(a=getchar())
		{
		if(flag!=1&&a=='\n')break;
		if(a==' ')a='a'+26;
		res+=dic[ a-'a' ];
		flag++;
		}
		printf("Case #%d: %d\n",k,res);
		}
	return 0;}
