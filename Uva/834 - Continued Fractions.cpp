#include<stdio.h>
#include<math.h>
int main()
{
	int p,q;
	while(scanf("%d%d",&p,&q)==2)
	{
		int a[100000];a[1]=0; 
		int i,wz=0;
		while(1)
		{
			a[wz++]=p/q;
			int z=p,x=q;
			z-=(int)(p/q)*q;
			p=q;q=z;
			if(q==0)break;
			}
		wz--;
		printf("[%d",a[0]);
		for(i=1;i<=wz;i++){if(i==1)printf(";%d",a[i]);else printf(",%d",a[i]);}
		printf("]\n");
		}
	return 0;
	}
