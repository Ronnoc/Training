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

vector<PII>L,E[2];
int deg[105],n;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	while(~scanf("%d",&n)) {
		L.clear(),E[0].clear(),E[1].clear();
		for(i=1; i<=n; i++)scanf("%d",&deg[i]);
		for(i=1; i<=n; i++)if(deg[i])L.PB(MP(-deg[i],i));
		for(i=0; i<L.SZ; i++) {
			sort(L.OP+i,L.ED);
			int next=i+1;
			while(L[i].AA<0&&next<L.SZ) {
				if(L[next].AA<0) {
					L[i].AA++,L[next].AA++;
					E[0].PB(MP(L[i].BB,L[next].BB));
				}
				next++;
			}
			if(L[i].AA<0)break;
		}
		if(i!=L.SZ) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		L.clear();
		for(i=1; i<=n; i++)if(deg[i])L.PB(MP(-deg[i],i));
		bool got=0;
		for(i=0; i<L.SZ; i++) {
			if(L[i].AA==0)continue;
			sort(L.OP+i,L.ED);
			int next=i+1;
			while(L[i].AA<0&&next<L.SZ) {
				if(L[next].AA<0) {
					L[i].AA++,L[next].AA++;
					E[1].PB(MP(L[i].BB,L[next].BB));
				}
				next++;
			}
			if(L[i].AA<0)break;
			if(next<L.SZ&&L[next].AA<0) {
				got=1;
				L[next-1].AA--;
				L[next].AA++;
				E[1].pop_back();
				E[1].PB(MP(L[i].BB,L[next].BB));
				break;
			}
		}
		bool multi=0;
		if(got) {
			for(i++;i<L.SZ;i++){
				sort(L.OP+i,L.ED);
				int next=i+1;
				while(L[i].AA<0&&next<L.SZ) {
					if(L[next].AA<0) {
						L[i].AA++,L[next].AA++;
						E[1].PB(MP(L[i].BB,L[next].BB));
					}
					next++;
				}
				if(L[i].AA<0)break;
			}
			if(i==L.SZ)multi=1;
		}
		if(multi){
			printf("MULTIPLE\n");
			for(j=0;j<2;j++){
				printf("%d %d\n",n,E[j].SZ);
				for(i=0;i<E[j].SZ;i++)printf("%s%d",i?" ":"",E[j][i].AA);printf("\n");
				for(i=0;i<E[j].SZ;i++)printf("%s%d",i?" ":"",E[j][i].BB);printf("\n");
			}
		}else {
			printf("UNIQUE\n");
			for(j=0;j<1;j++){
				printf("%d %d\n",n,E[j].SZ);
				for(i=0;i<E[j].SZ;i++)printf("%s%d",i?" ":"",E[j][i].AA);printf("\n");
				for(i=0;i<E[j].SZ;i++)printf("%s%d",i?" ":"",E[j][i].BB);printf("\n");
			}
		}
	}
	return 0;
}
