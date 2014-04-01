#include<stdio.h>
int main()
{
	int x,y,z,k;
	scanf("%d",&k);
	int max,min,i;
	for(i=1;i<=k;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		max=x>y?x:y;
		min=x+y-max;
		max=z>max?z:max;
		min=z>min?min:z;
		printf("Case %d: %d\n",i,x+y+z-max-min); 
		
		}
	return 0;
	}
