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
int main(){
//	freopen("ichess.in","r",stdin);
//	freopen("ichess.out","w",stdout);
	int i,j;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		vector<int>G;
		for(i=1;i<=200;i++){
			int l=i*i/2;
			int r=(i*i+1)/2;
			if(n>=l&&m>=r)G.PB(-i);
			if(m>=l&&n>=r)G.PB(-i);
		}
		SORT(G);
		if(G.empty())printf("Impossible\n");
		else printf("%d\n",-G[0]);
	}
	return 0;
}
