#include<stdio.h>
int dp[100][10];
int d=0;
int abs(int x){if(x>0)return x;return -x;}
int cho[10];
int place(int t){
	int i;
	for(i=1;i<t;i++){
		if(cho[i]==cho[t])return 0;
		if(abs(cho[i]-cho[t])==abs(i-t))return 0;
		}
	return 1;
	}
void op(int t){
	int i;
	if(t>8){
		++d;
		for(i=1;i<=8;i++)dp[d][i]=cho[i];
		}
	else {
		for(i=1;i<=8;i++){
			cho[t]=i;
			if(place(t))op(t+1);
			}
		}
	}
int main(){
	op(1);
	int x[10];
	int i,j;
	int k=0;
	while(scanf("%d",&x[1])!=EOF){
		int res=8;
		int sum=0;
		for(i=2;i<=8;i++)scanf("%d",&x[i]);
		for(i=1;i<=d;i++){
			sum=0;
			for(j=1;j<=8;j++)sum+=(bool)abs(x[j]-dp[i][j]);
			if(sum<res)res=sum;
			}
		++k;
		printf("Case %d: %d\n",k,res);
		}
	return 0;
	}
