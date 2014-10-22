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
const int N = 1000000+10;
int p[N], pn;
bool flag[N];	//trueÎªºÏÊý
void init(int n) {
	pn = 0;
	for(int i = 2; i <= n; i++) {
		if(!flag[i])
			p[pn ++ ] = i;
		for(int j = 0; j < pn && i * p[j] <= n; j++) {
			flag[i * p [j]] = true;
			if(i % p[j] == 0)
				break;
		}
	}
}
inline int read() {
	char ch;
	bool flag = false;
	int a = 0;
	while(!((((ch = getchar()) >= '0') && (ch <= '9')) | (ch == '-')));
	if(ch != '-')a = a*10+(ch-'0');
	else flag = true;
	while(((ch = getchar()) >= '0') && (ch <= '9'))
		a = a*10+(ch-'0');
	if(flag) a = -a;
	return a;
}
void write(int a) {
	if(a < 0)
		putchar('-'),a = -a;
	if(a >= 10)
		write(a / 10);
	putchar(a % 10 + '0');
}
vector<int>G[1000005];
int vis[N];
int A[N];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	init(1000000);
	for(i=0; i<pn; i++)
		for(j=p[i]; j<=1000000; j+=p[i])
			G[j].PB(i);
	_T=read();
	while(_T--) {
		int n=read();
		for(i=0; i<n; i++)A[i]=read();
		int ans=-1,le=0;
		for(i=0; i<pn; i++)vis[i]=0;
		for(i=0; i<n; i++) {
			int tot=0;
			for(j=0; j<G[A[i]].SZ; j++) {
				if(vis[G[A[i]][j]])tot++;
				vis[G[A[i]][j]]++;
			}
			while(le<i&&tot) {
				for(j=0; j<G[A[le]].SZ; j++) {
					vis[G[A[le]][j]]--;
					if(vis[G[A[le]][j]])tot--;
				}
				le++;
			}
			cmax(ans,i-le+1);
		}
		if(ans==1)ans=-1;
		write(ans);
		printf("\n");
	}
	return 0;
}
