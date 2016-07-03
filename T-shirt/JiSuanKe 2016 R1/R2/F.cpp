#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}
vector<int>g[105];
int n;
int vis[105];
int m;
int x[10005];
int y[10005];
int used[10005];
int a,b,mid;
int sta[105],ist;
int FLAG=0;
int fa[105];
int hasb=0;
void dfs(int u){
	if(hasb||FLAG)return;
	if(u==b){
		hasb=1;
		queue<int>Q;
		rep(i,1,n+1)fa[i]=-1;
		Q.push(a);
		fa[a]=a;
		vis[mid]=0;
		while(!Q.empty()){
			int p=Q.front();
			Q.pop();
			for(auto k:g[p])if(!used[k]){
				int q=x[k]+y[k]-p;
				if(!vis[q]&&fa[q]==-1){
					fa[q]=p;
					Q.push(q);
				}
			}
		}
		if(~fa[mid]){
			FLAG=1;
			stack<int>S;
			while(a!=mid){
				S.push(mid);
				mid=fa[mid];
			}
			vector<int>L;
			printf("%d",a);
			while(!S.empty()){
				int st=S.top();S.pop();
				printf(" %d",st);
			}
			rep(i,0,ist)
				printf(" %d",sta[i]);
			printf("\n");
		}
	}
	if(hasb||FLAG)return;
	for(auto k:g[u]){
		int v=x[k]+y[k]-u;
		if(v!=a&&!vis[v]){
			vis[v]=1;
			sta[ist++]=v;
			used[k]=1;
			dfs(v);
			used[k]=0;
			ist--;
		}
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&a,&b,&mid);
	rep(i,1,n+1)g[i].clear();
	rep(i,0,m){
		scanf("%d%d",&x[i],&y[i]);
		g[x[i]].PB(i);
		g[y[i]].PB(i);
	}
	srand(time(NULL));
	FLAG=0;
	while(!FLAG){
		rep(i,0,m)used[i]=0;
		rep(i,1,n+1)random_shuffle(all(g[i]));
		memset(vis,0,sizeof vis);
		ist=0;
		vis[mid]=1;
		hasb=0;
		dfs(mid);
	}
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}