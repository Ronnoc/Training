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
const double PI=acos(-1.);
const LL MOD = 1000000007;
string S[300005];
int R[300005];
string U[100005],V[100005];
vector<string>L;
vector<int>G[300005];
int fa[300005];
int in[300005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int m,n;
	string s;
	while(cin>>m) {
		L.clear();
		for(i=0; i<m; i++) {
			cin>>s;
			for(j=0; j<s.SZ; j++)s[j]=tolower(s[j]);
			L.PB(s);
		}
		cin>>n;
		for(i=0; i<n; i++) {
			cin>>U[i]>>V[i];
			for(j=0; j<U[i].SZ; j++)
				U[i][j]=tolower(U[i][j]);
			for(j=0; j<V[i].SZ; j++)
				V[i][j]=tolower(V[i][j]);
		}
		int nS=0;
		for(i=0; i<n; i++)S[nS++]=U[i];
		for(i=0; i<n; i++)S[nS++]=V[i];
		for(i=0; i<L.SZ; i++)S[nS++]=L[i];
		sort(S,S+nS);
		nS=unique(S,S+nS)-S;
		int N=nS;
		for(i=0; i<N; i++) {
			G[i].clear();
			fa[i]=i;
			R[i]=0;
			in[i]=0;
			for(j=0; j<S[i].SZ; j++)if(S[i][j]=='r')R[i]++;
		}
		for(i=0; i<n; i++) {
			int u=lower_bound(S,S+nS,U[i])-S;
			int v=lower_bound(S,S+nS,V[i])-S;
			G[v].PB(u);
			in[u]++;
		}
		vector<pair<int,PII > >T;
		for(i=0; i<N; i++)T.PB(MP(R[i],MP((int)S[i].SZ,i)));
		sort(T.OP,T.ED);
		for(int t=1; t<=640;t++)
			for(i=0; i<T.SZ; i++) {
				int v=T[i].BB.BB;
				for(j=0; j<G[v].SZ; j++) {
					int u=G[v][j];
					if(MP(R[fa[u]],(int)S[fa[u]].SZ)>MP(R[fa[v]],(int)S[fa[v]].SZ))
						fa[u]=fa[v];
				}
			}
		LL ans1=0,ans2=0;
//		for(i=0;i<N;i++)cout<<i<<" "<<fa[i]<<" "<<S[i]<<endl;
		for(i=0; i<L.SZ; i++) {
			int id=lower_bound(S,S+nS,L[i])-S;
			id=fa[id];
			ans1+=R[id];
			ans2+=S[id].SZ;
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
