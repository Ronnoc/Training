#include<stdio.h>
int main()
{
	int a[70];
	int i;
	while(scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6])!=EOF && !(!a[1]&&!a[2]&&!a[3]&&!a[4]&&!a[5]&&!a[6]))
	{
		int res=0;
		res+=a[6]+a[5]+a[4];
		a[2]-=a[4]*5;
		int kong=a[5]*11;
		int s=(a[3]+3)/4;res+=s;
		int p=0;
		if(a[3]%4==3){p=1;kong+=5;}
		if(a[3]%4==2){p=3;kong+=6;}
		if(a[3]%4==1){p=5;kong+=7;}
		a[2]-=p;
		if(a[2]<0){a[2]=-a[2];kong+=a[2]*4;a[2]=0;}
		s=(a[2]+8)/9;res+=s;
		s=a[2]%9;
		if(s!=0)s=9-s;else s=0; 
		s*=4;
		kong+=s;
		a[1]-=kong;
		if(a[1]<0)a[1]=0;
		res+=(a[1]+35)/36;
		printf("%d\n",res);
		}
//	return main();
	return 0;
	}
