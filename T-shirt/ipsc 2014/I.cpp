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
int fa[21111];
vector<int>G[21111];
int son[21111];
void dfson(int u){
	son[u]=1;
	for(int i=0;i<G[u].SZ;i++){
		int v=G[u][i];
		dfson(v);
		son[u]+=son[v];
	}
}
int main(){
	freopen("i2.in","r",stdin);
	freopen("i2.out","w",stdout);
	int i,j;
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		int n;
		scanf("%d",&n);
		for(i=1;i<=n;i++)G[i].clear();
		for(i=2;i<=n;i++)scanf("%d",&fa[i]);
		for(i=2;i<=n;i++)G[fa[i]].PB(i);
		dfson(1);
		LL ans=0;
		for(i=1;i<=n;i++)if(!G[i].empty()){
			priority_queue<int>Q;
			for(j=0;j<G[i].SZ;j++)Q.push(-son[G[i][j]]);
			while(Q.SZ>1){
				int u=-Q.top();Q.pop();
				int v=-Q.top();Q.pop();
				Q.push(-u-v);
				ans+=u+v;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
