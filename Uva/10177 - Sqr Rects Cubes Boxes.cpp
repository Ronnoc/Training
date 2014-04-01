#include<stdio.h>
int dp[110][10];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		long long s2,r2,s3,r3,s4,r4;
		long long z=(n+1)*n/2;
		s2=0;r2=z*z;
		s3=0;r3=r2*z;
		s4=0;r4=r3*z;
		int i;
		for(i=1;i<=n;i++){
			s2+=i*i;
			s3+=i*i*i;
			s4+=i*i*i*i;
			}
		r4-=s4;r3-=s3;r2-=s2;
		printf("%lld %lld %lld %lld %lld %lld\n",s2,r2,s3,r3,s4,r4);
		}
	return 0;
	}
