#include<stdio.h>
#include<stdlib.h>
int cmp(const void *aa,const void *bb)
{
	int *a=(int *)aa;
	int *b=(int *)bb;
	return *b-*a; 
	} 
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0 && m==0)break;
		int dra[20010],man[20010];
		bool gua[20010],sha[20010];
		int i;
		for(i=1;i<20010;i++){gua[i]=0;sha[i]=0;}
		for(i=1;i<=n;i++)scanf("%d",&dra[i]);
		for(i=1;i<=m;i++)scanf("%d",&man[i]);
		qsort(&dra[1],n,sizeof(int),cmp);
		qsort(&man[1],m,sizeof(int),cmp);
		int gon=1,hum=1,res=0;
		for(gon=1;gon<=n;gon++)
		{
			for(hum=m;hum>=1;hum--)
			{
				if(!sha[hum] && !gua[gon] && man[hum]>=dra[gon])
				{
					res+=man[hum];
					gua[gon]=1;
					sha[hum]=1;
					}
				}
			}
		int sum=0;
		for(i=1;i<=n;i++)sum+=gua[i];
		if(sum==n)printf("%d\n",res);
		else printf("Loowater is doomed!\n");
		}
	return 0;
	} 
