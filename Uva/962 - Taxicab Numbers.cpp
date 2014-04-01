#include<stdio.h>
#include<time.h>
int main()
{
	int i;
	int j;
	int p,q;
	while(scanf("%d%d",&p,&q)==2)
	{
		int a[100010];
		for(i=0;i<=q;i++)a[i]=0;
		for(i=1;;i++)
		{
			int s=i*i*i;
			if(s>p+q)break;
			for(j=i;;j++)
			{
				int m=s+j*j*j;
				if(m<p)continue;
				if(m>p+q)break;
				a[m-p]+=1;
				}
			}
		int flag=1;
		for(i=0;i<=q;i++)if(a[i]>=2){flag=0;printf("%d\n",i+p);}
		if(flag)printf("None\n");
		}
	return 0;
	}
