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
int fa[61005];
int getfa(int u){return fa[u]==u?u:fa[u]=getfa(fa[u]);}
void merfa(int u,int v){
	int fu=getfa(u),fv=getfa(v);
	fa[fu]=fv;
}
int main(){
	int i,j;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(!n&&!m)break;
		for(i=0;i<n+m;i++)fa[i]=i;
		for(i=0;i<m;i++){
			int k;
			scanf("%d",&k);
			while(k--){
				scanf("%d",&j);
				merfa(n+i,j);
			}
		}
		int cnt=0;
		for(i=0;i<n;i++)if(getfa(i)==getfa(0))cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
