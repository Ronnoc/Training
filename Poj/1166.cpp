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
char s[11][11]= {"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
int st[11];
int main() {
//	freopen("clocks.in", "r", stdin);
//	freopen("clocks.out", "w", stdout);
	while(cin>>st[0]) {
		int i,j;
		for(i=1; i<9; i++)cin>>st[i];
//		for(i=0; i<9; i++)st[i]/=3;
		int sv[11],nsv=1<<25;
		memset(sv,0,sizeof sv);
		for(int mask=0;; mask++) {
			int gao[11],now[11];
			memset(gao,0,sizeof gao);
			memcpy(now,st,sizeof st);
			int tp=mask,itp=0,cnt=0;
			while(tp) {
				gao[itp]+=tp%4,cnt+=tp%4;
				tp/=4;
				itp++;
			}
			if(gao[9])break;
			for(i=0; i<9; i++)for(j=0; s[i][j]; j++)
					now[ s[i][j]-'A' ]+=gao[i];
			int ok=1;
			for(i=0; i<9; i++)if(now[i]%4) {ok=0; break;}
			if(ok) {
				if(nsv>cnt) {
					memcpy(sv,gao,sizeof gao);
					nsv=cnt;
				}
			}
		}
		for(i=0; i<9; i++)if(sv[i]) {sv[i]--; printf("%d",i+1); break;}
		for(i=0; i<9; i++)while(sv[i]--)printf(" %d",i+1);
		printf("\n");
	}
	return 0;
}
