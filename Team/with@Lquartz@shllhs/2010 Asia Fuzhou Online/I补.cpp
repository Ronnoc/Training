//shllhs
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
string dp[2][200][200];
int main() {
	int t,n,m,i,j,cas = 1;
	scanf ("%d",&t);
	while (t--) {
		scanf ("%d%d",&n,&m);
		getchar();
		string s;
		cin>>s;
		for (i = 0; i<=n; i++) {
			dp[0][i][0] = s.substr (0,i);
			dp[1][i][0].assign (dp[0][i][0].rbegin(),dp[0][i][0].rend());
		}
		string ans = s;
		for (j = 1; j<=m; j++) {
			for (i = j; i<=n; i++) {
				dp[0][i][j] = s[i-1]+dp[1][i-1][j-1];
				if (i>j) dp[0][i][j] = min (dp[0][i][j],s[i-1]+dp[0][i-1][j]);
				dp[1][i][j] = dp[0][i-1][j-1]+s[i-1];
				if (i>j) dp[1][i][j] = min (dp[1][i][j],dp[1][i-1][j]+s[i-1]);
				ans = min (ans,dp[0][i][j]+s.substr (i,n-i));
			}
		}
		cout<<"Case "<<cas++<<": "<<ans<<endl;
	}
	return 0;
}
