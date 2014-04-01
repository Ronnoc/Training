#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int k;
		int x,y;
		for(k=1;k<=n;k++)
		{
			scanf("%d%d",&x,&y);
			x-=a;y-=b; 
			     if(x==0 || y==0)printf("divisa\n");
			else if(x>0 && y>0)printf("NE\n");
			else if(x>0 && y<0)printf("SE\n");
			else if(x<0 && y>0)printf("NO\n");
			else if(x<0 && y<0)printf("SO\n");
			}
		}
	return 0;
	}
