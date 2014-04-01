#include<stdio.h>
#include<string.h>
int f();
int sv[11],cc[1010];
int main()
{
	int k,z;
	scanf("%d",&z);
	getchar();getchar();
	for(k=1;k<=z;k++){f();if(k!=z)printf("\n"); }
	return 0;
	} 
void check()
{
	int i;
	for(i=0;i<=9;i++)sv[i]%=1000;
	for(i=0;i<=999;i++)cc[i]%=1000;
	}
int f()
{
	int res=0;
	int i;
	for(i=0;i<=9;i++)sv[i]=0;
	for(i=0;i<=999;i++)cc[i]=0;
	char c;
	char p,q,r;
	int b,n,m;
	int count=0;
	char edc[100];
	while(gets(edc))
	{
		p=edc[0];
		q=edc[1];
		r=edc[2];
		b=p-'0';
		n=q-'0';
		m=r-'0';
if(p=='\0' || strlen(edc)!=3){break;}
		cc[count++]=b*100+n*10+m;
		}
	count--;
	//printf("%d",count);
	i=0;
	while(1)
	{
	//if(i>999)break;
	//printf("cc[%d]=%d\n",i,cc[i]);
	//for(int j=0;j<=9;j++)printf("sv[%d]=%d",j,sv[j]);printf("\n");
	int n,b,d;
	b=cc[i]/100;
	n=cc[i]%10;
	d=(cc[i]-b*100)/10; 
	check();
	if(b==1){res+=1;break;}
	if(b==2){sv[d]=n;check();res+=1;}
	if(b==3){sv[d]+=n;check();res+=1;}
	if(b==4){sv[d]*=n;check();res+=1;}
	if(b==5){int s=n;sv[d]=sv[s];check();res+=1;}
	if(b==6){int s=n;sv[d]+=sv[n];check();res+=1;}
	if(b==7){int s=n;sv[d]*=sv[n];check();res+=1;}
	if(b==8){int a=n;sv[d]=cc[sv[a]];check();res+=1;}
	if(b==9){int s=d,a=n;cc[sv[a]]=sv[s];res+=1;}
	if(b==0){int s=n;res+=1;if(sv[s]!=0){i=sv[d]-1;}}
	i++;
	check();
	}
	printf("%d\n",res);
	return 0;
	}
