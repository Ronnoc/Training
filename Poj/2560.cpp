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
const LL MOD = 1000000007;
int fa[111];
int getfa(int u){return fa[u]==u?u:fa[u]=getfa(fa[u]);}
vector<pair<double,PII> >L;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
	while(~scanf("%d",&n)){
		double x[111],y[111];
		for(i=0;i<n;i++)scanf("%lf%lf",&x[i],&y[i]);
		for(i=0;i<n;i++)fa[i]=i;
		L.clear();
		for(i=0;i<n;i++)for(j=i+1;j<n;j++){
			double d=sqrt(SQ(x[i]-x[j])+SQ(y[i]-y[j]));
			L.PB(MP(d,MP(i,j)));
		}
		sort(L.OP,L.ED);
		double ans=0;
		for(i=0;i<L.SZ;i++){
			int u=L[i].BB.AA;
			int v=L[i].BB.BB;
			if(getfa(u)!=getfa(v))fa[getfa(u)]=getfa(v),ans+=L[i].AA;
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
