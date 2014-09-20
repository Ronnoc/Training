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

int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
	while(~scanf("%d",&n)){
		if(n<4){printf("NO\n");continue;}
		printf("YES\n");
		if(n%2==0){
			printf("1 * 2 = 2\n");
			printf("2 * 3 = 6\n");
			printf("6 * 4 = 24\n");
			for(i=5;i<=n;i+=2){
				printf("%d - %d = %d\n",i+1,i,1);
				printf("24 * 1 = 24\n");
			}
		}else {
			printf("1 + 5 = 6\n");
			printf("3 - 2 = 1\n");
			printf("6 * 4 = 24\n");
			printf("24 * 1 = 24\n");
			for(i=6;i<=n;i+=2){
				printf("%d - %d = %d\n",i+1,i,1);
				printf("24 * 1 = 24\n");
			}
		}
	}
	return 0;
}
