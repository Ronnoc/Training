#include<stdio.h>
#include<math.h>
int len(int n)
{
	int i=0;
	while(n!=0){n/=10;i++;}
	return i;
	}
double log2(double a)
{
	return log(a)/log(2);
	}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int p=len(n)+1;
		int e,res;
//		double q=floor(log2(n))+1;
//		printf("%d\n",p);
	//	if(p==len(n))p+=1;
		for(;;p++)
		{
			int flag=0;
			double xqj=log2(n)+p*log2(10);
			double sqj=log2(n+1)+p*log2(10);
			for(e=(int)xqj-1;e<sqj;e++)
			{
				if(e>=xqj){res=e;/*printf("%lf\t%lf\n",xqj,sqj);*/flag=1;}
				}
			if(flag)break; 
			}
		printf("%d\n",res);
		}
	return 0;
	}
