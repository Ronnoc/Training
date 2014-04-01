#include<stdio.h>
#include<string.h>
int dp[40][40][40];
int back(int x,int y,int z){
	x%=23,y%=28,z%=33;
	int &tp=dp[x][y][z];
	if(tp!=-1)return tp;
	return tp=1+back(x+1,y+1,z+1);
	}
int main(){
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	int x,y,z,w,T=0;
	while(scanf("%d%d%d%d",&x,&y,&z,&w)!=EOF){
		if(x==-1&&y==-1&&z==-1&&w==-1)break;
		if(x<0)x+=((-x)/23+1)*23;
		if(y<0)y+=((-y)/28+1)*28;
		if(z<0)z+=((-z)/33+1)*33;
		int res=23*28*33-back(x,y,z)-w;
		if(res<=0)res+=23*28*33;
		printf("Case %d: the next triple peak occurs in %d days.\n",++T,res);
		}
	return 0;
	}
