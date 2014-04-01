#include<stdio.h>
int main()
{
	struct xy{int x,y,s;}k,q,qq;
	while(scanf("%d%d%d",&k.s,&q.s,&qq.s)!=EOF)
	{
		k.x=k.s%8;k.y=k.s/8;
		q.x=q.s%8;q.y=q.s/8;
		qq.x=qq.s%8;qq.y=qq.s/8;
		int map[10][10];
		int i,j;
		for(i=0;i<8;i++)for(j=0;j<8;j++)map[i][j]=0;
		map[k.x][k.y]=-10;
		if(k.x>=1)map[k.x-1][k.y]=-5;
		if(k.y>=1)map[k.x][k.y-1]=-5;
		if(k.x<=6)map[k.x+1][k.y]=-5;
		if(k.y<=6)map[k.x][k.y+1]=-5;
	if(map[q.x][q.y]==-10){printf("Illegal state\n");continue;}
		map[q.x][q.y]=10;
	for(i=1;i<8;i++)
		{
			if(q.x+i<=7)
			{
				if(map[q.x+i][q.y]==-10)break;
				else if(map[q.x+i][q.y]==-5)map[q.x+i][q.y]=20;
				else map[q.x+i][q.y]=5;
				}
			else break;
			}
	for(i=1;i<8;i++)
		{
			if(q.x-i>=0)
			{
				if(map[q.x-i][q.y]==-10)break;
				else if(map[q.x-i][q.y]==-5)map[q.x-i][q.y]=20;
				else map[q.x-i][q.y]=5;
				}
			else break;
			}
	for(i=1;i<8;i++)
		{
			if(q.y+i<=7)
			{
				if(map[q.x][q.y+i]==-10)break;
				else if(map[q.x][q.y+i]==-5)map[q.x][q.y+i]=20;
				else map[q.x][q.y+i]=5;
				}
			else break;
			}
	for(i=1;i<8;i++)
		{
			if(q.y-i>=0)
			{
				if(map[q.x][q.y-i]==-10)break;
				else if(map[q.x][q.y-i]==-5)map[q.x][q.y-i]=20;
				else map[q.x][q.y-i]=5;
				}
			else break;
			}			
	if(map[qq.x][qq.y]==20){printf("Move not allowed\n");continue;}		
	if(map[qq.x][qq.y]!=5){printf("Illegal move\n");continue;}	
		for(i=0;i<8;i++)for(j=0;j<8;j++)map[i][j]=0;
		map[k.x][k.y]=-10;
		map[qq.x][qq.y]=10;
		if(k.x>=1)map[k.x-1][k.y]=1;
		if(k.y>=1)map[k.x][k.y-1]=1;
		if(k.x<=6)map[k.x+1][k.y]=1;
		if(k.y<=6)map[k.x][k.y+1]=1;
	for(i=1;i<8;i++){if(qq.x+i<=7){map[qq.x+i][qq.y]=0;}else break;}
	for(i=1;i<8;i++){if(qq.y+i<=7){map[qq.x][qq.y+i]=0;}else break;}
	for(i=1;i<8;i++){if(qq.x-i>=0){map[qq.x-i][qq.y]=0;}else break;}
	for(i=1;i<8;i++){if(qq.y-i>=0){map[qq.x][qq.y-i]=0;}else break;}
		int flag=0;
		if(k.x>=1&&map[k.x-1][k.y])flag=1;
		if(k.y>=1&&map[k.x][k.y-1])flag=1;
		if(k.x<=6&&map[k.x+1][k.y])flag=1;
		if(k.y<=6&&map[k.x][k.y+1])flag=1;
		if(flag)printf("Continue\n");
		else printf("Stop\n");
		}
	return 0;
	}
