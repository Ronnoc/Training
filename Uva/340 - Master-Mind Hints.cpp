#include<stdio.h>
#include<stdlib.h>	
int s;
int cmp_int(const void *_a,const void *_b)
{
	int *a=(int *)_a;
	int *b=(int *)_b;
	return *a-*b;
	} 
void del(int *a,int k)
{
	int i;
	for(i=k;i<=s;i++)a[i]=a[i+1];
	}
int main()
{
	int t=1;
	while(scanf("%d",&s)==1 && s!=0)
	{
		printf("Game %d:\n",t++);
		int code[1010],i;
		for(i=1;i<=s;i++)scanf("%d",&code[i]);
		while(1)
		{
			int guess[1010];
			int temp[1010];
			for(i=1;i<=s;i++){scanf("%d",&guess[i]);temp[i]=code[i];}
			int sum=0;
			for(i=1;i<=s;i++)sum+=guess[i];
			if(sum==0)break;
			int a=0,b=0;
			int j,_del=0;
			for(i=1;i<=s-_del;i++)
			{
				if(guess[i]==temp[i])
				{
					del(guess,i);
					del(temp,i);
					_del++;a++;i--;
					}
				}
		//	for(j=1;j<=s;j++)printf("%d\t",temp[j]);printf("\n");
		//	for(j=1;j<=s;j++)printf("%d\t",guess[j]);printf("\n");
			qsort(&temp[1],s-_del,sizeof(int),cmp_int);
			qsort(&guess[1],s-_del,sizeof(int),cmp_int);
		//	for(j=1;j<=s;j++)printf("%d\t",temp[j]);printf("\n");
		//	for(j=1;j<=s;j++)printf("%d\t",guess[j]);printf("\n");
			for(i=1;i<=s-_del;i++)
			{
				for(j=1;j<=s-_del;j++)
				{
					if(guess[i]==temp[j])
					{
					int z;
					del(guess,i);
					del(temp,j);
					_del++;b++;i--;
						} 
				//for(j=1;j<=s;j++)printf("%d\t",guess[j]);printf("\n");
				//for(j=1;j<=s;j++)printf("%d\t",temp[j]);printf("\n");
					}
				}
			printf("    (%d,%d)\n",a,b);
			}
		}
	return 0;
	}
