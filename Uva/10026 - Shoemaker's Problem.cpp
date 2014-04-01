#include<stdio.h>
#include<string.h>
int main()
{
//	freopen("out.txt","w",stdout);
	struct project{int t;int f;int num;}p[1010],temp;	//t-->time f-->fine
	int k,z,n;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)scanf("%d%d",&p[i].t,&p[i].f);
		for(i=1;i<=n;i++)p[i].num=i;
		int j,s;
	//	for(s=1;s<=n;s++)printf("%d ",p[s].num);printf("\n");
		for(j=1;j<=n;j++)
		{
			for(i=1;i<=n-1;i++)		//±È½Ïp[i]ºÍp[i+1] 
			{
				double pi=(double)p[i].f/p[i].t;
				double pj=(double)p[i+1].f/p[i+1].t;
			//	if(pi<pj||(pi==pj&&p[i].t>p[i+1].t))
			if(pi<pj)
				{
					memcpy(&temp,&p[i],sizeof(project));
					memcpy(&p[i],&p[i+1],sizeof(project));
					memcpy(&p[i+1],&temp,sizeof(project));
					}
			//	printf("%lf,%lf ",pi,pj);
			//	for(s=1;s<=n;s++)printf("%d ",p[s].num);printf("\n");
				}
			}
		printf("%d",p[1].num);
		for(i=2;i<=n;i++)printf(" %d",p[i].num);printf("\n");
		if(k!=z)printf("\n");
		}
//	return main();
	return 0;
	}
