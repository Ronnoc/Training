#include<stdio.h>
int f(int n,int *b)
{
	int a[40],m=n;
	if(n==0)return 1;
	int i,weizhi=1;
	for(i=1;i<40;i++)a[i]=0;
	while(1)
	{
		if(m==0)break;
		if(m%2==0)a[weizhi++]=0;
		else {m-=1;a[weizhi++]=1;}
		m/=2;
		}
	weizhi--;
	for(i=1;i<=weizhi;i++)b[i]=a[i];
	return weizhi;
	}
int g(int a,int b)
{
	int c=a+b;
	if(c==2)return 0;
	return c;
	}
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int a[40],b[40],c[40],d=0;
		int i;
		for(i=1;i<40;i++){a[i]=0;b[i]=0;c[i]=0;}
		int aa=f(m,a);
		int bb=f(n,b);
		for(i=1;i<40;i++)
		{
			c[i]=g(a[i],b[i]);
			}
		int cc=40;
		for(i=39;i>=1;i--)
		{
			if(c[i]!=0)break;
			}
		cc=i;
		d=0;
		for(i=cc;i>=1;i--)
		{
			d*=2;
			d+=c[i];
			}
		//for(i=aa;i>=1;i--)printf("%d",a[i]);printf("\n");
		//for(i=bb;i>=1;i--)printf("%d",b[i]);printf("\n");
		//for(i=cc;i>=1;i--)printf("%d",c[i]);printf("\n");
		printf("%d\n",d);
		}
	return 0;
	}
