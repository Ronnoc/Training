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
int main(){
	int i,j,n;
	int ans[1010];
	ans[0]=0;
	for(i=1;i<=1000;i++){
		ans[i]=ans[i-1];
		for(j=0;j<i;j++)if(__gcd(i,j)==1)ans[i]+=2;
		if(i==1)ans[i]++;
	}
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		scanf("%d",&n);
		printf("%d %d %d\n",CASE,n,ans[n]);
	}
	return 0;
}
