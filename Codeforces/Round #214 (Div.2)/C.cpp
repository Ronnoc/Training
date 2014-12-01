#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int dp[105][120000];
int n,k;
int a[111],b[111],t[111];
void solve(){
	while(cin>>n>>k){
		int i;
		for(i=0;i<n;i++)cin>>t[i];
		for(i=0;i<n;i++)cin>>b[i];
		for(i=0;i<n;i++)b[i]*=k;
		int add=100000;
		int ub=110005;
		for(i=0;i<n;i++)a[i]=t[i]-b[i];
		memset(dp,-1,sizeof dp);
		dp[0][add]=0;
		for(i=0;i<n;i++){
			for(int j=max(-a[i],0);j<ub;j++){
				if(dp[i][j]==-1)continue;
				dp[i+1][j+a[i]]=max(dp[i+1][j+a[i]]
							,dp[i][j]+t[i]);
				dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
			}
		}
		if(dp[n][add])cout<<dp[n][add]<<endl;
		else cout<<-1<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
