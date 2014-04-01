#include<stdio.h>
int min(int a,int b)
{
	if(a>b)return b;
	return a;
	}
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		getchar();
		char c;
		scanf("%c",&c);
		int m,n;
		scanf("%d%d",&m,&n);
		if(c=='r'||c=='Q')printf("%d\n",min(m,n));
		if(c=='k')
		{
			if(m*n%2==0)printf("%d\n",m*n/2);
			else printf("%d\n",(m*n+1)/2);
			}
		if(c=='K')
		{
			if(m%2==1)m++;
			if(n%2==1)n++;
			m/=2;
			n/=2;
			printf("%d\n",m*n);
			}
		}
//	printf("!");
	return 0;
	}
