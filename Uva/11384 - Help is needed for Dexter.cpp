#include<stdio.h>
#include<math.h>
int a[50000010];
int main()
{
	int n;
	double ln2=log(2);
	while(scanf("%d",&n)!=EOF)
	{
		double nn=log(n);
		nn/=ln2;
		nn=floor(nn+1);
		printf("%.0lf\n",round(nn));
		}
	return 0;
	}
