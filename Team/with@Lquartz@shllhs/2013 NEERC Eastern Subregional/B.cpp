//kybconnor
#include <cstdio>
int a[11111],n,k;
int main(){
	while(~scanf("%d%d",&n,&k)){
		int i;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		int big=0,sml=0;
		for(i=1;i<=n;i++){
			if(a[i]>=k)big+=a[i]-k;
			else sml+=k-a[i];
		}
		printf("%d %d\n",big,sml);
	}
	return 0;
}
