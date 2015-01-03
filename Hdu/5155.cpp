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

LL dp[55][55];
LL two[2555];
LL cb[55][55];
int main() {
#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	for(i=0;i<=50;i++){
		cb[i][0]=cb[i][i]=1;
		for(j=1;j<i;j++)
			cb[i][j]=(cb[i-1][j-1]+cb[i-1][j])%MOD;
	}
	two[0]=1;
	for(i=1;i<=2500;i++)
		two[i]=two[i-1]*2%MOD;
	dp[0][0]=1;
	for(i=1; i<=50; i++)
		for(j=1; j<=50; j++) {
			dp[i][j]=two[i*j];
			for(int p=0;p<=i;p++)
				for(int q=0;q<=j;q++)
					if(p+q)
						dp[i][j]-=cb[i][p]*cb[j][q]%MOD*dp[i-p][j-q]%MOD;
			dp[i][j]%=MOD;
		}
	int n,m;
	while(cin>>n>>m){
		if(n==0||m==0){
			cout<<0<<"\n";
			continue;
		}
		cout<<(dp[n][m]+MOD)%MOD<<"\n";
	}
	return 0;
}
