#include<stdio.h>
int main()
{
	int z,x;
	int l,g;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		int flag=1;
		scanf("%d%d",&g,&l);
		if(l%g!=0){flag=0;printf("-1\n");}
		else
		{
			int s=l/g;
			printf("%d %d\n",g,l);			
			}
		}
	return 0;
	}
