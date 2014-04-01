#include<stdio.h>
int m,n,t;
int main()
{
	while(scanf("%d%d%d",&m,&n,&t)!=EOF)
	{
		int i,j,k,temp;
		if(m>n){temp=m;m=n;n=temp;}		//∫„”–m<=n 
		k=t/n;
		int res=k,cha=t-k*n;
	//	printf("res=%d cha=%d\n",res,cha);
		for(i=k;i>=0;i--)
		{
			for(j=0;;j++)
			{
				int s=i*n+j*m;
				if(s>t)break;
				if(t-s<cha){cha=t-s;res=i+j;}
				else if(t-s==cha)
				{
					if(res<i+j)res=i+j;
					}
		//		printf("cha=%d,t=%d,s=%d,res=%d,i=%d,j=%d\n",cha,t,s,res,i,j);
				}
			}
		if(cha==0)printf("%d\n",res);
		else printf("%d %d\n",res,cha);
		} 
	return 0;
	}
