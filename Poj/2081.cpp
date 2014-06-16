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
int a[500005];
char b[3012505];
int main(){
	int i,j;
	a[0]=0;
	b[0]=1;
	int mx=0;
	for(i=1;i<=500000;i++){
		if(a[i-1]>i&&b[a[i-1]-i]==0)a[i]=a[i-1]-i;
		else a[i]=a[i-1]+i;
		b[a[i]]=1;
	}
	int k;
	while(~scanf("%d",&k)&&k>=0)printf("%d\n",a[k]);
	return 0;
}
