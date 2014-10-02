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

int U[100005],V[100005],W[100005];
vector<PII>G[1005];
int D[1005];
int n,m,x;
queue<int>Q;
void SPFA(int st){
	int i,j;
	for(i=1;i<=n;i++)D[i]=MOD;
	D[st]=0;
	Q.push(st);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
//		cout<<"Q "<<u<<" "<<D[u]<<endl;
		for(i=0;i<G[u].SZ;i++){
			int v=G[u][i].AA;
			int w=G[u][i].BB;
//			cout<<u<<"~"<<v<<" _ "<<w<<endl;
			if(D[v]>D[u]+w){
				D[v]=D[u]+w;
				Q.push(v);
			}
		}
	}
//	for(i=1;i<=n;i++)cout<<D[i]<<" ";cout<<endl;
}
int P[1005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	while(~scanf("%d%d%d",&n,&m,&x)){
		for(i=0;i<m;i++)scanf("%d%d%d",&U[i],&V[i],&W[i]);
		for(i=1;i<=n;i++)G[i].clear();
		for(i=0;i<m;i++)G[U[i]].PB(MP(V[i],W[i]));
		SPFA(x);
		for(i=1;i<=n;i++)P[i]=D[i];
		for(i=1;i<=n;i++)G[i].clear();
		for(i=0;i<m;i++)G[V[i]].PB(MP(U[i],W[i]));
		SPFA(x);
		for(i=1;i<=n;i++)P[i]+=D[i];
		int ans=P[1];
		for(i=2;i<=n;i++)cmax(ans,P[i]);
		printf("%d\n",ans);
	}
	return 0;
}
