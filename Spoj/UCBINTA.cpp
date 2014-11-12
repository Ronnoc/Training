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

int A[1005][1005];
int B[1005];
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	int n;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&A[i][j]);
		if(n==2){
			printf("%d %d\n",1,A[1][2]-1);
			continue;
		}
		int *z=A[1];
		B[1]=A[2][3]-z[2]-z[3];
		B[1]=-B[1]/2;
		for(i=2;i<=n;i++)
			B[i]=z[i]-B[1];
		for(i=1;i<=n;i++)
			printf("%d%c",B[i],i==n?'\n':' ');
	}
	return 0;
}
