#include<stdio.h>
#include<string.h>
int f(char a)
{
	return a-'0';
	}
int main()
{
	char aa[200],bb[200];
	while(scanf("%s%s",aa,bb)!=EOF)
	{
		int lena=strlen(aa),lenb=strlen(bb);int a,b;
		if(lena==1 && aa[0]=='0'&&lenb==1 && bb[0]=='0')break;
	if(lena>=2)a=f(aa[lena-1])+10*f(aa[lena-2]);else a=f(aa[lena-1]);
	if(lenb>=2)b=f(bb[lenb-1])+10*f(bb[lenb-2]);else b=f(bb[lenb-1]);
		a%=10;int res=0;
		if(a==0 || a==1 || a==5 ||a==6)res=a;
		if(a==2)
		{
			if(b%4==1)res=2;
			if(b%4==2)res=4;
			if(b%4==3)res=8;
			if(b%4==0)res=6;	
			}
		if(a==3)//3,9,7,1
		{
			if(b%4==1)res=3;
			if(b%4==2)res=9;
			if(b%4==3)res=7;
			if(b%4==0)res=1;
			}
		if(a==4)//4,6
		{
			if(b%2==1)res=4;
			else res=6;
			}
		if(a==7)//7,9,3,1					//789
		{
			if(b%4==1)res=7;
			if(b%4==2)res=9;
			if(b%4==3)res=3;
			if(b%4==0)res=1;
			}	
		if(a==8)//8,4,2,6 
		{
			if(b%4==1)res=8;
			if(b%4==2)res=4;
			if(b%4==3)res=2;
			if(b%4==0)res=6;
			}		
		if(a==9)//9,1
		{
			if(b%2==1)res=9;
			else res=1;
			}		
		printf("%d\n",res);
		}
	return 0;
	} 
