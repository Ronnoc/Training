#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int g(int a)
{
	if(a<10)return a;
	else return g(a%10+a/10);
	}
int f(char *a)
{
	int len=strlen(a);
	int i,sum=0;
	for(i=0;i<len;i++)if(a[i]<='z' && a[i]>='a')a[i]+='A'-'a';
	for(i=0;i<len;i++)if(a[i]<='Z'&&a[i]>='A')sum+=a[i]-'A'+1;
	return g(sum);
	}
int main()
{
	char a[100],b[100];
	while(gets(a))
	{
		gets(b);
		int la=strlen(a),lb=strlen(b);
		int i;
		int sua=f(a),sub=f(b);
		//printf("%d %d\n",sua,sub);
		double pre=(double)sua/sub;
		if(pre>1)pre=1/pre;
		pre*=100;
		printf("%.2lf %%\n",pre);
		}
	return 0;
	}
