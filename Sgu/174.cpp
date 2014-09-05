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

int fa[400005];
int getfa(int u){return fa[u]==u?u:fa[u]=getfa(fa[u]);}
map<PII,int>S;
int got(int a,int b){
	map<PII,int>::iterator it=S.find(MP(a,b));
	if(it==S.ED)return S[MP(a,b)]=S.SZ;
	else return S[MP(a,b)];
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,u,v,T;
	while(~scanf("%d",&n)){
		S.clear();
		for(i=0;i<2*n;i++)fa[i]=i;
		int ans=0;
		for(i=1;i<=n;i++){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			int u=got(a,b),v=got(c,d);
			if(getfa(u)==getfa(v)){if(!ans)ans=i;}
			else fa[getfa(u)]=getfa(v);
		}
		printf("%d\n",ans);
	}
	return 0;
}
