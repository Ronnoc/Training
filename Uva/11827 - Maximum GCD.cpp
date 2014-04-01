#include<stdio.h>
#include<string.h> 
int gcd(int a,int b)
{
	if(a==0)return b;
	if(b==0)return a;
	int t;
	if(a<b)
	{
		return gcd(b%a,a);
		}
	return gcd(a%b,b);
	}
int main()
{
	int k,z;
	scanf("%d",&z);getchar();
	for(k=1;k<=z;k++)
	{
		int a[110],i=1,j=1,p;char c;
		for(i=1;i<=100;i++)a[i]=0;
		char s[1000000];
		gets(s);
		int len=strlen(s);
		for(i=0;i<len-1;i++)
		{
			if(s[i]==' '&&s[i+1]!=' '){j++;continue;}
			if(s[i]!=' ')
			{
				a[j]*=10;
				a[j]+=s[i]-'0';
				}
		//	for(p=1;p<=j;p++)printf("%d ",a[p]);printf("\t%d\n",i);
			}
		if(s[len-1]!=' ')
		{
			a[j]*=10;
			a[j]+=s[len-1]-'0';		
			}
		int n=j,b;
//		for(i=1;i<=n;i++)printf("%d ",a[i]); printf("\n");
		int max=0;
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				b=gcd(a[i],a[j]);
				if(b>max)max=b;
				}
			}
		printf("%d\n",max);
		}
//	return main();
	return 0;
	}
