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
vector<int>X[100005],Y[100005];
vector<PII>L;
bool exist(int u,int v){
	int id=lower_bound(X[u].OP,X[u].ED,v)-X[u].OP;
	if(id==X[u].SZ)return 0;
	return X[u][id]==v;
}
int main(){
	int i,j,n,u,v;
	while(~scanf("%d",&n)){
		for(i=0;i<=100000;i++)X[i].clear();
		for(i=0;i<=100000;i++)Y[i].clear();
		L.clear();
		for(i=1;i<=n;i++){
			scanf("%d%d",&u,&v);
			X[u].PB(v);
			Y[v].PB(u);
			L.PB(MP(u,v));
		}
		for(i=0;i<=100000;i++)SORT(X[i]);
		for(i=0;i<=100000;i++)SORT(Y[i]);
		int ans=0;
		for(i=0;i<L.SZ;i++){
			int u=L[i].AA;
			int v=L[i].BB;
			int iu=lower_bound(X[u].OP,X[u].ED,v)-X[u].OP;
			int iv=lower_bound(Y[v].OP,Y[v].ED,u)-Y[v].OP;
			int ru=X[u].SZ-1-iu;
			int rv=Y[v].SZ-1-iv;
			if(ru<rv){
				for(j=iu+1;j<X[u].SZ;j++){
					int V=X[u][j];
					int d=V-v;
					int U=u+d;
					if(U>100000)break;
					if(!exist(U,v))continue;
					if(!exist(U,V))continue;
					ans++;
				}
			}else {
				for(j=iv+1;j<Y[v].SZ;j++){
					int U=Y[v][j];
					int d=U-u;
					int V=v+d;
					if(V>100000)break;
					if(!exist(u,V))continue;
					if(!exist(U,V))continue;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
