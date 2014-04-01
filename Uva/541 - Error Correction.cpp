#include<stdio.h>
#include<string.h>
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n==0)break;
		int map[110][110],i,j; 
		int row[110],line[110];
		int r[110],l[110];
		for(i=1;i<=n;i++)
		{
			row[i]=0;
			line[i]=0;
			r[i]=0;
			l[i]=0;
			}
		int tx,ty;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&map[i][j]);
				}
			} 
		/*
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%d",map[i][j]);
				}
			printf("\n");
			} 
		*/
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				line[i]+=map[i][j];
				row[i]+=map[j][i]; 
			//	printf("line[%d]+=map[%d][%d] => %d\n",i,i,j,line[i]);
			//	printf("row[%d]+=map[%d][%d] => %d\n",i,j,i,row[i]);
				}
			if(row[i]%2==1){r[i]=1;ty=i;}
			if(line[i]%2==1){l[i]=1;tx=i;}
			}	
	//	for(i=1;i<=n;i++)printf("r[%d]=%d l[%d]=%d\n",i,r[i],i,l[i]);
		int sumr=0,suml=0;
		for(i=1;i<=n;i++)
		{
			sumr+=r[i];
			suml+=l[i];
			//("%d %d\n",r[i],l[i]);
			}
		if(sumr==0 && suml==0)printf("OK\n");
		else if(sumr==1 && suml==1)printf("Change bit (%d,%d)\n",tx,ty);
		else printf("Corrupt\n");
		//printf("%d %d\n",sumr,suml);
		}
	return 0;
	} 
