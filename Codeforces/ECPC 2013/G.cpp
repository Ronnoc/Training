#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define OP begin()
#define ED end()
#define BB second
#define AA first
#define SZ size()
typedef pair<int,int> PII;

int sg[105][105][3];
int call(int u,int v,int w){
	if(w==3)return call(u+1,v,0);
	int &tp=sg[u][v][w];
	if(~tp)return tp;
	vector<int>G;
	if(u)G.PB(call(u-1,v,w+1));
	if(u)G.PB(call(u-1,v+1,w+1));
	if(v)G.PB(call(u,v-1,w+1));
	sort(G.OP,G.ED);
	G.PB(-1);
	for(int i=0;i<G.SZ;i++)if(G[i]!=i)return tp=i;
}
int main(){
	freopen("jenga.in","r",stdin);
	int i,j,T,n;
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		scanf("%d",&n);
		if(n%3)printf("Case %d: Bakkar\n",CA);
		else printf("Case %d: Wahdan\n",CA);
	}
	return 0;
}
