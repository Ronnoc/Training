#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) \
  int(X);      \
  scanf("%d", &X)
#define rep(i, a, n) for (int i = (a); i < (int)(n); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
const LL MOD = 1000000007;
const long double PI = acos(-1.);
const long double eps = 1e-9;


const int N = 1000005;

int n;
vector<PII>G[N];
int P[N];

int vis[N];
int fa[N];
int dep[N][2];
VI fsOrder;
VI invOrder;
int hei[N][2];

void solve(){
	RI(n);
	rep(i,1,n+1)G[i].clear();
	rep(i,2,n+1){
		RI(P[i]);
		int u = i;
		int v = P[i];
		G[u].PB(MP(0,v));
		G[v].PB(MP(0,u));
	}
	fsOrder.clear();
	invOrder.clear();
	rep(i,1,n+1)vis[i]=0,fa[i]=-1;

	fsOrder.PB(1);
	invOrder.PB(1);
	vis[1]=1;
	int iq=0;
	while(iq < fsOrder.SZ){
		int u = fsOrder[iq++];
		for(auto pr:G[u]){
			int v=pr.BB;
			if(!vis[v]){
				vis[v]=1;
				fa[v]=u;
				fsOrder.PB(v);
				invOrder.PB(v);
			}
		}
	}
	reverse(all(invOrder));

	rep(i,1,n+1)rep(j,0,2)dep[i][j]=0;
	for(auto u:invOrder){
		VI ds;
		ds.PB(1);
		for(auto pr:G[u]){
			int v=pr.BB;
			if(v!=fa[u]){
				ds.PB(dep[v][0]+1);
			}
		}
		sort(all(ds));
		reverse(all(ds));
		dep[u][0]=ds[0];
		if(ds.SZ>1)
			dep[u][1]=ds[1];
		else
			dep[u][1]=0;
		// cerr<<u<<" "<<dep[u][0]<<" "<<dep[u][1]<<endl;
	}

	rep(i,1,n+1)rep(j,0,2)hei[i][j]=0;
	for(auto u:fsOrder){
		VI ds;
		if(dep[u][0])ds.PB(dep[u][0]);
		if(dep[u][1])ds.PB(dep[u][1]);
		int v = fa[u];
		if(v!=-1){
			if(hei[v][0]==dep[u][0]+1)
				ds.PB(hei[v][1]+1);
			else
				ds.PB(hei[v][0]+1);
		}
		sort(all(ds));
		reverse(all(ds));
		hei[u][0]=ds[0];
		if(ds.SZ>1)
			hei[u][1]=ds[1];
		else
			hei[u][1]=0;
		// cerr<<u<<" "<<hei[u][0]<<" "<<hei[u][1]<<endl;
	}

	for(auto u:fsOrder){
		// cerr<<u<<": ";
		for(auto &pr:G[u]){
			int v = pr.BB;
			if(v==fa[u]){
				if(hei[v][0]==dep[u][0]+1){
					pr.AA=-hei[v][1];
				}else{
					pr.AA=-hei[v][0];
				}
			}else{
				pr.AA=-dep[v][0];
			}
			// cerr<<-pr.AA<<","<<pr.BB<<" ";
		}
		// cerr<<endl;
	}
	
	// cerr<<"\n";
	// rep(u,1,n+1){
	// 	cerr<<u<<": ";
	// 	for(auto &pr:G[u]){
	// 		cerr<<pr.BB<<","<<-pr.AA<<" ";
	// 	}
	// 	cerr<<endl;
	// }
	

	rep(u,1,n+1)sort(all(G[u]));
	LL ans = 0;
	rep(u,2,n+1){
		int v = fa[u];
		int iu=0;
		int iv=0;
		// cerr<<u<<","<<v<<":"<<endl;
		while(iu<G[u].SZ&&iv<G[v].SZ){
			if(G[u][iu].BB==v){iu++;continue;}
			if(G[v][iv].BB==u){iv++;continue;}
			int du=-G[u][iu].AA;
			int dv=-G[v][iv].AA;
			// cerr<<"("<<u<<"-"<<G[u][iu].BB<<","<<v<<"-"<<G[v][iv].BB<<")#"<<min(du,dv)<<endl;
			ans+=min(du,dv);
			iu++;
			iv++;
		}
	}
	cout<<ans<<endl;
}

int main()
{
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    printf("Case #%d: ", CA);
    solve();
  }
  fflush(stdout);
  return 0;
}