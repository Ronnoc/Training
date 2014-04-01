#include<stdio.h>
#include<string.h>
int main()
{
//	freopen("out.txt","w",stdout);
	int k,z;
	scanf("%d",&z);
	char m[10][10];
	for(k=1;k<=z;k++)
	{
		int i;
		for(i=0;i<=2;i++)scanf("%s",m[i]);
		int flago=0,flagx=0,countx=0,counto=0;
		if(m[0][0]=='X'&&m[0][0]==m[0][1]&&m[0][0]==m[0][2])flagx++;
		if(m[1][0]=='X'&&m[1][0]==m[1][1]&&m[1][0]==m[1][2])flagx++;
		if(m[2][0]=='X'&&m[2][0]==m[2][1]&&m[2][0]==m[2][2])flagx++;
		if(m[0][0]=='X'&&m[0][0]==m[1][0]&&m[0][0]==m[2][0])flagx++;
		if(m[0][1]=='X'&&m[0][1]==m[1][1]&&m[0][1]==m[2][1])flagx++;
		if(m[0][2]=='X'&&m[0][2]==m[1][2]&&m[0][2]==m[2][2])flagx++;
		if(m[0][0]=='X'&&m[0][0]==m[1][1]&&m[0][0]==m[2][2])flagx++;
		if(m[0][2]=='X'&&m[0][2]==m[1][1]&&m[0][2]==m[2][0])flagx++;
		
		if(m[0][0]=='O'&&m[0][0]==m[0][1]&&m[0][0]==m[0][2])flago++;
		if(m[1][0]=='O'&&m[1][0]==m[1][1]&&m[1][0]==m[1][2])flago++;
		if(m[2][0]=='O'&&m[2][0]==m[2][1]&&m[2][0]==m[2][2])flago++;
		if(m[0][0]=='O'&&m[0][0]==m[1][0]&&m[0][0]==m[2][0])flago++;
		if(m[0][1]=='O'&&m[0][1]==m[1][1]&&m[0][1]==m[2][1])flago++;
		if(m[0][2]=='O'&&m[0][2]==m[1][2]&&m[0][2]==m[2][2])flago++;
		if(m[0][0]=='O'&&m[0][0]==m[1][1]&&m[0][0]==m[2][2])flago++;
		if(m[0][2]=='O'&&m[0][2]==m[1][1]&&m[0][2]==m[2][0])flago++;
		int res=1,j;
		if(flago>0&&flagx>0)res=0;
		if(flagx>=3)res=0;
//	for(i=0;i<=2;i++)printf("%s\n",m[i]);
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=2;j++)
			{
				if(m[i][j]=='O')counto++;
				if(m[i][j]=='X')countx++;
				}
			}
		if(flago>0&&countx!=counto)res=0;
		if(flagx>0&&countx!=counto+1)res=0;
		if(countx-counto>=2)res=0;
		if(counto>countx)res=0;
		if(res)printf("yes\n");
		else printf("no\n");
//		printf("\n"); 
		}
	return 0;
	}
