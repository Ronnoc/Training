//kybconnor
#include <cstdio>
#include <cstring>
int mx[33][33];
int n;
int a[33][33];
int main(){
	int i,j;
	while(~scanf("%d",&n)){
		if(n==0)break;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&mx[i][j]);
		int tot[10];
		memset(tot,0,sizeof tot);
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i][j]==mx[i][j])tot[0]++;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i][j]==mx[j][n-i+1])tot[1]++;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i][j]==mx[n-j+1][i])tot[2]++;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i][j]==mx[n-i+1][n-j+1])tot[3]++;
		int res=0;
		for(i=0;i<4;i++)if(tot[i]>res)res=tot[i];
		printf("%d\n",res);
	}
	return 0;
}
