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
const LL MOD = 1000000009;
LL dp[17][10005];
int n,m;
LL solve(int id,int s){
	if(id==-1)return s==0;
	if(~dp[id][s])return dp[id][s];
	LL &tp=dp[id][s];
	tp=0;
	for(int i=0;i<=m;i++){
		int r=s-(i<<id);
		if(r<0)break;
		tp+=solve(id-1,r);
	}
	tp%=MOD;
	return tp;
}
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--){
		scanf("%d%d",&m,&n);
		memset(dp,-1,sizeof dp);
		for(i=0;n>>i;i++);
		cout<<solve(i,n)<<"\n";
	}
	return 0;
}
