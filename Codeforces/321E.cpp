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
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;
int dp[805][4005];
int C[4005][4005];
int G[4005][4005];
int update(int d,int i,int j){
	int ret=dp[d-1][j]+G[j+1][i];
	if(ret<dp[d][i]){
		dp[d][i]=ret;
		return 1;
	}
	return 0;
}
void solve(int d,int L,int R,int cl,int cr){
	int m=(L+R)/2;
	for(int i=cl;i<=cr;i++)
		if(update(d,m,i))
			C[d][m]=i;
//	cout<<"call "<<d<<" "<<L<<"~"<<R<<" @? "<<cl<<"~"<<cr<<"\tdp"<<m<<"="<<dp[d][m]<<"@"<<C[d][m]<<endl;
	if(m>L)solve(d,L,m-1,cl,C[d][m]);
	if(R>m)solve(d,m+1,R,C[d][m],cr);
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n,m;
	char c;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++)for(j=1;j<=n;j++){
			while(c=getchar())
				if(c<='9'&&c>='0')break;
			C[i][j]=c-'0';
		}
		for(i=1;i<=n;i++)for(j=2;j<=n;j++)C[i][j]+=C[i][j-1];
		for(i=2;i<=n;i++)for(j=1;j<=n;j++)C[i][j]+=C[i-1][j];
		for(i=1;i<=n;i++)for(j=i;j<=n;j++)
			G[i][j]=(C[j][j]+C[i-1][i-1]-C[i-1][j]-C[j][i-1])/2;
		memset(dp,0x2f,sizeof dp);
		for(i=1;i<=n;i++)dp[1][i]=G[1][i];
		for(i=1;i<=n;i++)C[1][i]=1;
		for(k=2;k<=m;k++){
			dp[k][k]=dp[k-1][k-1]+G[k][k];
			dp[k][n]=MOD;
			for(j=k;j<=n;j++){
				int t=dp[k-1][j-1]+G[j][n];
				if(t<dp[k][n])dp[k][n]=t,C[k][n]=j;
			}
			for(i=n-1;i>=k;i--){
				dp[k][i]=MOD;
				for(j=C[k-1][i];j<=C[k][i+1]&&j<=i;j++){
					int t=dp[k-1][j-1]+G[j][i];
					if(t<dp[k][i])dp[k][i]=t,C[k][i]=j;
				}
			}
		}
		cout<<dp[m][n]<<endl;
	}
	return 0;
}
