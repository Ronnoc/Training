#include<stdio.h>
#include<string.h>
bool a[11];
char ro[100]="right on";
char th[100]="too high";
char tl[100]="too low";
void check(char *x,int k)
{
	int i;
	if(strcmp(tl,x)==0)
	{
		for(i=1;i<=k;i++)a[i]=0;
		}
	if(strcmp(th,x)==0)
	{
		for(i=k;i<=10;i++)a[i]=0;
		}
	}
int main()
{
	char x[100];

	int k,i;
	while(scanf("%d",&k)!=EOF&&k)
	{
		for(i=1;i<=10;i++)a[i]=1;
		getchar();
		gets(x);
		while(strcmp(x,ro)!=0)
		{
			check(x,k);
			scanf("%d",&k);getchar();
			gets(x);
			check(x,k);
			}
		if(a[k])printf("Stan may be honest\n");else printf("Stan is dishonest\n"); 
		}
	return 0;
	}
