#include<stdio.h>
#include<string.h>
int main()
{
//	freopen("in.txt","r",stdin);
	char a[1000000],b[1000000];
	while(scanf("%s%s",a,b)!=EOF)
	{
		int la=strlen(a),lb=strlen(b);
		int i=0,j;
		for(j=0;j<lb;j++)
		{
			if(i==la)break;
			if(b[j]==a[i])i++;
			}
		if(i==la)printf("Yes\n");else printf("No\n");
		}
//	return main();
	return 0;
	}
