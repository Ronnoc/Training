#include<stdio.h>
int gcd(int a,int b)
{
	if(a==1) return 1;
	if(b==1) return 1;
	if(a>b) return gcd(b,a-b);
	else if(a==b) return a;
	else return gcd(a,b-a); 
	} 
int main()
{
	int  g[510];g[0]=0;g[1]=0;
	int i,j;
	for(i=2;i<=500;i++)
	{
		g[i]=g[i-1];
		for(j=1;j<i;j++)g[i]+=gcd(j,i);
		}
	while(scanf("%d",&i)==1)
	{
		if(i==0)break;
		else printf("%d\n",g[i]); 
		} 
	return 0;
	}
	/*
int main()
{
	int z,x;
	int k;
	scanf("%d",&k);
	
	for(z=1;z<=k;z++)
	{
		int i,j,g=0;
		for(i=1;i<z;i++)
		{
			for(j=i+1;j<=z;j++)
			{
				g+=gcd(i,j);
				}
			}
		printf("%d:%d\n",z,g);
		}
		
	//for(z=1;z<=k;z++)for(x=z;x<=k;x++)printf("gcd(%d,%d)=%d\n",x,z,gcd(x,z));
	return main();
	}
*/
