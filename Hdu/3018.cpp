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
int deg[111111];
int fa[111111];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
map<int,vector<int> >M;
map<int,vector<int> >::iterator it;
int main(){
	int i,j;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		M.clear();
		memset(deg,0,sizeof(int)*(n+1));
		for(i=1;i<=n;i++)fa[i]=i;
		while(m--){
			scanf("%d%d",&i,&j);
			deg[i]++;
			deg[j]++;
			int fi=getfa(i);
			int fj=getfa(j);
			fa[fi]=fj;
		}
		for(i=1;i<=n;i++)M[getfa(i)].PB(deg[i]);
		int ans=0;
		for(it=M.OP;it!=M.ED;++it){
			vector<int>L=(*it).BB;
			int tot=0;
			int flag=0;
			for(i=0;i<L.SZ;i++)if(L[i]&1)tot++;
			for(i=0;i<L.SZ;i++)if(L[i])flag++;
			tot/=2;
			if(!tot)tot++;
			if(flag)ans+=tot;
//			for(i=0;i<L.SZ;i++)cout<<L[i]<<" ";cout<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
