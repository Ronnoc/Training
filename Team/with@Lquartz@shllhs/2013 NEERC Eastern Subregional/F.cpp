//kybconnor
#include <cstdio>
int x[111111];
int main(){
	int n,k,p;
	while(~scanf("%d%d%d",&n,&k,&p)){
		int i;
		for(i=1;i<=n-k;i++)x[i]=1;
		int now=2,cnt=0;
		//1-(cnt)/(i-1)>=p/100
		//100(i-1)-100cnt>=(i-1)*p
		while(i<=n){
			if(100*(i-1)-100*cnt>=(i-1)*p)x[i]=now,cnt++;
			else cnt=1,x[i]=++now;
			i++;
		}
		long long ans=0;
		for(i=1;i<=n;i++)ans+=x[i];
		printf("%I64d\n",ans);
		printf("%d",x[1]);
		for(i=2;i<=n;i++)printf(" %d",x[i]);
		printf("\n");
	}
	return 0;
}
