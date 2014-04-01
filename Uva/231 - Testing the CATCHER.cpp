#include<stdio.h>
#include<string.h>
int main()
{
	int test=1,f1,f2,k,g[100000],i=0;
	g[0]=32768;
	while(scanf("%d",&f1)==1)
	{
		if(f1==-1)
		{
			if(f2==-1)break;
	//		for(k=1;k<=i;k++)printf("%4d",g[k]);
			if(test>=2)printf("\n");
			printf("Test #%d:\n",test++);
			printf("  maximum possible interceptions: %d\n",i);
			memset(g,0,sizeof(g));
			i=0;
			g[0]=32768;
			f2=f1;
			continue;
			}
		int j;
	//	printf("%d %d\n",f1,f2);
		int s=g[i],a=f1;
		if(a<=s){i++;g[i]=a;}
		else 
		{
			for(j=i;j>=1;j--)
			{
				if(g[j-1]>=a){g[j]=a;break;}
		//		for(k=1;k<=i;k++)printf("%4d",g[k]);printf("\n");
				}
			}
		f2=f1;
		}
	return 0;
	}
