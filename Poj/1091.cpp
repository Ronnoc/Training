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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
map<int,int>P;
int phi(int x){
	if(P[x]!=0)return P[x];
	int ret=x,n=x;
	for(int i=2;i*i<=n;i++)if(n%i==0){
		while(n%i==0)n/=i;
		ret=ret/i*(i-1);
	}
	if(n>1)ret=ret/n*(n-1);
	return P[x]=ret;
}
vector<int>L;
LL dp[16][1011];
int get(int x){
	return lower_bound(L.OP,L.ED,x)-L.OP;
}
int shu(int a,int m){
	return phi(m/a);
}
int main(){
	int i,j,k;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		L.clear();
		memset(dp,0,sizeof dp);
		for(i=1;i*i<=m;i++)if(m%i==0)L.PB(i),L.PB(m/i);
		SORT(L);
		L.erase(unique(L.OP,L.ED),L.ED);
		memset(dp,0,sizeof dp);
		dp[0][get(m)]=1;
		for(i=0;i<n;i++)for(j=0;j<L.SZ;j++)if(dp[i][j]){
			for(k=0;k<L.SZ;k++)dp[i+1][get(__gcd(L[j],L[k]))]+=dp[i][j]*shu(L[k],m);
		}
		printf("%lld\n",dp[n][0]);
	}
	return 0;
}
