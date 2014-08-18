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

PII X[50005];
int n;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++)
			scanf("%d%d",&X[i].AA,&X[i].BB);
		sort(X,X+n);
		int l=X[0].AA,r=X[0].BB;
		for(i=1;i<n;i++){
			if(X[i].AA<=r){
				cmax(r,X[i].BB);
			}else {
				printf("%d %d\n",l,r);
				l=X[i].AA,r=X[i].BB;
			}
		}
		printf("%d %d\n",l,r);
	}
	return 0;
}
