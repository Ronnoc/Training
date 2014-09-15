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

LL dp[12][22][1<<11];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	memset(dp,0,sizeof dp);
	for(k=1; k<=11; k++) {
		dp[k][1][0]=1;
		vector<int>L;
		for(i=0;i<1<<k;i+=2){
			if(i&(i>>1))continue;
			L.PB(i);
		}
		int ALL=(1<<k)-1;
		for(i=1; i<=11; i++)
			for(j=0; j<1<<k; j++)if(dp[k][i][j])
					for(int l=0;l<L.SZ;l++){
						int put=L[l]^(L[l]>>1);
						int has=j;
						int emp=j^ALL;
						if(has&put)continue;
						int rem=emp^put;
						int next=rem;
						dp[k][i+1][rem]+=dp[k][i][j];
//						cout<<k<<"@"<<i<<","<<j<<"->"<<i+1<<" "<<rem<<endl;
					}
	}
	int n,m;
	while(~scanf("%d%d",&n,&m)&&(n||m))
		printf("%I64d\n",dp[n][m+1][0]);
	return 0;
}
