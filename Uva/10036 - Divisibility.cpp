#include<stdio.h>
int a[10010];
int dp[10010][110];
int main(){
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		int n,p;
		scanf("%d%d",&n,&p);
		int i,j;
		for(i=1;i<=n;i++){
			int t;
			scanf("%d",&t);
			t%=p;
			if(t<0)t+=p;
			a[i]=t;
			}
		for(i=0;i<=n;i++)for(j=0;j<p;j++)dp[i][j]=0;
		dp[0][0]=1;
		for(i=1;i<=n;i++){
			for(j=0;j<p;j++){
				if(dp[i-1][j]){
					if(j-a[i]>=0)dp[i][j-a[i]]=1;//printf("(%d,%d) ",i,j-a[i]);}
					else dp[i][j-a[i]+p]=1;//printf("(%d,%d) ",i,j-a[i]+p);}
					if(j+a[i]<p)dp[i][j+a[i]]=1;//printf("(%d,%d) ",i,j+a[i]);}
					else dp[i][j+a[i]-p]=1;//printf("(%d,%d) ",i,j+a[i]-p);}
					}
				}
			}
//		for(i=1;i<=n;i++)printf("%2d",a[i]);printf("\n");
	//	for(i=0;i<p;i++)printf("%2d",i);printf("\n");
	//	for(i=0;i<=n;i++){for(j=0;j<p;j++)printf("%2d",dp[i][j]);printf("\n");}
		if(dp[n][0])printf("Divisible\n");
		else printf("Not divisible\n");
		} 
	return 0;
	}
