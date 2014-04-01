#include<stdio.h>
#include<string.h>
int hh[1010],mm[1010],ss[1010];
double h[1010],m[1010],s[1010];
int main()
{
	int k=1,zhiv=0,i=0;
	double l=0,v=0,j,res=0;
	for(i=0;i<=1000;i++)
	{hh[i]=mm[i]=ss[i]=0;h[i]=s[i]=m[i]=0;}
	while(scanf("%d:%d:%d",&hh[k],&mm[k],&ss[k])!=EOF)
	{
		h[k]=hh[k];m[k]=mm[k];s[k]=ss[k];
		char c;
		c=getchar(); 
		if(c=='\n')
		{
			printf("%02d:%02d:%02d %.2lf km\n",hh[k],mm[k],ss[k],res+v*(h[k]-h[zhiv])+ v/60*(m[k]-m[zhiv]) + v/3600*(s[k]-s[zhiv]));
			//printf("%lf\n%lf\n%lf\n%lf\n",v*s[k],v*s[zhiv],s[k],s[zhiv]);
			}
		else 
		{
			if(k>=1)res+=( h[k]-h[zhiv]+(m[k]-m[zhiv])/60+(s[k]-s[zhiv])/3600 )*v;
			scanf("%lf",&v);
			//printf("%lf\n",v);
			zhiv=k;
			}
		k++;
		}
	return 0;
	}
