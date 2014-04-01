#include<stdio.h>
#define LL long long
LL map[20][110];
LL dp[20][110];
LL m,n;
LL min3(LL a,LL b,LL c){
	LL res=a;
	if(b<res)res=b;
	if(c<res)res=c;
	return res;
	}
int main(){
	while(scanf("%lld%lld",&n,&m)!=EOF){		//nÐÐmÁÐ 
		int i,j;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%lld",&map[i][j]);
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				dp[j][i]=map[j][i];
				if(i!=1){
					int x,y;
					x=j+1;if(x==n+1)x=1;
					y=j-1;if(y==0)y=n;
					dp[j][i]+=min3(dp[x][i-1],dp[j][i-1],dp[y][i-1]);
					}
				}
			}
	/*	for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)printf("%d ",dp[i][j]);
			printf("\n");
			}*/
		LL res=dp[n][m],pr=n;
		for(i=1;i<=n;i++)if(res>dp[i][m])res=dp[i][m],pr=i;
		bool ok[20][110];
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)ok[i][j]=0;
		for(j=m;j>=1;j--){
			for(i=1;i<=n;i++){
				if(j==m){
					if(dp[i][j]==res)ok[i][j]=1;
					}
				else {
					int k;
					for(k=1;k<=n;k++){
						if(ok[k][j+1]){
							LL aim=dp[k][j+1]-map[k][j+1];
							int x,y;
							x=k+1;if(x==n+1)x=1;
							y=k-1;if(y==0)y=n;
							if(dp[x][j]==aim)ok[x][j]=1;
							if(dp[k][j]==aim)ok[k][j]=1;
							if(dp[y][j]==aim)ok[y][j]=1;
							}
						}
					}
				}
			}
		for(j=1;j<=m;j++){
			for(i=1;i<=n;i++){
				if(ok[i][j]){
					if(j!=1)printf(" ");
					printf("%d",i);
					int k;
					int x,y;
						x=i+1;if(x==n+1)x=1;
						y=i-1;if(y==0)y=n;
					for(k=1;k<=n;k++){
						if(k==i||k==x||k==y){
							if(dp[k][j+1]-map[k][j+1]!=dp[i][j])ok[k][j+1]=0;
							}
						else ok[k][j+1]=0;
						}
					break;
					}
				}
			}
		printf("\n%lld\n",res);
		}
	return 0;
	} 
