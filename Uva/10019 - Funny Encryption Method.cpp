#include<math.h>
#include<stdio.h>
int pow2(int k)
{
	int i=1,res=1;
	for(i=1;i<=k;i++)res*=2;
	return res;
	}
int f(int a)
{
	double ln2=log(2);
	double lna=log(a);
	int res=0,i;
	for(i=round(lna/ln2)+1;i>=0;i--)
	{
		if(a>=pow2(i)){a-=pow2(i);res++;}
		}
	return res;
	}
int htoo(int a)
{
	int q,w,e,r;
	r=a%10;
	a/=10;
	e=a%10;
	a/=10;
	w=a%10;
	a/=10;
	q=a%10;
	int res=0;
	res+=q;
	res*=16;
	res+=w;
	res*=16;
	res+=e;
	res*=16;
	res+=r;	
	return res;
	}
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		int n;
		scanf("%d",&n);
		printf("%d %d\n",f(n),f(htoo(n)));
		}
	return 0;
	
	}
