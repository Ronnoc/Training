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

vector<int>G[100005];
vector<int>V[100005];
int sg[100005];
int sv[100005];
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	int n,m;
	while(~scanf("%d%d",&m,&n)){
		for(i=1;i<=n;i++)V[i].clear(),sv[i]=MOD;
		for(i=1;i<=m;i++){
			G[i].clear();
			sg[i]=MOD;
			int z;
			scanf("%d",&z);
			while(z--){
				scanf("%d",&j);
				G[i].PB(j);
				V[j].PB(i);
			}
		}
		set<int>Q[2];
		set<int>::iterator it;
		int x=0,y=1;
		for(sv[1]=i=0;i<V[1].SZ;i++)
			Q[x].insert(V[1][i]),sg[V[1][i]]=1;
		int foo=1;
		while(!Q[x].empty()){
			set<int>S;
			for(it=Q[x].OP;it!=Q[x].ED;++it){
				int u=*it;
				for(i=0;i<G[u].SZ;i++)if(sv[G[u][i]]==MOD)
					S.insert(G[u][i]),sv[G[u][i]]=foo;
			}
			for(it=S.OP;it!=S.ED;++it){
				int u=*it;
				for(i=0;i<V[u].SZ;i++)if(sg[V[u][i]]==MOD)
					Q[y].insert(V[u][i]),sg[V[u][i]]=foo;
			}
			Q[x].clear();
			swap(x,y);
			foo++;
		}
		LL a1=0,a2=0,a3=0;
		for(i=1;i<=n;i++)if(sv[i]<MOD){
			a1++;
			cmax(a2,1LL*sv[i]);
			a3+=sv[i];
		}
		cout<<a1<<" "<<a2<<" "<<a3<<"\n";
	}
	return 0;
}
