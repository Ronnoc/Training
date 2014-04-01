#include <cstdio>
#include <cmath>
const int MXN=1000000;
bool isp[MXN+10];
int main(){
	long long i,j,sn=sqrt(MXN);
	for(i=3,isp[2]=1;i<=MXN;i++)isp[i]=i%2;
	for(i=3;i<=sn;i++)if(isp[i])for(j=i*i;j<=MXN;j+=2*i)isp[j]=0;
	int n;
	while(~scanf("%d",&n)){
		int tot=0;
		for(i=3;i+2<=n;i+=2)if(isp[i]&&isp[i+2])tot++;
		printf("%d\n",tot);
		for(i=3;i+2<=n;i+=2)if(isp[i]&&isp[i+2])printf("2 %d\n",i);
	}
	return 0;
}
