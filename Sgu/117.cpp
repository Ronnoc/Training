#include<stdio.h>
int a[20][10010];
int main(){
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%d",&a[1][i]);
			a[1][i]%=k;
			for(j=2;j<=14;j++){
				a[j][i]=a[j-1][i]*a[j-1][i];
				a[j][i]%=k;
				}
			}
		int res=0;
		int plus[20];
		for(i=1;i<=14;i++){
			if(m%2==1)plus[i]=1;
			else plus[i]=0;
			m/=2;
			}
		for(i=1;i<=n;i++){
			int x=1;
			for(j=1;j<=14;j++)if(plus[j]){
				x*=a[j][i];
				x%=k;
				}
			if(x==0)res++;
			}
		printf("%d\n",res);
		}
	return 0;
	}
