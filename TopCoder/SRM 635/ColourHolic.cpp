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
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(p) sort(p.OP,p.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos(-1);
const LL MOD = 1000000009;
LL extGcd(LL a, LL b, LL &x, LL &y) {
	LL ret = a;
	if(b) {
		ret = extGcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else x = 1, y = 0;
	return ret;
}
LL modInv(LL a, LL m) {
	LL x, y;
	extGcd(a,m,x,y);
	return (m+x%m)%m;
}
LL dp[2][205][205][4];
LL fact[210005];
LL inv[210005];
LL two[210005];
LL comb(int a,int b) {
	if(a<=200000&&b<=a&&a>=0&&b>=0);
	else return 0;
	return fact[a]*inv[b]%MOD*inv[a-b]%MOD;
}
LL pd[666];
LL gao(int n,int p,int q) {
	if(~pd[n])return pd[n];
	LL ret=0;
	for(int a=0; a<=n&&a<=p; a++) {
		int b=q-(p-a);
		if(b<0||a+b>n)continue;
		LL mul=comb(n,a)*comb(n-a,b)%MOD;
		ret+=mul*comb((p+q+a+b)/2-1,n-1)%MOD*two[n-a-b]%MOD;
	}
	return pd[n]=ret%MOD;
}
class ColourHolic {
public:
	int countSequences(vector <int> r) {
		sort(r.OP,r.ED);
		cout<<r[0]<<" "<<r[1]<<" "<<r[2]<<" "<<r[3]<<endl;
		LL ret=0;
		memset(pd,-1,sizeof pd);
		memset(dp,0,sizeof dp);
		int i,j,k,t;
		fact[0]=1;
		for(i=1; i<=210000; i++)fact[i]=fact[i-1]*i%MOD;
		two[0]=1;
		for(i=1; i<=210000; i++)two[i]=two[i-1]*2%MOD;
		for(i=0; i<=210000; i++)inv[i]=modInv(fact[i],MOD);
		dp[0][0][0][3]=1;
		for(int ii=0; ii<=r[0]+r[1]+1; ii++) {
			i=ii&1;
			memset(dp[i^1],0,sizeof dp[i^1]);
			for(j=0; j<=r[0]; j++)for(k=0; k<=r[1]; k++)for(t=0; t<=3; t++) {
						LL &tp=dp[i][j][k][t];
						if(tp>=MOD)tp%=MOD;
						if(!tp)continue;
						if(t!=0)dp[i][j+1][k][0]+=tp;
						if(t!=1)dp[i][j][k+1][1]+=tp;
						if(t!=2)dp[i^1][j][k][2]+=tp;
						if(j==r[0]&&k==r[1]&&tp&&t<3)
							ret+=tp*gao(ii,r[2],r[3])%MOD;
					}
			ret%=MOD;
		}
		return (int)(ret%MOD);
	}
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor

