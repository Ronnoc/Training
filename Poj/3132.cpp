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

int dp[1150][200][15];
vector<int>P;
bool isprime(int x) {
	if(x<=1)return 0;
	for(int i=2; i*i<=x; i++)if(x%i==0)return 0;
	return 1;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,l,n,m,u,v,T;
	for(i=2; i<=1140; i++)if(isprime(i))P.PB(i);
	memset(dp,0,sizeof dp);
	dp[0][0][0]=1;
	for(i=0; i<=1140; i++)for(j=0; j<P.SZ; j++)for(k=0; k<14; k++)if(dp[i][j][k])
					for(l=j; l<P.SZ&&i+P[l]<=1140; l++) {
						dp[i+P[l]][l+1][k+1]+=dp[i][j][k];
//						if(i+P[l]==24)cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<" "<<P[l]<<endl;
					}
	while(~scanf("%d%d",&n,&m)) {
		if(!n&&!m)break;
		int sum=0;
		for(j=0; j<P.SZ; j++)sum+=dp[n][j][m];
		printf("%d\n",sum);
	}
	return 0;
}

