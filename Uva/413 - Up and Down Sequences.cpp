#include<stdio.h>
int main()
{
	 int a[40];
	 while(scanf("%d",&a[1])!=EOF&&a[1])
	 {
			int i;
			for(i=2;i<=30;i++)a[i]=0;
			i=2;
			while(scanf("%d",&a[i])!=EOF)if(!a[i++])break;
			i--;i--;
	//		printf("%d\n",i);
			int len=i;
	//		for(i=1;i<=len;i++)printf("%2d",a[i]);printf("\n");
			int key=0;
			for(i=2;i<=len;i++)
			if(a[i]-a[i-1]!=0){key=i;break;}
			double res[3];
			res[1]=0;res[2]=0;
			
			if(key)
			{
				int s=a[key]-a[key-1];
				int flag=2;
				if(s>0)flag=1;else flag=2;
				int up=0,down=0;
				if(s>0)up++;else down++;
				for(i=2;i<=len;i++)
				{
		//			printf("s=%2d,i=%d,a[i]=%d,a[i-1]=%d,res[1]=%lf,res[2]=%lf,flag=%d\n",s,i,a[i],a[i-1],res[1],res[2],flag);
					if(s*(a[i]-a[i-1])>=0)
					{
						res[flag]+=1;
						}
					else 
					{
						flag=3-flag;
						res[flag]++;
						s=-s;
						if(s>0)up++;else down++;
						}
		//			printf("%d %d\n",up,down);
					}
		//		printf("s=%d,i=%d,a[i]=%d,a[i-1]=%d,res[1]=%lf,res[2]=%lf,flag=%d\n",s,i,a[i],a[i-1],res[1],res[2],flag);
				if(up==0)up++;
				if(down==0)down++;
				res[1]/=up;
				res[2]/=down;
				}
			printf("Nr values = %d:  %lf %lf\n",len,res[1],res[2]);
			}
	return 0;
	}
