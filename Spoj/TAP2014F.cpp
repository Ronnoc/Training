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

int tl[10005],nz;
int rk[10005][105];
int main() {
#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	int N,T;
	while(~scanf("%d%d",&N,&T)) {
		for(nz=0,i=1; i<=N; i++)rk[0][i]=0;
		tl[nz++]=0;
		for(int tt=1; tt<=T; tt++) {
			int C,P;
			char s[105];
			scanf("%d%s%d",&C,s,&P);
			nz-=C;
			if(nz<1)nz=1;
			for(i=1; i<=N; i++)rk[nz][i]=rk[nz-1][i];
			vector<pair<pair<int,char>,int> >L;
			for(i=1; i<=N; i++)
				L.PB(MP(MP(rk[nz][i],s[i-1]),i));
			sort(L.OP,L.ED);
			for(i=0; i<L.SZ; i++) {
				if(i&&L[i].AA==L[i-1].AA)
					rk[nz][L[i].BB]=rk[nz][L[i-1].BB];
				else rk[nz][L[i].BB]=i;
			}
			printf("%d\n",L[P-1].BB);
			nz++;
		}
	}
	return 0;
}
