#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int dp[100010];
int main() {
int OFFL=0;
#ifndef ONLINE_JUDGE
OFFL=1;
#endif
	int n,k;
	while(cin>>n>>k){
		memset(dp,-1,sizeof(dp));
		queue<pair<int,int> >S;
		S.push(make_pair(n,0));
		while(!S.empty()&&dp[k]==-1){
			int x=S.front().first;
			int t=S.front().second;
			S.pop();
			if(x<0||x>100000)continue;
			int flag=0;
			if(dp[x]==-1)flag=1,dp[x]=t;
			else if(dp[x]>t)flag=1,dp[x]=t;
			if(!flag)continue;
			S.push(make_pair(x+1,t+1));
			S.push(make_pair(x-1,t+1));
			S.push(make_pair(x*2,t+1));
		}
		cout<<dp[k]<<endl;
	}
return 0;}
