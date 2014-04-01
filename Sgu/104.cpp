#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[110][110];
int f,v,a[110][110];
int place[110][110];
void solve(){
	int i,j,k;
	cin>>f>>v;
	for(i=1;i<=f;i++)for(j=1;j<=v;j++)cin>>a[i][j];
	memset(dp,0,sizeof(place));
	memset(place,0,sizeof(dp));
	for(i=1;i<=f;i++){
		for(j=i;j<=v;j++){
			dp[i][j]=dp[i-1][j-1]+a[i][j];
			place[i][j]=j;
			if(j>i)
			if(dp[i][j-1]>dp[i][j]){
				dp[i][j]=dp[i][j-1];
				place[i][j]=place[i][j-1];
			}
		}
	}
	cout<<dp[f][v]<<endl;
	int res[110],tp=v;
	for(i=f;i>=1;i--){
		res[i]=place[i][tp];
		tp=res[i]-1;
	}
	cout<<res[1];
	for(i=2;i<=f;i++)cout<<" "<<res[i];
	cout<<endl;
}
int main() {
#ifndef ONLINE_JUDGE
#endif
	solve();
return 0;}
