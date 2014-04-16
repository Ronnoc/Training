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
vector<PII>ea,eb;
int dega[1000005];
int degb[1000005];
int main() {
	int i,j,u,v;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		ea.clear(),eb.clear();
		memset(dega,0,sizeof dega);
		memset(degb,0,sizeof degb);
		int na,nb;
		scanf("%d",&na);
		for(i=1;i<na;i++){
			scanf("%d%d",&u,&v);
			ea.PB(MP(u,v));
			dega[u]++,dega[v]++;
		}
		scanf("%d",&nb);
		for(i=1;i<nb;i++){
			scanf("%d%d",&u,&v);
			eb.PB(MP(u,v));
			degb[u]++,degb[v]++;
		}
		int coreb=0,maxdegb=0;
		for(i=1;i<=nb;i++)if(degb[i]>1)coreb++,cmax(maxdegb,degb[i]);
		if(coreb>1){
			printf( "Case %d: %s\n",CASE,"YES" );
			continue;
		}
		if(coreb==0){
			printf( "Case %d: %s\n",CASE,"NO" );
			continue;
		}
		int maxdega=2*(maxdegb)-1;
		int flag=0;
		for(i=1;i<=na;i++)if(dega[i]>=maxdega)flag=1;
		if(flag)printf( "Case %d: %s\n",CASE,"NO" );
		else printf( "Case %d: %s\n",CASE,"YES" );
	}
	return 0;
}
