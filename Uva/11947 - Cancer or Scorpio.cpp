#include<stdio.h>
int is_run(int year)
{
	if(year%4!=0)return false;
	if(year%100==0&&year%400!=0)return false;
	return true;
	}
int ping[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int run[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int m,d,y;
	int k,z,i,j,sum=0;
//	for(i=1;i<=12;i++)sum+=ping[i];printf("%d\n",sum);sum=0;
//	for(i=1;i<=12;i++)sum+=run[i];printf("%d\n",sum);sum=0;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		scanf("%2d%2d%4d",&m,&d,&y);
		int begin=d;
		if(is_run(y))for(i=1;i<m;i++)begin+=run[i];
		else for(i=1;i<m;i++)begin+=ping[i];
		int res_y=y,res_m=1,res_d;
		begin+=280;
		if(begin>366&&is_run(y) ){begin-=366;res_y++;}
		if(begin>365&&!is_run(y)){begin-=365;res_y++;}
		int end=begin;
		if(is_run(res_y))
		{
			for(res_m=1;end>run[res_m];res_m++)
			{
				end-=run[res_m];
				}
			res_d=end;
			}
		else
		{
			for(res_m=1;end>ping[res_m];res_m++)
			{
				end-=ping[res_m];
				}
			res_d=end;
			}
		printf("%d %02d/%02d/%04d ",k,res_m,res_d,res_y);
		int k=res_m*100+res_d;		//3220
		     if(k>=121&&k<=219)  printf("aquarius");
		else if(k>=220&&k<=320)  printf("pisces");
		else if(k>=321&&k<=420)  printf("aries");
		else if(k>=421&&k<=521)  printf("taurus");
		else if(k>=522&&k<=621)  printf("gemini");
		else if(k>=622&&k<=722)  printf("cancer");
		else if(k>=723&&k<=821)  printf("leo");
		else if(k>=822&&k<=923)  printf("virgo");
		else if(k>=924&&k<=1023) printf("libra");
		else if(k>=1024&&k<=1122)printf("scorpio");
		else if(k>=1123&&k<=1222)printf("sagittarius");
		else 					 printf("capricorn");
		printf("\n");
		}
	return 0;
	}
