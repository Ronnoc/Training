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
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T;
	scanf("%d",&T);
	while(T--){
		int a[22];
		for(i=0;i<16;i++)scanf("%d",&a[i]);
		int cnt=0;
		for(i=2;i<=14;i++)for(j=i;j<=14;j++){
			int flag=1;
			for(k=i;k<=j;k++)if(a[k]<=a[i-1]||a[k]<=a[j+1])flag=0;
			cnt+=flag;
		}
		printf("%d %d\n",a[0],cnt);
	}
	return 0;
}
