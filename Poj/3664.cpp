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
const double PI=acos( -1. );
const LL MOD = 1000000007;

vector<pair<PII,int> >L;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,T;
	int n,k,u,v;
	while(~scanf("%d%d",&n,&k)){
		L.clear();
		for(i=0;i<n;i++){
			scanf("%d%d",&u,&v);
			L.PB(MP(MP(-u,-v),i));
		}
		sort(L.OP,L.OP+n);
		for(i=0;i<k;i++)swap(L[i].AA.AA,L[i].AA.BB);
		sort(L.OP,L.OP+k);
		cout<<L[0].BB+1<<endl;
	}
	return 0;
}
