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

vector<int>G[10005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T=0;
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		for(i=1;i<=n;i++)G[i].clear();
		G[1].PB(1);
		G[1].PB(2);
		G[1].PB(3);
		G[1].PB(5);
		int j=4;
		for(i=2;i<=n;i++){
			G[i].PB(j),G[i].PB(6*i-5),G[i].PB(6*i-3),G[i].PB(6*i-1);
			j+=2;
			if(j%3==0)j+=2;
		}
		int f=0;
		for(i=1;i<=n;i++)for(j=0;j<G[i].SZ;j++)cmax(f,G[i][j]);
		cout<<f*m<<"\n";
		for(i=1;i<=n;i++,cout<<"\n")for(j=0;j<G[i].SZ;j++)cout<<G[i][j]*m<<" ";
	}
	return 0;
}
