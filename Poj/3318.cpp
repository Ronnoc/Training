#include<stdio.h>
#include<stdlib.h> 
#include<math.h>
#define N 510
#define LL long long
LL A[N][N],B[N][N],C[N][N],X[N],Y1[N],Y2[N],tp[N];
int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%lld",&A[i][j]);
		for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%lld",&B[i][j]);
		for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%lld",&C[i][j]);
		int flag=1;
		int test=1;
		while(test--){
			if(!flag)break;
			X[0]=rand()%n;
			for(i=1;i<n;i++)X[i]=X[i-1]+rand()%n;
			for(i=0;i<n;i++){
				tp[i]=0;
				for(j=0;j<n;j++)tp[i]+=X[j]*B[i][j];
				}
			for(i=0;i<n;i++){
				Y1[i]=0;
				for(j=0;j<n;j++)Y1[i]+=tp[j]*A[i][j];
				}	
			for(i=0;i<n;i++){
				Y2[i]=0;
				for(j=0;j<n;j++)Y2[i]+=X[j]*C[i][j];
				}
			for(i=0;i<n;i++)if(Y1[i]!=Y2[i]){flag=0;break;}					
			}
		if(flag)printf("YES\n");
		else printf("NO\n");
		}
	return 0;
	}
