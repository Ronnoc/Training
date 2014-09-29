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
const int MXN = 1000005;
int mu[MXN], p[MXN], pn;
bool flag[MXN];	//trueÎªºÏÊý
void init(int N) {
	pn = 0;
	mu[1] = 1;
	for(int i = 2; i < N; i++) {
		if(!flag[i]) {
			p[pn ++ ] = i;
			mu[i] = -1;						//phi[i]=i-1;
		}
		for(int j = 0; j < pn && i * p[j] < N; j++) {
			flag[i * p [j]] = true;
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;		//phi[i * p[j]] = p[j] * phi[i];
				break;
			} else  mu[i * p[j]] = -mu[i];  //phi[i * p[j]] = (p[j] - 1) * phi[i];
		}
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
	init(1000001);
	while(cin>>n) {
		int got=0;
		for(i=4; i+4<=n; i++)if(flag[i]&&flag[n-i]){
			printf("%d %d\n",i,n-i);
			got=1;
			break;
		}
	}
	return 0;
}
