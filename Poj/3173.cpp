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

int A[33][33];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n,S;
	while(~scanf("%d%d",&n,&S)) {
		for(j=1; j<=n; j++)for(i=1; i<=j; i++) {
				A[i][j]=(S++)%10;
				if(S%10==0)S++;
			}
		for(i=1; i<=n; i++) {
			if(i!=1)printf(" ");
			else printf("%d",A[i][i]);
			for(j=2; j<=n; j++) {
				if(j>=i)printf(" %d",A[i][j]);
				else printf("  ");
			}
			printf("\n");
		}
	}
	return 0;
}
