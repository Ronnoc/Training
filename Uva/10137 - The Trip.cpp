#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void *aa,const void *bb)
{
	int *a=(int *)aa;
	int *b=(int *)bb;
	return *a-*b;
	}
int max(int a,int b){if(a>b)return a;return b;}
int min(int a,int b){if(a>b)return b;return a;}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n==0)break;
		double a[1010],sum=0,avg;
		int i;
		for(i=1;i<=n;i++)scanf("%lf",&a[i]);
	//	for(i=1;i<=n;i++)printf("a[%d]=%lf\n",i,a[i]);
		int f[1010],res=0;
		for(i=1;i<=n;i++){f[i]=round(a[i]*100);sum+=f[i];}
		qsort(&f[1],n,sizeof(int),cmp);
		//for(i=1;i<=n;i++)printf("f[%d]=%d\n",i,f[i]);
		avg=sum/n;
		int money=0,give=0,earn=0;
		if((double)((int)avg)==avg)
		{
			int s=avg;
			for(i=1;i<=n;i++)
			{
				if(f[i]<s)res+=s-f[i];
				} 
			} 
		else
		{
			int in=floor(avg),ax=in+1,s=0;
			//printf("%d\t%d\n",in,ax);
			for(i=1;i<=n;i++)
			{
				if(f[i]<avg)res+=min(abs(f[i]-ax),abs(f[i]-in));
				else if(f[i]>avg)s+=min(abs(f[i]-ax),abs(f[i]-in));
				}
				res=max(res,s);
			}
		printf("$%d.%02d\n",res/100,res%100);
		}
	return 0;
	} 
