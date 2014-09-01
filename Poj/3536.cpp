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
int pre[1111111];
int isp[1111111];
int main(){
//	freopen("beer.in","r",stdin);
//	freopen("beer.out","w",stdout);
	int i,j;
	int n;
	while(~scanf("%d",&n)){
		vector<int>G;
		for(i=1;i*i<=n;i++){
			if(n%i)continue;
			G.PB(i);G.PB(n/i);
		}
		SORT(G);
		int temp=2*n+1;
		int p=1,q=1;
		for(i=0;i<G.SZ;i++)for(j=i;j<G.SZ;j++){
			if(n%(G[i]*G[j]))continue;
			int now=G[i]*G[j]+n/G[i]+n/G[j];
			if(now<temp)temp=now,p=G[i],q=G[j];
		}
		printf("%d %d %d\n",p,q,n/(p*q));
	}
	return 0;
}
