#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define BG begin()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))

int z[500000];
int L[50005],nl;
const int ADD = 200000;
double S[50005];
double V[50005];
LL sq(int x){
	return 1LL*x*x;
}
int main() {
	int i,j;
	int T;
	scanf("%d",&T);
	memset(z,0,sizeof z);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int mn=1000000000,mx=-1000000000;
		for(i=0;i<n;i++){
			scanf("%d",&j);
			z[j+ADD]++;
			cmax(mx,j);
			cmin(mn,j);
		}
		nl=0;
		for(i=mn;i<=mx;i++)
			while(z[i+ADD])L[++nl]=i,z[i+ADD]--;
		if(m==n){
			printf("%.16f\n",0.);
			continue;
		}
		m=n-m;
//		for(i=0;i<=nl;i++)cerr<<L[i]<<"~";cerr<<"\n";
		S[0]=V[0]=0;
		for(i=1;i<=nl;i++){
			S[i]=S[i-1]+L[i];
			V[i]=V[i-1]+sq(L[i]);
		}
//		for(i=0;i<=nl;i++)cerr<<S[i]<<" ";cerr<<"\n";
//		for(i=0;i<=nl;i++)cerr<<V[i]<<" ";cerr<<"\n";
		double ans=1e100;
		for(i=0;i+m<=nl;i++){
			double sum=S[i+m]-S[i];
			double val=V[i+m]-V[i];
			double now=val-sum*sum/m;
//			cerr<<"("<<i<<","<<i+m<<"] ?"<<sum<<" "<<val<<" => "<<now<<"\n";
			cmin(ans,now);
		}
		printf("%.16f\n",ans);
	}
	return 0;
}
/*
10
3 0
-1 0 1
3 1
-1 0 1
3 2
-1 0 1
3 3
-1 0 1
4 0
-2 -1 1 2
4 1
-2 -1 1 2
4 2
-2 -1 1 2
4 3
-2 -1 1 2
4 4
-2 -1 1 2
*/
