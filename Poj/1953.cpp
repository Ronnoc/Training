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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
LL ans[55][2];
int main(){
	int i,j;
	ans[0][0]=0,ans[0][1]=0;
	ans[1][0]=1,ans[1][1]=1;
	for(i=2;i<=45;i++){
		ans[i][0]=ans[i-1][1]+ans[i-1][0];
		ans[i][1]=ans[i-1][0];
	}
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		scanf("%d",&i);
		printf("Scenario #%d:\n",CASE);
		cout<<ans[i][0]+ans[i][1]<<endl<<endl;
	}
	return 0;
}
