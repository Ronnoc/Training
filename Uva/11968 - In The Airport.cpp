#include<stdio.h>
#include<math.h>
double abs(double a){if(a>0)return a;return -a;}
int find(double *p,int pp,double avg)
{
	int k;
//	printf("find(pp=%d,avg=%lf)\n",pp,avg);
//	for(k=1;k<=pp;k++)printf("p[%d]=%.2lf ",k,p[k]);printf("\n");
	int i,j;
	double temp;
	for(i=1;i<=pp;i++)
	{
		for(j=1;j<pp;j++)
		{
			if(abs(p[j])>abs(p[j+1]))
			{
				temp=p[j];p[j]=p[j+1];p[j+1]=temp;
				}
			else if(abs(p[j])==abs(p[j+1])&&p[j]>0&&p[j+1]<0)
			{
				temp=p[j];p[j]=p[j+1];p[j+1]=temp;
				}
			}
		} 
	return (int)(p[1]+avg);
	}
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		int n,i,j,a[1010];
		scanf("%d",&n);
		int x,c,v,b,pp,qq;
		scanf("%d%d",&pp,&qq);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		x=1;c=pp;v=pp+1;b=pp+qq;		//x~cÊÇ,v~bÊÇ 
		double sum=0; 
		for(i=1;i<=n;i++)sum+=a[i];
		sum/=(double)n;
		double p[1010],q[1010];
		for(i=1;i<=pp;i++){p[i]=a[i];p[i]-=sum;}
		for(i=1;i<=qq;i++){q[i]=a[pp+i];q[i]-=sum;}
		printf("Case #%d: %d %d\n",k,find(p,pp,sum),find(q,qq,sum));
		}
//	return main();
	return 0;
	}
