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
vector<PII>L;
bool check(int x,int y,int r) {
	for(int i=0; i<L.SZ; i++) {
		int p=L[i].AA;
		int q=L[i].BB;
		if(p<=x||p>=x+r)continue;
		if(q<=y||q>=y+r)continue;
		return 0;
	}
	return 1;
}
int main() {
	int i, j;
//	freopen("cricket.in", "r", stdin);
//	freopen("cricket.out", "w", stdout);
	int n,m,b,x,y;
	while(~scanf("%d%d%d",&b,&m,&n)) {
		vector<int>X,Y;
		L.clear();
		while(b--) {
			scanf("%d%d",&x,&y);
			L.PB(MP(x,y));
			X.PB(x);
			Y.PB(y);
		}
		X.PB(0),Y.PB(0);
		sort(X.OP,X.ED);
		sort(Y.OP,Y.ED);
		X.erase(unique(X.OP,X.ED),X.ED);
		Y.erase(unique(Y.OP,Y.ED),Y.ED);
		int s,t,z;
		s=0,t=0,z=1;
		for(i=0; i<X.SZ; i++)for(j=0; j<Y.SZ; j++) {
				int r=min(m-X[i],n-Y[j]);
				int l=min(r,1);
				while(r>l) {
					if(r-l<=1) {
						if(check(X[i],Y[j],r))l=r;
						break;
					}
					int mid=(l+r)/2;
					if(check(X[i],Y[j],mid))l=mid;
					else r=mid-1;
				}
				//				cout<<X[i]<<" "<<Y[j]<<" "<<g<<endl;
				if(l>z)s=X[i],t=Y[j],z=l;
			}
		printf("%d %d %d\n",s,t,z);
	}
	return 0;
}
/*
4 1 1
0 0
0 1
1 0
1 1
0 1 1
0 2 2
0 3 5
1 1 1
1 0
1 1 1
0 1
*/
