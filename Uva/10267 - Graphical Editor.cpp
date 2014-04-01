#include<stdio.h>
#include<stdlib.h>
char nm[270][270];
bool nnmm[270][270];
int m,n;
int min(int x,int y)
{
	if(x>y)return y;
	return x;
	}
int max(int x,int y)
{
	if(x<y)return y;
	return x;
	}
void f(int y,int x,char s,char c)
{
	nm[y][x]=c;nnmm[y][x]=0;
	if(y>1 && nm[y-1][x]==s && nnmm[y-1][x])f(y-1,x,s,c);
	if(x>1 && nm[y][x-1]==s && nnmm[y][x-1])f(y,x-1,s,c);
	if(x<m && nm[y][x+1]==s && nnmm[y][x+1])f(y,x+1,s,c);
	if(y<n && nm[y+1][x]==s && nnmm[y+1][x])f(y+1,x,s,c);
	} 
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char s;
	int i,j;
	for(i=0;i<=250;i++)
			{
				for(j=0;j<=250;j++){nm[i][j]='O';nnmm[i][j]=1;}
				}
	while(scanf("%c",&s)!=EOF && s!='X')
	{
		if(s=='I')
		{
			scanf("%d%d",&m,&n);
			for(i=0;i<=250;i++)
			{
				for(j=0;j<=250;j++)nm[i][j]='O';
				}
			}
		else if(s=='C')
		{
			for(i=0;i<=250;i++)
			{
				for(j=0;j<=250;j++)nm[i][j]='O';
				}
			}
		else if(s=='L')
		{
			int p,q;char w;
			scanf("%d%d %c",&p,&q,&w);
			nm[q][p]=w;
			}
		else if(s=='V')
		{
			int x,y1,y2;char c;
			scanf("%d%d%d %c",&x,&y1,&y2,&c);
			for(i=min(y1,y2);i<=max(y1,y2);i++)nm[i][x]=c;	
			}
		else if(s=='H')
		{
			int x1,x2,y;char c;
			scanf("%d%d%d %c",&x1,&x2,&y,&c);
			for(i=min(x1,x2);i<=max(x1,x2);i++)nm[y][i]=c;	
			}
		else if(s=='K')
		{
			int x1,x2,y1,y2;char c;
			scanf("%d%d%d%d %c",&x1,&y1,&x2,&y2,&c);
			for(i=min(x1,x2);i<=max(x1,x2);i++)
			{
				for(j=min(y1,y2);j<=max(y1,y2);j++)nm[j][i]=c;
				}
			}
		else if(s=='F')
		{
			int x,y;char c,q;
			scanf("%d%d %c",&x,&y,&c);
			q=nm[y][x];
			for(i=0;i<=250;i++)
			{
				for(j=0;j<=250;j++){nnmm[i][j]=1;}
				}
			f(y,x,q,c);
			}
		else if(s=='S')
		{
			char d[1000];
			scanf("%s",d);
			printf("%s\n",d);
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)printf("%c",nm[i][j]);
				printf("\n");
				}
			}
		else continue;
		}
	return 0;
	} 
