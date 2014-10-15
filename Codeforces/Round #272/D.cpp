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
const double PI=acos(-1.);
const LL MOD = 1000000007;
int ma[5005][5005];
LL dp[5005][5005];
int cnt[5005][5005];
char s[5005];
int ls;
int callma(int u,int v) {
	int &tp=ma[u][v];
	if(~tp)return tp;
	if(u==ls||v==ls)return tp=0;
	if(s[u]==s[v])return tp=callma(u+1,v+1)+1;
	else return tp=0;
}
void update(int a,int b,LL c,int cc) {
	if(a>ls)return;
	dp[a][b]+=c;
	if(dp[a][b]>=MOD)dp[a][b]%=MOD;
	if(~cnt[a][b])
		cmin(cnt[a][b],cc);
	else cnt[a][b]=cc;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	while(~scanf("%s",s)) {
		memset(ma,-1,sizeof ma);
		memset(dp,0,sizeof dp);
		memset(cnt,-1,sizeof cnt);
		ls=strlen(s);
		for(i=0; i<ls; i++)if(s[i+1]!='0')break;
		dp[i+1][i+1]=1;
		cnt[i+1][i+1]=1;
		for(i=1; i<ls; i++)for(j=1; j<=i; j++)if(~cnt[i][j]) {
					int r=i-j;
					int l=callma(r,i);
					if(dp[i][j]>=MOD)dp[i][j]%=MOD;
					update(i+1,j+1,dp[i][j],cnt[i][j]);
					if(s[i]=='1') {
						if(l>=j||s[i+l]=='1')update(i+j,j,dp[i][j],cnt[i][j]+1);
						else update(i+j+1,j+1,dp[i][j],cnt[i][j]+1);
					}
				}
		LL sum=0;
		for(i=1; i<=ls; i++)if(~cnt[ls][i]&&s[ls-i]=='1')sum=(sum+dp[ls][i])%MOD;
		sum%=MOD;
		cout<<sum<<endl;
		LL now=MOD;
		for(i=1;i<=ls;i++)if(~cnt[ls][i]){
			int t=ls-i;
			if(s[t]=='0')continue;
			LL ans=0;
			for(j=0;j<i;j++)ans=(ans*2+(s[t+j]=='1'))%MOD;
			ans+=cnt[ls][i];
			ans%=MOD;
			cmin(now,ans);
			if(i>20)break;
//			break;
		}
		cout<<now<<endl;
	}
	return 0;
}
